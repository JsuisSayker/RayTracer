/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Material
*/

#include "Material.hpp"

Material::Material::Material() {}

Material::Material::~Material() {}

bool Material::Material::scatter(const RayTracer::Ray &r_in,
                                 const PrimitivesRecord &rec,
                                 Math::Vector3D &attenuation,
                                 RayTracer::Ray &scattered) const
{
  return false;
}