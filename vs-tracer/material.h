#ifndef MATERIAL_H_
#define MATERIAL_H_

#include <vector_functions.hpp>
#include "ray.h"
#include "pdf.h"
#include "sphere.h"
#include "utils.h"

enum materialType 
{
	LAMBERTIAN,
	METAL,
	DIELECTRIC,
	DIFFUSE_LIGHT
};

struct scatter_record
{
	ray scattered;
	bool is_specular;
	float3 attenuation;
	//pdf *pdf_ptr;
};

struct material 
{
	materialType type;
	float3 albedo;
	float3 _emitted;
	float param;

	material() {}
	__device__ material(const material &m) :type(m.type), albedo(m.albedo), _emitted(m._emitted), param(m.param) {}
	__device__ bool scatter(const float3& r_dir, const hit_record& rec, const sphere* light_shape, seed_t seed, scatter_record& srec) const;
	__device__ float scattering_pdf(const float3& r_dir, const hit_record& rec, const ray& scattered) const;
	float3 emitted(const ray& r_in, const hit_record& rec, const float3 &p) const;
};

material* make_lambertian(const float3& a);
material* make_metal(const float3& albedo, float fuzz);
material* make_dielectric(float ref_idx);
material* make_diffuse_light(const float3& e);

__device__ bool scatter_lambertian(const material* mat, const float3& r_dir, const hit_record& hrec, const sphere* light_shape, seed_t seed, scatter_record& srec);

#endif /* MATERIAL_H_ */
