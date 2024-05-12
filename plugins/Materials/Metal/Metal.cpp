/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Metal
*/

#include <Metal.hpp>

Materials::Metal::Metal(const Math::Vector3D &albedo, double fuzz)
    : Materials::Material(), _fuzz(fuzz < 1 ? fuzz : 1)
{
    _albedo = albedo;
}

Materials::Metal::~Metal() {}

bool Materials::Metal::scatter(const RayTracer::Ray &r_in, Materials::Material &rec,
                              Math::Vector3D &attenuation, RayTracer::Ray &scattered) const
{
    Math::Vector3D reflected = reflect(r_in._direction, rec.normal);
    reflected = unit_vector(reflected) + (random_unit_vector() * _fuzz);
    scattered = RayTracer::Ray(rec.p, reflected, r_in.time());
    attenuation = _albedo;

    return (scattered._direction.dot(rec.normal) > 0);
}