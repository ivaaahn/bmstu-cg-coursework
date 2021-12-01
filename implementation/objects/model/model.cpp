//
// Created by ivaaahn on 23.05.2021.
//

#include "model.hpp"
#include <cassert>
#include <iostream>
#include <fstream>
#include <sstream>
#define EPS 1e-5


int TriangularModel::numOfFaces() const {
    return static_cast<int>(this->_faces.size());
}

int TriangularModel::numOfPoints() const {
    return static_cast<int>(this->_points.size());
}

const float3& TriangularModel::getPoint(int point_idx) const {
    assert(point_idx >= 0 && point_idx < this->numOfPoints());
    return this->_points[point_idx];
}

float3& TriangularModel::getPoint(int point_idx) {
    assert(point_idx >= 0 && point_idx < this->numOfPoints());
    return this->_points[point_idx];
}

const Triangle& TriangularModel::getFace(int face_idx) const {
    assert(face_idx >= 0 && face_idx < this->numOfFaces());
    return this->_faces[face_idx];
}

void TriangularModel::getBox(float3& p_min, float3& p_max) {
    p_min = p_max = this->_points[0];

    for (int point_idx = 1; point_idx < this->numOfPoints(); ++point_idx)
    {
        for (int axis_idx = 0; axis_idx < 3; ++axis_idx)
        {
            p_min[axis_idx] = std::min(p_min[axis_idx], this->_points[point_idx][axis_idx]);
            p_max[axis_idx] = std::max(p_max[axis_idx], this->_points[point_idx][axis_idx]);
        }
    }

    std::cerr << "bbox: [ (" << p_min[0] << ", " << p_min[1] << ", " << p_min[2] << ") : (" << p_max[0] << ", "
              << p_max[1] << ", " << p_max[2] << ") ]" << std::endl;
}

bool TriangularModel::rayIntersect(const std::shared_ptr<Ray>& ray, float& distTo1stIntersect, float3& N, float3& hit) const {
    if (!this->_rayBoxIntersect(ray)) return false;

    float faceDist = std::numeric_limits<float>::max();
    float currDist;
    Triangle face;

    for (const auto & currFace : this->_faces)
    {
        if (this->_rayFaceIntersect(ray, currFace, currDist) && currDist < faceDist)
        {
            faceDist = currDist;
            face = currFace;
        }
    }

    if (faceDist == std::numeric_limits<float>::max()) return false;

    N = this->getNormal(face, ray);
    distTo1stIntersect = currDist;
    hit = ray->src + ray->dir * currDist;

    return true;
}

bool TriangularModel::_rayFaceIntersect(const std::shared_ptr<Ray>& ray, const Triangle& face, float& ray_tvalue) const {
//  find vectors for two edges sharing vertex[0]
    float3 edge1 = getPoint(face.verts[1]) - getPoint(face.verts[0]);
    float3 edge2 = getPoint(face.verts[2]) - getPoint(face.verts[0]);

//   begin calc determinant - also used to calc U parameter
    float3 pvec = linalg::cross(ray->dir, edge2);
    float det = linalg::dot(edge1, pvec);

//   ray lies in plane of triangle
    if (det < EPS) return false;

//   calc dist from vertex[0] to ray source
    float3 tvec = ray->src - getPoint(face.verts[0]);

//  calculate bary_u parameter and test bounds
    float bary_u = linalg::dot(tvec, pvec);
    if (bary_u < 0.0 || bary_u > det) return false;

//  bary_v (barycenter)
    float3 qvec = linalg::cross(tvec, edge1);
    float bary_v = linalg::dot(ray->dir, qvec);

    //test bounds
    if (bary_v < 0.0 || bary_u + bary_v > det) return false;

    auto inv_det = 1. / det;

    ray_tvalue = static_cast<float>(linalg::dot(edge2, qvec) * inv_det);

    return ray_tvalue > EPS;
}

float3 TriangularModel::getNormal(const Triangle& face, const std::shared_ptr<Ray>& ray) const {
    float3 edge1 = getPoint(face.verts[1]) - getPoint(face.verts[0]);
    float3 edge2 = getPoint(face.verts[2]) - getPoint(face.verts[0]);

    auto n = linalg::normalize(linalg::cross(edge1, edge2));

    if (linalg::dot(n, ray->dir) < 0)
    {
        n *= -1;
    }

    return n;
}



TriangularModel::TriangularModel(const std::shared_ptr<std::ifstream>& srcFile) {
    std::string line;
    std::ifstream in;

    while (!srcFile->eof()) {
        std::getline(*srcFile, line);
        std::istringstream iss(line);
        std::cout << line << std::endl;
        char trash;
        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            float3 v;
            for (int i = 0; i < 3; i++)
            {
                iss >> v[i];
            }

            this->_points.push_back(v);

        }
        else if (!line.compare(0, 2, "f "))
        {
            int3 f;
            int idx, cnt = 0;
            iss >> trash;
            while (iss >> idx)
            {
                idx--; // in wavefront obj all indices start at 1, not zero
                f[cnt++] = idx;
            }
            if (cnt == 3)
            {
                this->_faces.emplace_back(f);
            }
        }
        else
        {
            break;
        }
    }

    this->_material = Material(srcFile);
    std::cerr << "# v# " << this->_points.size() << " f# "  << this->_faces.size() << std::endl;


    float3 p_min, p_max;
    this->getBox(p_min, p_max);

    this->_box_bounds[0] = p_min;
    this->_box_bounds[1] = p_max;
}

bool TriangularModel::_rayBoxIntersect(const std::shared_ptr<Ray>& r) const {
    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin = (this->_box_bounds[r->sign[0]].x - r->src.x) * r->invdir.x;
    tmax = (this->_box_bounds[1-r->sign[0]].x - r->src.x) * r->invdir.x;
    tymin = (this->_box_bounds[r->sign[1]].y - r->src.y) * r->invdir.y;
    tymax = (this->_box_bounds[1-r->sign[1]].y - r->src.y) * r->invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (this->_box_bounds[r->sign[2]].z - r->src.z) * r->invdir.z;
    tzmax = (this->_box_bounds[1-r->sign[2]].z - r->src.z) * r->invdir.z;

    if ((tmin > tzmax) || (tzmin > tmax))
        return false;
    if (tzmin > tmin)
        tmin = tzmin;
    if (tzmax < tmax)
        tmax = tzmax;

    return true;
}

raw_figure TriangularModel::clFormat() const {
    raw_figure res;

    res.num_of_points = this->numOfPoints();
    res.num_of_faces = this->numOfFaces();

    for (int i = 0; i < this->numOfPoints(); ++i)
    {
        res.points[i].x = this->_points[i].x;
        res.points[i].y = this->_points[i].y;
        res.points[i].z = this->_points[i].z;
    }

    for (int i = 0; i < this->numOfFaces(); ++i)
    {
        res.faces[i].x = this->_faces[i].verts.x;
        res.faces[i].y = this->_faces[i].verts.y;
        res.faces[i].z = this->_faces[i].verts.z;
    }


    for (int i = 0; i < 2; ++i)
    {
        res.box_bounds[0].x = this->_box_bounds[0].x;
        res.box_bounds[0].y = this->_box_bounds[0].y;
        res.box_bounds[0].z = this->_box_bounds[0].z;
    }

    return res;
}



//Sphere::Sphere(const std::shared_ptr<std::ifstream>& srcFile) {
//    this->_loadCenter(srcFile);
//    this->_loadRadius(srcFile);
//    this->_material = Material(srcFile);
//}
//
//void Sphere::_loadRadius(const std::shared_ptr<std::ifstream>& srcFile) {
//    float tempRadius = 0.f;
//
//    if (!(*srcFile >> tempRadius))
//        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
//
//    this->_radius = tempRadius;
//}
//
//void Sphere::_loadCenter(const std::shared_ptr<std::ifstream>& srcFile) {
//    float x, y, z;
//
//    if (!(*srcFile >> x >> y >> z))
//        throw FileFormatError(__FILE__, __LINE__, "invalid model-file format");
//
//    this->_center = float3{x, y, z};
//}







