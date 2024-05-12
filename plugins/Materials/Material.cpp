/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Material
*/

#include "Material.hpp"

Materials::Material::Material() {}

Materials::Material::~Material() {}

bool Materials::Material::scatter(const RayTracer::Ray &r_in, Material &rec,
                                  Math::Vector3D &attenuation, RayTracer::Ray &scattered) const
{
    return false;
}