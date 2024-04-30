/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** RayTracer
*/

#include "RayTracer.hpp"

RayTracer::Ray::Ray() : origin(), direction()
{
}

RayTracer::Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction) : origin(origin), direction(direction)
{
}

RayTracer::Ray::~Ray()
{
}
