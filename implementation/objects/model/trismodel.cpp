//
// Created by ivaaahn on 23.05.2021.
//

#include "trismodel.hpp"
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

void TriangularModel::_updCorners() {
    auto pmin = this->_box_bounds[0];
    auto pmax = this->_box_bounds[1];

    _corners[0] = pmin;
    _corners[1] = float3{pmin.x, pmin.y, pmax.z};
    _corners[2] = float3{pmin.x, pmax.y, pmin.z};
    _corners[3] = float3{pmax.x, pmin.y, pmin.z};
    _corners[4] = float3{pmin.x, pmax.y, pmax.z};
    _corners[5] = float3{pmax.x, pmin.y, pmax.z};
    _corners[6] = float3{pmax.x, pmax.y, pmin.z};
    _corners[7] = pmax;
}

void TriangularModel::_createBox() {
    auto p_min = float3{1.} * std::numeric_limits<float>::max();
    auto p_max = float3{1.} * std::numeric_limits<float>::min();

    for (const auto& p: this->_points) {
        for (int i = 0; i < 3; ++i) {
            p_min[i] = std::min(p_min[i], p[i]);
            p_max[i] = std::max(p_max[i], p[i]);
        }
    }


//    for (int point_idx = 1; point_idx < this->numOfPoints(); ++point_idx)
//    {
//        for (int axis_idx = 0; axis_idx < 3; ++axis_idx)
//        {
//            p_min[axis_idx] = std::min(p_min[axis_idx], this->_points[point_idx][axis_idx]);
//            p_max[axis_idx] = std::max(p_max[axis_idx], this->_points[point_idx][axis_idx]);
//        }
//    }

    this->_box_bounds[0] = p_min;
    this->_box_bounds[1] = p_max;

    std::cerr << "bbox: [ (" << p_min[0] << ", " << p_min[1] << ", " << p_min[2] << ") : (" << p_max[0] << ", "
              << p_max[1] << ", " << p_max[2] << ") ]" << std::endl;
}

bool TriangularModel::rayIntersect(const std::shared_ptr<Ray>& ray, float& distTo1stIntersect, float3& N,
                                   float3& hit) const {
    if (!this->_rayBoxIntersect(ray)) return false;


    float faceDist = std::numeric_limits<float>::max();
    float currDist;
    Triangle face;

    for (const auto& currFace: this->_faces) {
        if (this->_rayFaceIntersect(ray, currFace, currDist) && currDist < faceDist) {
            faceDist = currDist;
            face = currFace;
        }
    }

    if (faceDist == std::numeric_limits<float>::max()) return false;

    N = this->getN(face, ray);
    distTo1stIntersect = currDist;
    hit = ray->src + ray->dir * currDist;

    return true;
}

bool
TriangularModel::_rayFaceIntersect(const std::shared_ptr<Ray>& ray, const Triangle& face, float& ray_tvalue) const {
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

float3 TriangularModel::getN(const Triangle& face, const std::shared_ptr<Ray>& ray) const {
    float3 edge1 = getPoint(face.verts[1]) - getPoint(face.verts[0]);
    float3 edge2 = getPoint(face.verts[2]) - getPoint(face.verts[0]);

    auto n = linalg::normalize(linalg::cross(edge1, edge2));

    if (linalg::dot(n, ray->dir) < 0) {
        n *= -1;
    }

    return n;
}


TriangularModel::TriangularModel(const std::shared_ptr<std::ifstream>& srcFile) {
    std::string line;
    std::ifstream in;

    auto center = float3 {0.};


    while (!srcFile->eof()) {
        std::getline(*srcFile, line);
        std::istringstream iss(line);
        char trash;
        if (!line.compare(0, 2, "v ")) {
            iss >> trash;
            float3 v;
            for (int i = 0; i < 3; i++) {
                iss >> v[i];
            }

            this->_points.push_back(v);
            center += v;
        }
        else if (!line.compare(0, 2, "f ")) {
            int3 f;
            int idx, cnt = 0;
            iss >> trash;
            while (iss >> idx) {
                idx--; // in wavefront obj all indices start at 1, not zero
                f[cnt++] = idx;
            }
            if (cnt == 3) {
                this->_faces.emplace_back(f);
            }
        }
        else {
            break;
        }
    }

    this->_center = center / this->_points.size();

//    for (int i=0; i<this->numOfFaces(); ++i) {
//        if (this->_faces[i].verts.x < 0) this->_faces[i].verts.x += this->numOfFaces();
//        if (this->_faces[i].verts.y < 0) this->_faces[i].verts.y += this->numOfFaces();
//        if (this->_faces[i].verts.z < 0) this->_faces[i].verts.z += this->numOfFaces();
//    }
//
//    for (int i=0; i<this->numOfPoints(); ++i)
//    {
//        std::cout << this->_points[i].x << std::endl;
//        this->_points[i] *= 5;
//        std::cout << this->_points[i].x << std::endl;
//
//    }


    this->_material = Material(srcFile);
    std::cerr << "# v# " << this->_points.size() << " f# " << this->_faces.size() << std::endl;


//    float3 p_min, p_max;/
    this->_createBox();
    this->_updCorners();

//    this->_box_bounds[0] = p_min;
//    this->_box_bounds[1] = p_max;
}

bool TriangularModel::_rayBoxIntersect(const std::shared_ptr<Ray>& r) const {
    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin = (this->_box_bounds[r->sign[0]].x - r->src.x) * r->invdir.x;
    tmax = (this->_box_bounds[1 - r->sign[0]].x - r->src.x) * r->invdir.x;
    tymin = (this->_box_bounds[r->sign[1]].y - r->src.y) * r->invdir.y;
    tymax = (this->_box_bounds[1 - r->sign[1]].y - r->src.y) * r->invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (this->_box_bounds[r->sign[2]].z - r->src.z) * r->invdir.z;
    tzmax = (this->_box_bounds[1 - r->sign[2]].z - r->src.z) * r->invdir.z;

//    if ((tmin > tzmax) || (tzmin > tmax))
//        return false;
//    if (tzmin > tmin)
//        tmin = tzmin;
//    if (tzmax < tmax)
//        tmax = tzmax;
//
//    return true;
    return ((tmin <= tzmax) && (tzmin <= tmax));
}

raw_figure TriangularModel::clFormat() const {
    raw_figure res;

    res.num_of_points = this->numOfPoints();
    res.num_of_faces = this->numOfFaces();

    for (int i = 0; i < this->numOfPoints(); ++i) {
        res.points[i].x = this->_points[i].x;
        res.points[i].y = this->_points[i].y;
        res.points[i].z = this->_points[i].z;
    }

    for (int i = 0; i < this->numOfFaces(); ++i) {
        res.faces[i].x = this->_faces[i].verts.x;
        res.faces[i].y = this->_faces[i].verts.y;
        res.faces[i].z = this->_faces[i].verts.z;
    }


    for (int i = 0; i < 2; ++i) {
        res.box_bounds[i].x = this->_box_bounds[i].x;
        res.box_bounds[i].y = this->_box_bounds[i].y;
        res.box_bounds[i].z = this->_box_bounds[i].z;
    }

    res.material = this->clMaterial();

    res.center = cl_float3{}; // TODO  а нужен ли центр ?
    res.radius = cl_float{};
    res.fig_type = FigureType::POLYGONAL;

    return res;
}

inline double toRad(const float angle) {
    return angle * (M_PI / 180);
}


void TriangularModel::_rotX(float3& p, float angle) {
    auto _cos = (float)cos(toRad(angle));
    auto _sin = (float)sin(toRad(angle));
    auto _y = p.y;

    p.y = p.y * _cos - p.z * _sin;
    p.z = p.z * _cos + _y * _sin;
}

void TriangularModel::_rotY(float3& p, float angle) {
    auto _cos = (float)cos(toRad(angle));
    auto _sin = (float)sin(toRad(angle));
    auto _x = p.x;

    p.x = p.x * _cos - p.z * _sin;
    p.z = p.z * _cos + _x * _sin;
}

void TriangularModel::_rotZ(float3& p, float angle) {
    auto _cos = (float)cos(toRad(angle));
    auto _sin = (float)sin(toRad(angle));
    auto _x = p.x;

    p.x = p.x * _cos - p.y * _sin;
    p.y = p.y * _cos + _x * _sin;
}

//void TriangularModel::_scale(float3& point, const float3& scale) {
//    point.x *= scale.x;
//    point.y *= scale.y;
//    point.z *= scale.z;
//}

//void TriangularModel::_rot(float3& point, const float3& rotate) {
//    this->_rotX(point, rotate.x);
//    this->_rotY(point, rotate.y);
//    this->_rotZ(point, rotate.z);
//}

//void TriangularModel::transform(const float3& move, const float3& scale, const float3& rotate) {
//    std::cerr << "Move: (" << move.x << ", " << move.y << ", " << move.z << ")" << std::endl;
//    std::cerr << "Scale: (" << scale.x << ", " << scale.y << ", " << scale.z << ")" << std::endl;
//    std::cerr << "Rotate: (" << rotate.x << ", " << rotate.y << ", " << rotate.z << ")" << std::endl;
//
//    auto center = this->getCenter();
//    std::cout << "center = (" << center.x << ' ' << center.y << ' ' << center.z << ')' << std::endl;
//
//#pragma omp parallel for num_threads(8)
//    for (int i = 0; i < this->_points.size(); ++i) {
//        _points[i] -= center;
//
//        this->_rot(_points[i], rotate);
//        this->_scale(_points[i], scale);
//
//        _points[i] += center;
//        _points[i] += move;
//    }
//
//    auto bbox_pmin_new = float3{1.} * std::numeric_limits<float>::max();
//    auto bbox_pmax_new = float3{1.} * std::numeric_limits<float>::min();
//
//    for (auto& point: this->_corners) {
//        point -= center;
//
//        this->_rot(point, rotate);
//        this->_scale(point, scale);
//
//        point += center;
//        point += move;
//
//        for (int i = 0; i < 3; ++i) {
//            bbox_pmin_new[i] = std::min(bbox_pmin_new[i], point[i]);
//            bbox_pmax_new[i] = std::max(bbox_pmax_new[i], point[i]);
//        }
//    }
//
//    this->_box_bounds[0] = bbox_pmin_new;
//    this->_box_bounds[1] = bbox_pmax_new;
//}
//
//float3 TriangularModel::getCenter() const {
//    auto center = float3{0.};
//    for (const auto& p: this->_corners)
//        center += p;
//
//    return center / 8;
//}

void TriangularModel::rotate(const float3& value) {
    auto center = this->getCenter();

    auto p_min = float3{1.} * std::numeric_limits<float>::max();
    auto p_max = float3{1.} * std::numeric_limits<float>::min();


#pragma omp parallel for num_threads(16)
    for (int i = 0; i < this->_points.size(); ++i) {
        this->_points[i] -= center;
        this->_rotX(this->_points[i], value.x);
        this->_rotY(this->_points[i], value.y);
        this->_rotZ(this->_points[i], value.z);
        this->_points[i] += center;

        for (int k = 0; k < 3; ++k) {
            p_min[k] = std::min(p_min[k], this->_points[i][k]);
            p_max[k] = std::max(p_max[k], this->_points[i][k]);
        }
    }

    this->_box_bounds[0] = p_min;
    this->_box_bounds[1] = p_max;
}

void TriangularModel::translate(const float3& value) {
    this->_center += value;

    auto p_min = float3{1.} * std::numeric_limits<float>::max();
    auto p_max = float3{1.} * std::numeric_limits<float>::min();

#pragma omp parallel for num_threads(16)
    for (int i = 0; i < this->_points.size(); ++i) {
        this->_points[i] += value;

        for (int k = 0; k < 3; ++k) {
            p_min[k] = std::min(p_min[k], this->_points[i][k]);
            p_max[k] = std::max(p_max[k], this->_points[i][k]);
        }
    }

    this->_box_bounds[0] = p_min;
    this->_box_bounds[1] = p_max;
}

void TriangularModel::scale(const float3& value) {
    auto center = this->getCenter();

    auto p_min = float3{1.} * std::numeric_limits<float>::max();
    auto p_max = float3{1.} * std::numeric_limits<float>::min();

#pragma omp parallel for num_threads(16)
    for (int i = 0; i < this->_points.size(); ++i) {
        this->_points[i] -= center;

        this->_points[i].x *= value.x;
        this->_points[i].y *= value.y;
        this->_points[i].z *= value.z;

        this->_points[i] += center;

        for (int k = 0; k < 3; ++k) {
            p_min[k] = std::min(p_min[k], this->_points[i][k]);
            p_max[k] = std::max(p_max[k], this->_points[i][k]);
        }
    }

    this->_box_bounds[0] = p_min;
    this->_box_bounds[1] = p_max;
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







