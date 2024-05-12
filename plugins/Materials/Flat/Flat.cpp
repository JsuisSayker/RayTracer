/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Flat
*/

#include <Flat.hpp>

Material::Flat::Flat(const Math::Vector3D &albedo) { this->_albedo = albedo; }
Material::Flat::~Flat() {}

bool Material::Flat::scatter(const RayTracer::Ray &r_in, Material &rec, Math::Vector3D &attenuation,
                             RayTracer::Ray &scattered) const
{
    Math::Vector3D scatter_direction = rec.normal + random_unit_vector();

    if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

    scattered = RayTracer::Ray(rec.p, scatter_direction, r_in.time());
    attenuation = _albedo;
    return true;
}