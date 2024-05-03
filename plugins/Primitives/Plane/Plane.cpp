/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Plane
*/

#include <Plane.hpp>

RayTracer::Plane::Plane(const Math::Point3D &position, const Math::Vector3D &normal)
{
    this->position = position;
    this->normal = normal;
}

RayTracer::Plane::~Plane()
{
}

bool RayTracer::Plane::hits(const Ray &ray) const
{
    double denominator = normal.dot(ray.direction);
    if (denominator > 1e-6) {
        Math::Vector3D oc = position - ray.origin;
        double t = oc.dot(normal) / denominator;
        return (t >= 0);
    }
    return false;
}

void RayTracer::Plane::translate(const Math::Vector3D &translation)
{
    position = position + translation;
}