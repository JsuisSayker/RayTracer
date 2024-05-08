/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Metal
*/

#include "Metal.hpp"

Material::Metal::Metal(const Math::Vector3D &albedo)
    : IMaterial(), Material::Material(), albedo(albedo)
{
}

Material::Metal::~Metal() {}

bool Material::Metal::scatter(const RayTracer::Ray &r_in,
                              const PrimitivesRecord &rec,
                              Math::Vector3D &attenuation,
                              RayTracer::Ray &scattered) const
{
  Math::Vector3D reflected = reflect(r_in.direction, rec.normal);
  scattered = RayTracer::Ray(rec.p, reflected);
  attenuation = albedo;
  return true;
}