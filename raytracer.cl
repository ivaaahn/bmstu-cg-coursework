#pragma OPENCL EXTENSION cl_khr_fp64 : enable

// Define C++ Classes as OpenCL structs
typedef struct __attribute__ ((packed)) _cl_tag_Sphere {
    float3 center;
    float radius;
} Sphere;

typedef struct __attribute__ ((packed)) _cl_tag_Ray {
	float3 src;
	float3 dir;
    float3 invdir;
    int3 sign;
} Ray;

typedef struct __attribute__ ((packed)) _cl_tag_Light {
	float3 position;
    float intensity;
} Light;


typedef struct __attribute__ ((packed)) _cl_tag_Camera {
    float3 position;
	float fov;
} Camera;



typedef struct __attribute__ ((packed)) _cl_tag_Material {
    float3 albedo;
	float3 diffuseColor;
	float specularExp;
} Material;

#define NP 5000
#define NF 8000

typedef struct __attribute__ ((packed)) _cl_tag_RawFigure {
    float3 points[NP];
    int3 faces[NF];
    float3 box_bounds[2];
    int num_of_points;
    int num_of_faces;
    Material material;
} RawFigure;



// float3 getReflectionVector(float3 I, float3 N) {
//     return I - N * 2 * dot(I, N);
// }

// Define math functions
// double3 UnitVector(double3 v) {
// 	return v / length(v);
// }

// double SquaredLength(double3 m_dE) {
// 	return m_dE.x * m_dE.x + m_dE.y * m_dE.y + m_dE.z * m_dE.z;
// }

// bool Refract(const double3 v, const double3 n, double NiOverNt, double3 refracted) {
// 	double3 vUV = UnitVector(v);
// 	double dDT = dot(vUV, n);
// 	double dDiscriminant = 1.0 - (NiOverNt * NiOverNt * (1 - dDT * dDT));
// 	if (dDiscriminant > 0) {
// 		refracted = NiOverNt * (vUV - (n * dDT)) - (n * sqrt(dDiscriminant));
// 		return true;
// 	}
// 	else return false;
// }
// double schlick(double cosine, double ref_idx) {
// 	double d0 = (1 - ref_idx) / (1 + ref_idx);
// 	d0 = d0 * d0;
// 	return d0 + (1 - d0)*pow((1 - cosine), 5);
// }

// double3 Color(const Ray *r, sObject *x, Material *m, const int ObjLen, const double3 *rus, uint2 randomid, int depth) {
// 	HitRecord rec;
// 	if (worldHit(x, m, ObjLen, *r, &rec)) {
// 		Ray scattered;
// 		double3 attenuation;
// 		// OpenCL does not support recursive functions, so the ray tracer is limited to primary rays only
// 		if (depth < 1 && scatter(&rec.m_curmat, *r, &rec, &attenuation, &scattered, rus, randomid)) {
// 			return (double3)attenuation; //*Color(&scattered, x, m, ObjLen, rus, randomid, depth + 1);
// 		}
// 		else {
// 			return (double3)(0);
// 		}
// 	}
// 	else {
// 		double t1 = 0.5*(UnitVector(r->b).y + 1.0);
// 		return (1.0 - t1) + (t1 * (double3)(0.5, 0.7, 1.0));
// 	}
// // }
// Ray getRay(double s, double t, int2 dims, Camera cam, const double3 *rud, uint2 randomid) {

// 	double dHalfHeight = tan(cam.Fov*M_PI / 360);
// 	double dHalfWidth = (dims.x / dims.y) * dHalfHeight;
// 	double dFocusDist = length(cam.lookFrom - cam.lookAt);
// 	double3 vW = UnitVector(cam.lookFrom - cam.lookAt);
// 	double3 vU = UnitVector(cross(cam.viewUp, vW));
// 	double3 vV = cross(vW, vU);
// 	double3 vOrigin = cam.lookFrom;
// 	double3 vLowerLeftCorner = vOrigin - (dHalfWidth * dFocusDist * vU) - (dHalfHeight * dFocusDist * vV) - (dFocusDist * vW);
// 	double3 vHorizontal = 2 * dHalfWidth*dFocusDist*vU;
// 	double3 vVertical = 2 * dHalfHeight*dFocusDist*vV;
// 	double3 vRD = (cam.aperture / 2) * (rud[tenrand(randomid)] / 5.234);
// 	double3 vOffset = vU * vRD.x + vV * vRD.y;
// 	return (Ray) { (double3)(vOrigin + vOffset), (double3)(vLowerLeftCorner + (s * vHorizontal) + (t * vVertical) - vOrigin - vOffset) };
// }


void getRay(Ray *ray, int w, int h, int2 dim, Camera *cam) {
    float x = w + 0.5 - dim.s0 / 2.;
    float y = -(h + 0.5) + dim.s1 / 2.;
    float z = -dim.s1 / (2. * tan(cam->fov / 2.));


    // float x = (2 * (w + 0.5) / (float)dim.s0 - 1) * tan(cam->fov / 2.) * dim.s0 / (float)dim.s1;
    // float y = -(2 * (h + 0.5) / (float)dim.s1 - 1) * tan(cam->fov / 2.);

    ray->src = cam->position;
    ray->dir = normalize((float3)(x, y, z)); 
    
    ray->invdir = 1 / ray->dir;

    // printf("%f %f %f\n", ray->invdir.x, ray->invdir.y, ray->invdir.z);

    ray->sign.x = (ray->invdir.x < 0);
    ray->sign.y = (ray->invdir.y < 0);
    ray->sign.z = (ray->invdir.z < 0);

    // printf("%d %d %d\n", ray->sign.x, ray->sign.y, ray->sign.z);
}

float length2(float3 v) {
	return dot(v, v);
}

float distance2(float3 a, float3 b) {
	return length2(b-a);
}

bool sphereIsIntersect(const Sphere *sphere, const Ray *ray, float *distTo1stIntersect) {
	float3 L = sphere->center - ray->src;


    float dFromSrcToProjOfCenter = dot(L, ray->dir);
    float distToRaySqr = length2(L) - dFromSrcToProjOfCenter * dFromSrcToProjOfCenter;

    if (distToRaySqr > sphere->radius * sphere->radius)
    {
        return false;
    }

    float halfChordLength = sqrt(sphere->radius * sphere->radius - distToRaySqr);

    *distTo1stIntersect = dFromSrcToProjOfCenter - halfChordLength;
    float distTo2ndIntersect = dFromSrcToProjOfCenter + halfChordLength;

    if (*distTo1stIntersect < 0)
    {
        *distTo1stIntersect = distTo2ndIntersect;
    }

    if (*distTo1stIntersect < 0)
    {
        return false;
    }

    return true;
}

bool rayBoxIntersect(global const RawFigure *fig, const Ray *r) {
    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin = (fig->box_bounds[r->sign.s0].x - r->src.x) * r->invdir.x;
    tmax = (fig->box_bounds[1-r->sign.s0].x - r->src.x) * r->invdir.x;
    tymin = (fig->box_bounds[r->sign.s1].y - r->src.y) * r->invdir.y;
    tymax = (fig->box_bounds[1-r->sign.s1].y - r->src.y) * r->invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (fig->box_bounds[r->sign.s2].z - r->src.z) * r->invdir.z;
    tzmax = (fig->box_bounds[1-r->sign.s2].z - r->src.z) * r->invdir.z;

    // if ((tmin > tzmax) || (tzmin > tmax))
    //     return false;
    // if (tzmin > tmin)
    //     tmin = tzmin;
    // if (tzmax < tmax)
    //     tmax = tzmax;

    // return true;
    return ((tmin <= tzmax) && (tzmin <= tmax));
}



#define EPS 1e-5

bool rayTriangleFaceIntersect(global const RawFigure *fig, const Ray *ray, const int3 face, float *ray_tvalue) {
//  find vectors for two edges sharing vertex[0]
    float3 edge1 = fig->points[face.s1] - fig->points[face.s0];
    float3 edge2 = fig->points[face.s2] - fig->points[face.s0];

//   begin calc determinant - also used to calc U par`ameter
    float3 pvec = cross(ray->dir, edge2);
    float det = dot(edge1, pvec);

//   ray lies in plane of triangle
    if (det < EPS) return false;

//   calc dist from vertex[0] to ray source
    float3 tvec = ray->src - fig->points[face.s0];

//  calculate bary_u parameter and test bounds
    float bary_u = dot(tvec, pvec);
    if (bary_u < 0.0 || bary_u > det) return false;

//  bary_v (barycenter)
    float3 qvec = cross(tvec, edge1);
    float bary_v = dot(ray->dir, qvec);

    //test bounds
    if (bary_v < 0.0 || bary_u + bary_v > det) return false;

    float inv_det = 1. / det;

    *ray_tvalue = dot(edge2, qvec) * inv_det;

    return *ray_tvalue > EPS;
}

float3 getTriangleNormal(global const RawFigure *fig, const int3 face, const Ray *ray) {
    float3 edge1 = fig->points[face.s1] - fig->points[face.s0];
    float3 edge2 = fig->points[face.s2] - fig->points[face.s0];

    float3 n = normalize(cross(edge1, edge2));

    if (dot(n, ray->dir) < 0)
    {
        n *= -1;
    }

    return n;
}


bool rayTriangleModelIntersect(global const RawFigure *fig, const Ray *ray, float *distTo1stIntersect, float3 *N, float3 *hit) {
    if (!rayBoxIntersect(fig, ray)) return false;

    // printf("rayTriangleModelIntersect() start...\n");
    

    float faceDist = MAXFLOAT;
    float currDist;
   
    int3 face;

    for (int i = 0; i < fig->num_of_faces; ++i)
    {
        if (rayTriangleFaceIntersect(fig, ray, fig->faces[i], &currDist) && currDist < faceDist)
        {
            faceDist = currDist;
            face = fig->faces[i];
        }
    }

    if (faceDist == MAXFLOAT) return false;

    *N = getTriangleNormal(fig, face, ray);
    *distTo1stIntersect = currDist;
    *hit = ray->src + ray->dir * currDist;

    return true;
}



bool sceneIsIntersect(global const RawFigure *fList, const int flLen, const Ray *ray, float3 *hit, float3 *N, Material *mat) {
    // printf("sceneIsIntersect() start...\n");

    float figuresDist = MAXFLOAT;

    float currDist;
    float3 currN, currHit;

    for (int i = 0; i < flLen; ++i)
    {
        // Sphere sphere = { (float3)(figList[i].s0, figList[i].s1, figList[i].s2), (float)figList[i].s3 };


        if (rayTriangleModelIntersect(&fList[i], ray, &currDist, &currN, &currHit) && currDist < figuresDist)
        {
            figuresDist = currDist;
            *hit = currHit;
            *N = currN;
            *mat = fList[i].material;
        }

    }

    float checkerboard_dist = MAXFLOAT;
    if (fabs(ray->dir.y) > EPS)
    {
        float d = -(ray->src.y + 4) / ray->dir.y; // the checkerboard plane has equation y = -4
        float3 pt = ray->src + ray->dir * d;
 
        if (d > EPS && fabs(pt.x) < 10 && pt.z < -10 && pt.z > -30 && d < figuresDist) 
        {
            checkerboard_dist = d;
            *hit = pt;
            *N = (float3)(0, 1, 0);
            mat->diffuseColor = ((int)(0.5 * hit->x + 1000) + (int)(0.5 * hit->z)) & 1 ? (float3)(.3, .3, .3) : (float3)(.3, .2, .1);
            // mat->diffuseColor *= 0.3;
        }
    }

    return min(figuresDist, checkerboard_dist) < 1000;


    // printf("sceneIsIntersect(): [2] figuresDist == %f", figuresDist);

    // return figuresDist < 1000;
}


float3 getReflectionVector(const float3 I, const float3 N) {
    return I - N * 2.f * dot(I, N);
}

float3 getColor(global const RawFigure *fList, int flLen, global const Light *lList, int llLen, Ray *ray, int depth) {
    float3 amount = {0.0, 0.0, 0.0};
    float product = 1.0;
    
    while (true) 
    {
        float3 hit, N;
        Material material;
        Ray tmp_ray;


        if (depth > 3 || !sceneIsIntersect(fList, flLen, ray, &hit, &N, &material)) break;
       

        float DLI = 0, SLI = 0; // diffuse light intensity, specular light intensity
        global const Light *light = 0;

        // Lights
        for (int i = 0; i < llLen; ++i)
        {
            light = lList + i;
            float3 lightDir = normalize((light->position - hit));
            float lightDist = distance2(light->position, hit);

            // checking if the point lies in the shadow of the light
            float3 shadowSrc = dot(lightDir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
            float3 shadowHit, shadowN;

            tmp_ray.src = shadowSrc;
            tmp_ray.dir = lightDir;
            Material tmpMaterial;
            if (sceneIsIntersect(fList, flLen, &tmp_ray, &shadowHit, &shadowN, &tmpMaterial) && distance2(shadowHit, shadowSrc) < lightDist)
                continue;

            DLI += light->intensity * max(0.f, dot(lightDir, N));
            SLI +=  pown(max(0.f, dot(-getReflectionVector(-lightDir, N), ray->dir)), material.specularExp) * light->intensity;
        }

        float3 alb = material.albedo;

        amount += product * (material.diffuseColor * DLI * alb.s0 + (float3)(1., 1., 1.) * SLI * alb.s1);
        product *= alb.s2;

        ray->dir = normalize(getReflectionVector(ray->dir, N));
        ray->src = dot(ray->dir, N) < 0 ? (hit - N * (float)1e-3) : (hit + N * (float)1e-3);
        
        depth++;
    }

    return amount + product*(float3)(0.2, 0.7, 0.8);
}


// float3 RaysHandling::castRay(float3 src, float3 dir, const std::shared_ptr<Scene>& scene, size_t depth) {
//     auto summary12 = float3{0.0};
//     float palb2 = 1.;

//     while (true) {

// //        depth--;

//         float3 hit, N;
//         Material mat;

//         if (depth > 3 || !scene->isIntersect(src, dir, hit, N, mat)) break;

//         float DLI = 0, SLI = 0; // diffuse light intensity, specular light intensity
//         for (auto& light: scene->_lights) {
//             float3 light_dir = normalize((light->getPosition() - hit));
//             float light_distance = linalg::distance2(light->getPosition(), hit);

//             // checking if the point lies in the shadow of the light
//             float3 shadow_src = dot(light_dir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
//             float3 shadow_hit, shadow_N;
//             Material tmp_material;
//             if (scene->isIntersect(shadow_src, light_dir, shadow_hit, shadow_N, tmp_material) &&
//                 distance2(shadow_hit, shadow_src) < light_distance)
//                 continue;

//             DLI += light->getIntensity() * std::max(0.f, dot(light_dir, N));

//             auto reflectVec = RaysHandling::getReflectionVector(-light_dir, N);

//             SLI += powf(std::max(0.f, linalg::dot(-reflectVec, dir)), mat.getSpecularExp()) *
//                    light->getIntensity();
//         }

//         auto alb = mat.getAlbedo();


//         summary12 += palb2 * (mat.getDiffuse() * DLI * alb[0] + float3(1.) * SLI * alb[1]);
//         palb2 *= alb[2];




//         // offset the original point to avoid occlusion by the object itself
//         dir = normalize(RaysHandling::getReflectionVector(dir, N));
//         src = dot(dir, N) < 0 ? (hit - N * (float)1e-3) : (hit + N * (float)1e-3);

//         depth++;
// //        return mat.getDiffuse() * DLI * alb[0]
// //               + float3(1.) * SLI * alb[1]
// //               + alb[2] * RaysHandling::castRay(reflectSrc, reflect_dir, scene, depth + 1);;
//     }

//     return summary12 + palb2*float3{0.2, 0.7, 0.8}; // background color


kernel void Render(global uchar *pixels,
                   global const RawFigure *figList,
                   global const Light *lightList,
                //    global const float8 *materials,
                   global const float4 *cam,
                   global const int2 *dims,
                   global const int *flLen,
                   global const int *llLen) {

    // printf("Render() start...\n");
    
    int gid = get_global_id(0); // Current ray in image
	int2 dim = dims[0]; // Image Dimensions
	int figListLen = flLen[0]; // objects in list
	int lightListLen = llLen[0]; // lights in list
    // printf("L == %d\n\n", lightList[0].intensity);
    // printf("num_of_lights == %d\n", lightListLen);

    // printf("num_of_points == %d", figList[0].num_of_points);
    // printf("num_of_faces == %d", figList[0].num_of_faces);

	int j = floor((double)(gid / dim.x)); // Current Y
	int i = gid - (j * dim.x); // Current X

	Camera camera = { (float3)(cam[0].s0, cam[0].s1, cam[0].s2), cam[0].s3 };

    Ray ray;
    getRay(&ray, i, j, dim, &camera);

    // printf("Material: (%f, %f, %f), (%f, %f, %f), %f\n",
    //  figList[0].material.albedo.x, figList[0].material.albedo.y, figList[0].material.albedo.z,
    //  figList[0].material.diffuseColor.x, figList[0].material.diffuseColor.y, figList[0].material.diffuseColor.z,
    //  figList[0].material.specularExp);

    // printf("figList[0].faces[0].s0 = %d\n", figList[0].faces[0].s0);
    // printf("figList[0].faces[0].s1 = %d\n", figList[0].faces[0].s1);
    // printf("figList[0].faces[0].s2 = %d\n\n", figList[0].faces[0].s2);

    // printf("figList[0].faces[1].s0 = %d\n", figList[0].faces[1].s0);
    // printf("figList[0].faces[1].s1 = %d\n", figList[0].faces[2].s1);
    // printf("figList[0].faces[1].s2 = %d\n\n", figList[0].faces[3].s2);


	// Sphere sphere = { (float3)(figList[gid].s0, figList[gid].s1, figList[gid].s2), (float)figList[gid].s3 };

    float3 c = getColor(figList, figListLen, lightList, lightListLen, &ray, 0);

    float max_ = max(c.s0, max(c.s1, c.s2));
    if (max_ > 1) c *= (1.f / max_);

    c[0] = max(0.f, min(1.f, c.s0));
    c[1] = max(0.f, min(1.f, c.s1));
    c[2] = max(0.f, min(1.f, c.s2));

    c *= 255;

/*
    0123 - 1
    3454 - 2
    6785 - 3
    9101112 - 4 

    x * 3 
*/
    pixels[gid*4-4] = c.s2;
    pixels[gid*4-3] = c.s1;
    pixels[gid*4-2] = c.s0;

	// pixel[gid] = c;


	/*
		gid = 15;
		W = 10 (dim.x)
		H = 5 (dim.y)

		=> j =  floor((double)(gid / dim.x)) = floor(15 / 10) - floor(1.5) == 1;
		=> i = gid - (j * dim.x) = 15 - (1 * 10) = 5;

		i + j * dim.x = 5 + 1 * 10 = 15

	*/
}