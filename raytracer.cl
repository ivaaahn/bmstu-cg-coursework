#pragma OPENCL EXTENSION cl_khr_fp64 : enable

#define POLYGONAL 0
#define SPHERE 1

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
    float4 albedo;
	float3 diffuse;
	float specularExp;
	float refIdx;
    float ambient;
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
    float3 center;
    float radius;
    int fig_type;
} RawFigure;



float3 refract(const float3 I, float3 N, float eta_t, float eta_i) { // Snell's law
    float cosi = -max(-1.f, min(1.f, dot(I, N)));


    if (cosi < 0)
    { // if the ray is inside the object, swap the indices and invert the normal to get the correct result
        N = -N;
        float tmp = eta_i;
        eta_i = eta_t;
        eta_t = tmp;
        cosi = -max(-1.f, min(1.f, dot(I, N))); // TODO: может оптимизировать можно ? 
    }

    float eta = eta_i / eta_t;
    float k = 1 - eta*eta*(1 - cosi*cosi);
    return k < 0 ? (float3)(1.f, 0.f, 0.f) : I*eta + N*(eta*cosi - sqrt(k));
}

void RayInit(Ray *ray, float3 src, float3 dir)
{
    ray->src = src;
    ray->dir = dir; 
    ray->invdir = 1 / ray->dir;
    ray->sign.x = (ray->invdir.x < 0);
    ray->sign.y = (ray->invdir.y < 0);
    ray->sign.z = (ray->invdir.z < 0);
}


void getRay(Ray *ray, int w, int h, int2 dim, Camera *cam) {
    float dir_x = (w + 0.5) - dim.s0 / 2.;
    float dir_y = -(h + 0.5) + dim.s1 / 2.;
    float dir_z = -dim.s1 / (2. * tan(cam->fov / 2.));

    RayInit(ray, cam->position, normalize((float3)(dir_x, dir_y, dir_z)));

    // float x = (2 * (w + 0.5) / (float)dim.s0 - 1) * tan(cam->fov / 2.) * dim.s0 / (float)dim.s1;
    // float y = -(2 * (h + 0.5) / (float)dim.s1 - 1) * tan(cam->fov / 2.);
    

    // ray->src = cam->position;
    // ray->dir = normalize((float3)(x, y, z)); 
    
    // ray->invdir = 1 / ray->dir;

    // printf("%f %f %f\n", ray->invdir.x, ray->invdir.y, ray->invdir.z);

    // ray->sign.x = (ray->invdir.x < 0);
    // ray->sign.y = (ray->invdir.y < 0);
    // ray->sign.z = (ray->invdir.z < 0);

    // printf("%d %d %d\n", ray->sign.x, ray->sign.y, ray->sign.z);
}

float length2(float3 v) {
	return dot(v, v);
}

float dist2(float3 a, float3 b) {
	return length2(b-a);
}

bool sphereIsIntersect(global const RawFigure *fig, const Ray *ray, float *distTo1stIntersect, float3 *N, float3 *hit) {
	float3 L = fig->center - ray->src;


    float dFromSrcToProjOfCenter = dot(L, ray->dir);
    float distToRaySqr = length2(L) - dFromSrcToProjOfCenter * dFromSrcToProjOfCenter;

    float rad2 = fig->radius * fig->radius;

    if (distToRaySqr > rad2)
    {
        return false;
    }

    float halfChordLength = sqrt(rad2 - distToRaySqr);

    *distTo1stIntersect = dFromSrcToProjOfCenter - halfChordLength;
    float distTo2ndIntersect = dFromSrcToProjOfCenter + halfChordLength;

    if (distTo2ndIntersect < 0) return false;


    if (*distTo1stIntersect < 0)
    {
        *distTo1stIntersect = distTo2ndIntersect;
    }


    *hit = ray->src + ray->dir * *distTo1stIntersect;
    *N = normalize(*hit - fig->center);

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

    if (dot(n, ray->dir) > 0)
    {
        n *= -1;
    }

    return n;
}


bool rayTriangleModelIntersect(global const RawFigure *fig, const Ray *ray, float *distTo1stIntersect, float3 *N, float3 *hit) {
    // if (fig->fig_type == POLYGONAL && !rayBoxIntersect(fig, ray)) return false;

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

#define PLANE_Y 4
#define PLANE_X_BOUNDS 12
#define PLANE_Z_MIN (-30)
#define PLANE_Z_MAX 0

bool sceneIsIntersect(global const RawFigure *fList, const int flLen, const Ray *ray, float3 *hit, float3 *N, Material *mat) {
    float figuresDist = MAXFLOAT;

    float currDist;
    float3 currN, currHit;

    for (int i = 0; i < flLen; ++i)
    {
        if ((fList[i].fig_type == POLYGONAL) && rayTriangleModelIntersect(&fList[i], ray, &currDist, &currN, &currHit) && currDist < figuresDist)
        {
            figuresDist = currDist;
            *hit = currHit;
            *N = currN;
            *mat = fList[i].material;

            continue;
        }

        if (sphereIsIntersect(&fList[i], ray, &currDist, &currN, &currHit) && currDist < figuresDist)
        {
            figuresDist = currDist;
            *hit = currHit;
            *N = currN;
            *mat = fList[i].material;
        }
    }

    float checkerboard_dist = MAXFLOAT;
    if (ray->dir.y > EPS || ray->dir.y < -EPS)
    {
        float d = -(ray->src.y + PLANE_Y) / ray->dir.y; // the checkerboard plane has equation y = -1
        float3 pt = ray->src + ray->dir * d;
        


        if (d > EPS && fabs(pt.x) < PLANE_X_BOUNDS && pt.z < PLANE_Z_MAX && pt.z > PLANE_Z_MIN && d < figuresDist) 
        {
            checkerboard_dist = d;
            *hit = pt;
            *N = (float3)(0, 1, 0);
            mat->diffuse = ((int)(0.5 * pt.x + 1000) + (int)(0.5 * pt.z)) & 1 ? (float3)(0.3, 0.3, 0.3) : (float3)(0.3, 0.2, 0.1);
            mat->albedo = (float4)(0.6,0.3,0.1,0.0);
            mat->specularExp = 2;
            mat->refIdx=1;
            mat->ambient=0.125;
            // printf("mat->diffuse: (%f, %f, %f)", mat->diffuse.x, mat->diffuse.y, mat->diffuse.z);
        }
    }

    return min(figuresDist, checkerboard_dist) < 1000;
}


float3 reflect(const float3 I, const float3 N) {
    return I - N * 2.f * dot(I, N);
}



float3 _getColor(global const RawFigure *fList, int flLen, global const Light *lList, int llLen, const Material *m, float3 hit, const Ray *ray, float3 N, float3 reflect_cf, float3 refract_cf) {
    float DLI = 0, SLI = 0; // diffuse light intensity, specular light intensity
    global const Light *light = 0;

    for (int i = 0; i < llLen; ++i)
    {
        light = lList + i;
        float3 lightDir = normalize((light->position - hit));
        float lightDist = dist2(light->position, hit);

        // checking if the point lies in the shadow of the light
        float3 shadowSrc = dot(lightDir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
        float3 shadowHit, shadowN;

        Ray tmp_ray;
        tmp_ray.src = shadowSrc;
        tmp_ray.dir = lightDir;
        Material tmpMaterial;
        if (sceneIsIntersect(fList, flLen, &tmp_ray, &shadowHit, &shadowN, &tmpMaterial) && dist2(shadowHit, shadowSrc) < lightDist)
            continue;

        DLI += light->intensity * max(0.f, dot(lightDir, N));
        SLI +=  pown(max(0.f, dot(-reflect(-lightDir, N), ray->dir)), m->specularExp) * light->intensity;
    }

    float4 alb = m->albedo;
    
    return m->diffuse*DLI*alb[0] + (float3)(1., 1., 1.)*SLI*alb[1] + reflect_cf*alb[2] + refract_cf*alb[3] + (float3)(1., 1., 1.)*m->ambient;
}



typedef struct _ray_hit_data {
    char idx;
    Ray ray;
    bool hits;
    float3 hit;
    float3 N;
    Material m;
    float3 reflect_cf;
    char depth;
} RayHitData;

#define STACK_LEN 8
#define STACK_MAX STACK_LEN - 1

#define CONSTRAINT 1


float3 getColor(global const RawFigure *fList, int flLen, global const Light *lList, int llLen, Ray *ray, int i, int j) {
    RayHitData stack[STACK_LEN] = {};
    int top = -1;

    RayHitData d;

    char id = 0;

    d.idx = id++;
    d.ray = *ray;
    d.hits = sceneIsIntersect(fList, flLen, &d.ray, &d.hit, &d.N, &d.m);

    float3 curr_color = (float3)(0.1, 0.1, 0.1);

    while (true) 
    {
        while (d.hits)
        {
            d.depth = top < 0 ? 0 : stack[top].depth + 1;
            // printf("(%d, %d): while... stacktop == %d, id == %d, depth == %d\n", i, j, top, d.idx, d.depth);

            stack[++top] = d;
            stack[++top] = d;

            // get left child
            d.ray.dir = normalize(reflect(d.ray.dir, d.N));         
            d.ray.src = dot(d.ray.dir, d.N) < 0 ? (d.hit - d.N * (float)1e-3) : (d.hit + d.N * (float)1e-3);
            d.idx = id++;

           
            d.hits = (stack[top].depth >= CONSTRAINT) ? false : sceneIsIntersect(fList, flLen, &d.ray, &d.hit, &d.N, &d.m);
        }

        if (top == -1) break;

        d = stack[top--];


        if (top != -1 && stack[top].idx == d.idx)
        {
            // printf("(%d, %d): if... stacktop == %d, id == %d, depth == %d\n", i, j, top, d.idx, d.depth);

            stack[top].reflect_cf = curr_color;
            curr_color = (float3)(0.5, 0.5, 0.5);

            // get right child
            d.ray.dir = normalize(refract(d.ray.dir, d.N, d.m.refIdx, 1.f));         
            d.ray.src = dot(d.ray.dir, d.N) < 0 ? (d.hit - d.N * (float)1e-3) : (d.hit + d.N * (float)1e-3);
            d.idx = id++;

            d.hits = (stack[top].depth >= CONSTRAINT) ? false : sceneIsIntersect(fList, flLen, &d.ray, &d.hit, &d.N, &d.m);
        }
        else
        {
            // printf("(%d, %d): else... stacktop == %d, id == %d, depth == %d\n", i, j, top, d.idx, d.depth);
            curr_color = _getColor(fList, flLen, lList, llLen, &d.m, d.hit, &d.ray, d.N, d.reflect_cf, curr_color);
            d.hits = false;
        }
    }

    // printf("(%d, %d) end...\n", i, j);
    return curr_color;
}
// float3 _getColor(global const RawFigure *fList, int flLen, global const Light *lList, int llLen, const Material *m, float3 hit, const Ray *ray, float3 N, float3 reflect_cf, float3 refract_cf) {
// 

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
//             float light_distance = linalg::dist2(light->getPosition(), hit);

//             // checking if the point lies in the shadow of the light
//             float3 shadow_src = dot(light_dir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;
//             float3 shadow_hit, shadow_N;
//             Material tmp_material;
//             if (scene->isIntersect(shadow_src, light_dir, shadow_hit, shadow_N, tmp_material) &&
//                 dist2(shadow_hit, shadow_src) < light_distance)
//                 continue;

//             DLI += light->getIntensity() * std::max(0.f, dot(light_dir, N));

//             auto reflectVec = RaysHandling::reflect(-light_dir, N);

//             SLI += powf(std::max(0.f, linalg::dot(-reflectVec, dir)), mat.getSpecularExp()) *
//                    light->getIntensity();
//         }

//         auto alb = mat.getAlbedo();


//         summary12 += palb2 * (mat.getDiffuse() * DLI * alb[0] + float3(1.) * SLI * alb[1]);
//         palb2 *= alb[2];




//         // offset the original point to avoid occlusion by the object itself
//         dir = normalize(RaysHandling::reflect(dir, N));
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

    // printf("(%d, %d)\n", i, j);

	Camera camera = { (float3)(cam[0].s0, cam[0].s1, cam[0].s2), cam[0].s3 };

    Ray ray;
    getRay(&ray, i, j, dim, &camera);

    // printf("Material: (%f, %f, %f), (%f, %f, %f), %f\n",
    //  figList[0].material.albedo.x, figList[0].material.albedo.y, figList[0].material.albedo.z,
    //  figList[0].material.diffuse.x, figList[0].material.diffuse.y, figList[0].material.diffuse.z,
    //  figList[0].material.specularExp);

    // printf("figList[0].faces[0].s0 = %d\n", figList[0].faces[0].s0);
    // printf("figList[0].faces[0].s1 = %d\n", figList[0].faces[0].s1);
    // printf("figList[0].faces[0].s2 = %d\n\n", figList[0].faces[0].s2);

    // printf("figList[0].faces[1].s0 = %d\n", figList[0].faces[1].s0);
    // printf("figList[0].faces[1].s1 = %d\n", figList[0].faces[2].s1);
    // printf("figList[0].faces[1].s2 = %d\n\n", figList[0].faces[3].s2);


	// Sphere sphere = { (float3)(figList[gid].s0, figList[gid].s1, figList[gid].s2), (float)figList[gid].s3 };

    float3 c = getColor(figList, figListLen, lightList, lightListLen, &ray, i, j);

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