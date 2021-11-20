#pragma OPENCL EXTENSION cl_khr_fp64 : enable

// Define C++ Classes as OpenCL structs
typedef struct _cl_tag_Sphere {
    float3 center;
    float radius;
} Sphere;

typedef struct _cl_tag_Ray {
	float3 src;
	float3 dir;
} Ray;

typedef struct _cl_tag_Camera {
    float3 position;
	float fov;
} Camera;

// typedef struct _cl_tag_Material {
//     float3 albedo;
// 	float3 diffuseColor;
// 	float3 specularExp;
// } Material;


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
    float x = (2 * (w + 0.5) / (float)dim.s0 - 1) * tan(cam->fov / 2.) * dim.s0 / (float)dim.s1;
    float y = -(2 * (h + 0.5) / (float)dim.s1 - 1) * tan(cam->fov / 2.);

    ray->src = cam->position;
    ray->dir = normalize((float3)(x, y, -1.0));
}

float length2(float3 v) {
	return dot(v, v);
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


bool sceneIsIntersect(global const float4 *figList, const int listLen, const Ray *ray) {
    float figuresDist = MAXFLOAT;

    for (int i = 0; i < listLen; ++i)
    {
        float currDist;
        Sphere sphere = { (float3)(figList[i].s0, figList[i].s1, figList[i].s2), (float)figList[i].s3 };

        if (sphereIsIntersect(&sphere, ray, &currDist) && currDist < figuresDist)
        {
            figuresDist = currDist;
            // hit = ray->src + ray->dir * currDist;
        }

    }

    return figuresDist < 1000;

}


float3 getColor(global const float4 *figList, const int figlistLen, const Ray *ray) {
	float sphereDist = MAXFLOAT;

	if (!sceneIsIntersect(figList, figlistLen, ray))
    {
        // printf("NOT INTERSECT");
		return (float3)(0.2, 0.7, 0.8); // BG color
    }


    // printf("INTERSECT\n");
    
    return (float3)(0.4, 0.4, 0.3);
}

kernel void Render(global uchar *pixels,
                   global const float4 *figList,
                   global const float8 *materials,
                   global const float4 *cam,
                   global const int2 *dims,
                   global const int *listLen) {

    int gid = get_global_id(0); // Current ray in image
	int2 dim = dims[0]; // Image Dimensions
	int figListLen = listLen[0]; // objects in list

	int j = floor((double)(gid / dim.x)); // Current Y
	int i = gid - (j * dim.x); // Current X

	Camera camera = { (float3)(cam[0].s0, cam[0].s1, cam[0].s2), cam[0].s3 };

    Ray ray;
    getRay(&ray, i, j, dim, &camera);



	// Sphere sphere = { (float3)(figList[gid].s0, figList[gid].s1, figList[gid].s2), (float)figList[gid].s3 };

    float3 c = getColor(figList, figListLen, &ray);

    float max_ = max(c.s0, max(c.s1, c.s2));
    if (max_ > 1)
    {
        c *= (1.f / max_);
    }

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