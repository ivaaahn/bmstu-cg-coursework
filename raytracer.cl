#pragma OPENCL EXTENSION cl_khr_fp64 : enable

#define POLYGONAL 0
#define SPHERE 1


#define EPS 1e-5


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
    int2 angles;
	int fov;
} Camera;


typedef struct __attribute__ ((packed)) _cl_tag_Material {
    float4 albedo;
	float3 diffuse;
	float specularExp;
	float refIdx;
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



float3 refract(float3 I, float3 N, float eta_t, float eta_i) { // Snell's law
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
    return k < 0 ? (float3)(1, 0, 0) : I*eta + N*(eta*cosi - sqrt(k));
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

float toRad(const float angle) {
    return angle * (M_PI / 180);
}

void rotateY(float3 *p, float angle) {
    float cos_y = cos(toRad(angle));
    float sin_y = sin(toRad(angle));

    float tmp_x = p->x;

    p->x = p->x * cos_y - p->z * sin_y;
    p->z = p->z * cos_y + tmp_x * sin_y;
}


void rotateX(float3 *p, float angle) {
    float cos_x = cos(toRad(angle));
    float sin_x = sin(toRad(angle));
    float tmp_y = p->y;

    p->y = p->y * cos_x - p->z * sin_x;
    p->z = p->z * cos_x + tmp_y * sin_x;
}

void getRay(Ray *ray, int w, int h, int2 dim, global const Camera *cam) {
    float base_x = (w + 0.5) - dim.s0 / 2.;
    float base_y =  -((h + 0.5) - dim.s1 / 2.);
    float base_z = -dim.s1 / (2. * tan(toRad(cam->fov) / 2.));

    float3 p = (float3)(base_x, base_y, base_z);

    if (cam->angles.x) rotateX(&p, cam->angles.x);
    if (cam->angles.y) rotateY(&p, cam->angles.y);

    RayInit(ray, cam->position, normalize(p));
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

    if (distToRaySqr > rad2) return false;

    float halfChordLength = sqrt(rad2 - distToRaySqr);

    *distTo1stIntersect = dFromSrcToProjOfCenter - halfChordLength;
    float distTo2ndIntersect = dFromSrcToProjOfCenter + halfChordLength;

    if (distTo2ndIntersect < EPS) return false;


    if (*distTo1stIntersect < EPS)
    {
        *distTo1stIntersect = distTo2ndIntersect;
    }


    *hit = ray->src + ray->dir * *distTo1stIntersect;
    *N = normalize(*hit - fig->center);

    return true;
}

bool rayBoxIntersect(global const RawFigure *fig, const Ray *r) {
    float tmin, tmax, tymin, tymax, tzmin, tzmax;

    tmin = (fig->box_bounds[r->sign.x].x - r->src.x) * r->invdir.x;
    tmax = (fig->box_bounds[1-r->sign.x].x - r->src.x) * r->invdir.x;

    tymin = (fig->box_bounds[r->sign.y].y - r->src.y) * r->invdir.y;
    tymax = (fig->box_bounds[1-r->sign.y].y - r->src.y) * r->invdir.y;

    if ((tmin > tymax) || (tymin > tmax))
        return false;
    if (tymin > tmin)
        tmin = tymin;
    if (tymax < tmax)
        tmax = tymax;

    tzmin = (fig->box_bounds[r->sign.z].z - r->src.z) * r->invdir.z;
    tzmax = (fig->box_bounds[1-r->sign.z].z - r->src.z) * r->invdir.z;

    // if ((tmin > tzmax) || (tzmin > tmax))
    //     return false;
    // if (tzmin > tmin)
    //     tmin = tzmin;
    // if (tzmax < tmax)
    //     tmax = tzmax;

    // return true;
    return ((tmin <= tzmax) && (tzmin <= tmax));
}




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
    if (!rayBoxIntersect(fig, ray)) return false;

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

    bool has_intersected;
    for (int i = 0; i < flLen; ++i)
    {

        if (fList[i].fig_type == POLYGONAL) {
            has_intersected = rayTriangleModelIntersect(&fList[i], ray, &currDist, &currN, &currHit);
        }
        else {
            has_intersected = sphereIsIntersect(&fList[i], ray, &currDist, &currN, &currHit);
        }


        if (has_intersected && currDist < figuresDist) {
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
            mat->albedo = (float4)(0.2,0.5,0.3,0.0);
            mat->specularExp = 2;
            mat->refIdx=1;
        }
    }

    return min(figuresDist, checkerboard_dist) < 1000;
}


float3 reflect(const float3 I, const float3 N) {
    return I - N * 2.f * dot(I, N);
}



float3 _getColor(global const RawFigure *fList, int flLen, global const Light *lList, int llLen, const Material *m, float3 hit, const Ray *ray, float3 N, float3 reflect_cf, float3 refract_cf, float sceneAmbientLight) {
    float DLI = 0, SLI = 0; // diffuse light intensity, specular light intensity
    global const Light *light = 0;

    for (int i = 0; i < llLen; ++i)
    {
        light = lList + i;
        float3 lightDir = normalize((light->position - hit));
        float lightDist = dist2(light->position, hit);

        // checking if the point lies in the shadow of the light
        float3 shadowSrc = dot(lightDir, N) < 0 ? hit - N * (float)1e-3 : hit + N * (float)1e-3;

        float curr_dli = light->intensity * max(0.f, dot(lightDir, N));
        float curr_sli = pown(max(0.f, dot(-reflect(-lightDir, N), ray->dir)), m->specularExp) * light->intensity;

        Ray shadowRay;
        RayInit(&shadowRay, shadowSrc, lightDir);

        Material shadowMaterial;
        float3 shadowHit, shadowN;
        if (sceneIsIntersect(fList, flLen, &shadowRay, &shadowHit, &shadowN, &shadowMaterial) && dist2(shadowHit, shadowSrc) < lightDist) {
            curr_dli *= shadowMaterial.albedo[3];
            curr_sli *= shadowMaterial.albedo[3];
        }

        DLI += curr_dli;
        SLI += curr_sli;
    }

    float4 alb = m->albedo;
    
    return (float3)(sceneAmbientLight, sceneAmbientLight, sceneAmbientLight)*alb[0] + m->diffuse*DLI*alb[1] + (float3)(1., 1., 1.)*SLI*alb[2] + reflect_cf*alb[2] + refract_cf*alb[3];
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

#define STACK_LEN 16
#define STACK_MAX STACK_LEN - 1

#define COLOR_R 60.
#define COLOR_G 41.
#define COLOR_B 105.

float3 getColor(global const RawFigure *fList, int flLen, global const Light *lList, int llLen, Ray *ray, float sceneAmbientLight, int rayTreeHeightMax) {
    RayHitData stack[STACK_LEN] = {};
    int top = -1;

    RayHitData d;

    char id = 0;

    d.idx = id++;
    d.ray = *ray;
    d.hits = sceneIsIntersect(fList, flLen, &d.ray, &d.hit, &d.N, &d.m);

    float3 curr_color = (float3)(COLOR_R/255., COLOR_G/255., COLOR_B/255.) * sceneAmbientLight;

    while (true) 
    {
        while (d.hits)
        {
            d.depth = top < 0 ? 0 : stack[top].depth + 1;

            stack[++top] = d;
            stack[++top] = d;

            // get left child
            float3 new_dir = normalize(reflect(d.ray.dir, d.N));
            float3 new_src =  dot(new_dir, d.N) < 0 ? (d.hit - d.N * (float)1e-3) : (d.hit + d.N * (float)1e-3);
            RayInit(&d.ray, new_src, new_dir);
            d.idx = id++;
          
            d.hits = (stack[top].depth >= rayTreeHeightMax) ? false : sceneIsIntersect(fList, flLen, &d.ray, &d.hit, &d.N, &d.m);
        }

        if (top == -1) break;

        d = stack[top--];


        if (top != -1 && stack[top].idx == d.idx)
        {
            stack[top].reflect_cf = curr_color;
            curr_color = (float3)(COLOR_R/255., COLOR_G/255., COLOR_B/255.) * sceneAmbientLight;

            // get right child
            float3 new_dir = normalize(refract(d.ray.dir, d.N, d.m.refIdx, 1.f));
            float3 new_src = dot(new_src, d.N) < 0 ? (d.hit - d.N * (float)1e-3) : (d.hit + d.N * (float)1e-3);
            RayInit(&d.ray, new_src, new_dir);
            d.idx = id++;

            d.hits = (stack[top].depth >= rayTreeHeightMax) ? false : sceneIsIntersect(fList, flLen, &d.ray, &d.hit, &d.N, &d.m);
        }
        else
        {
            curr_color = _getColor(fList, flLen, lList, llLen, &d.m, d.hit, &d.ray, d.N, d.reflect_cf, curr_color, sceneAmbientLight);
            d.hits = false;
        }
    }

    return curr_color;
}


kernel void Render(global uchar *pixels,
                   global const RawFigure *figList,
                   global const Light *lightList,
                   global const Camera *cam,
                   global const int2 *dims,
                   global const int *flLen,
                   global const int *llLen,
                   global const float *sceneAmbientLightArr,
                   global const int *rayTreeHeightArr) {


    int gid = get_global_id(0); // Current ray in image
	int2 dim = dims[0]; // Image Dimensions
	int figListLen = flLen[0]; // objects in list
	int lightListLen = llLen[0]; // lights in list
    float sceneAmbientLight = sceneAmbientLightArr[0];
    int rayTreeHeight = rayTreeHeightArr[0];

	int j = floor((double)(gid / dim.x)); // Current Y
	int i = gid - (j * dim.x); // Current X

    Ray ray;
    getRay(&ray, i, j, dim, cam);

    float3 c = getColor(figList, figListLen, lightList, lightListLen, &ray, sceneAmbientLight, rayTreeHeight);

    float max_ = max(c.s0, max(c.s1, c.s2));
    if (max_ > 1) c *= (1.f / max_);

    c[0] = max(0.f, min(1.f, c.s0)) * 255;
    c[1] = max(0.f, min(1.f, c.s1)) * 255;
    c[2] = max(0.f, min(1.f, c.s2)) * 255;

    int coords = gid*4-4;

    pixels[coords] = c.s2;
    pixels[coords+1] = c.s1;
    pixels[coords+2] = c.s0;
}