/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Metal
*/

#include <Metal.hpp>

Material::Metal::Metal(const Math::Vector3D &albedo, double fuzz)
    : Material::Material(), _fuzz(fuzz < 1 ? fuzz : 1)
{
  _albedo = albedo;
}

Material::Metal::~Metal() {}

bool Material::Metal::scatter(const RayTracer::Ray &r_in,
                              Material &rec,
                              Math::Vector3D &attenuation,
                              RayTracer::Ray &scattered) const
{
  Math::Vector3D reflected = reflect(r_in.direction, rec.normal);
  reflected = unit_vector(reflected) + (random_unit_vector() * _fuzz);
  scattered = RayTracer::Ray(rec.p, reflected);
  attenuation = _albedo;
  return (scattered.direction.dot(rec.normal) > 0);
}