/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Flat
*/

#include <Flat.hpp>

Materials::Flat::Flat(const Math::Vector3D &albedo) { this->_albedo = albedo; }
Materials::Flat::~Flat() {}

bool Materials::Flat::scatter(const RayTracer::Ray &r_in, Materials::Material &rec,
                                   Math::Vector3D &attenuation, RayTracer::Ray &scattered) const
{
    Math::Vector3D scatter_direction = rec.normal + random_unit_vector();

    if (scatter_direction.near_zero())
        scatter_direction = rec.normal;

    scattered = RayTracer::Ray(rec.p, scatter_direction, r_in.time());
    attenuation = _albedo;
    return true;
}