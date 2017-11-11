#ifndef UTILS_H_
#define UTILS_H_

#define M_PI       3.14159265358979323846   // pi
#define M_PI_2     1.57079632679489661923   // pi/2
//#define M_PI_4     0.785398163397448309616  // pi/4

#include <vector_functions.h>
#include <helper_math.h>

//#include <curand.h>
#include <curand_kernel.h>

#define seed_t curandStatePhilox4_32_10_t*

// Compute a pseudorandom integer.
// Output value in range [0, 32767]
float drand48(void);
__device__ float cu_drand48(seed_t seed);
__device__ float3 random_cosine_direction(seed_t seed);
__device__ float3 random_to_sphere(seed_t seed);
__device__ float3 random_to_sphere(seed_t seed, float radius, float distance_squared);
__device__ bool refract(const float3& v, const float3& n, float ni_over_nt, float3& refracted);
__device__ float schlick(float cosine, float ref_idx);
float3 random_in_unit_disk();
float3 hex2float3(const int hexval);
__device__ float squared_length(const float3& v);

#endif /* UTILS_H_ */
