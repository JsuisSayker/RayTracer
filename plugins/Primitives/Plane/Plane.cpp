/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Plane
*/

#include <Plane.hpp>
#include <cstdio>

RayTracer::Plane::Plane(double position, const char axe)
{
    this->position = position;
    this->axe = axe;
}

RayTracer::Plane::~Plane()
{
}

bool RayTracer::Plane::hits(const Ray &ray) const
{
    if (axe == 'x') {
        if (ray.direction.x == 0)
            return false;
        double t = (position - ray.origin.x) / ray.direction.x;
        if (t < 0)
            return false;
        return true;
    }
    if (axe == 'y') {
        if (ray.direction.y == 0)
            return false;
        double t = (position - ray.origin.y) / ray.direction.y;
        if (t < 0)
            return false;
        return true;
    }
    if (axe == 'z') {
        if (ray.direction.z == 0)
            return false;
        double t = (position - ray.origin.z) / ray.direction.z;
        if (t < 0)
            return false;
        return true;
    }
    return false;
}
