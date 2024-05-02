/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** RayTracer
*/

#include "RayTracer.hpp"

RayTracer::Ray::Ray()
{
    origin = Math::Point3D(0, 0, 0);
    direction = Math::Vector3D(0, 0, 0);
}

RayTracer::Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction)
{
    this->origin = origin;
    this->direction = direction;
}

RayTracer::Ray::~Ray()
{
}
