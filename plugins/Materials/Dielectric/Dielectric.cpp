/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Dielectric
*/

#include "Dielectric.hpp"

Material::Dielectric::Dielectric(double refraction_index)
    : _refraction_index(refraction_index)
{
}

Material::Dielectric::~Dielectric() {}

static double reflectance(double cosine, double refraction_index)
{
  // Use Schlick's approximation for reflectance.
  auto r0 = (1 - refraction_index) / (1 + refraction_index);
  r0 = r0 * r0;
  return r0 + (1 - r0) * pow((1 - cosine), 5);
}

bool Material::Dielectric::scatter(const RayTracer::Ray &r_in,
                                   Material &rec,
                                   Math::Vector3D &attenuation,
                                   RayTracer::Ray &scattered) const
{
  attenuation = Math::Vector3D(1.0, 1.0, 1.0);
  double ri = rec.front_face ? (1.0 / _refraction_index) : _refraction_index;

  Math::Vector3D unit_direction = unit_vector(r_in._direction);
  double cos_theta = fmin(-unit_direction.dot(rec.normal), 1.0);
  double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

  bool cannot_refract = ri * sin_theta > 1.0;
  Math::Vector3D direction;

  if (cannot_refract || reflectance(cos_theta, ri) > random_double())
    direction = reflect(unit_direction, rec.normal);
  else
    direction = refract(unit_direction, rec.normal, ri);

  scattered = RayTracer::Ray(rec.p, direction, r_in.time());
  return true;
}