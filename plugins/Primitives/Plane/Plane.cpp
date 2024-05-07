/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Plane
*/

#include <Plane.hpp>
#include <cstdio>

RayTracer::Plane::Plane(const char axe, double position)
{
    this->position = position;
    this->axe = axe;
}

RayTracer::Plane::~Plane()
{
}

bool RayTracer::Plane::hits(const RayTracer::Ray &ray, double ray_tmin,
           double ray_tmax, RayTracer::Primitives_record &rec) const
{
    if (axe == 'X' || axe == 'x') {
        if (ray.direction.x == 0)
            return -1;
        double t = (position - ray.origin.x) / ray.direction.x;
        if (t < 0)
            return -1;
        return t;
    }
    if (axe == 'Y' || axe == 'y') {
        if (ray.direction.y == 0)
            return -1;
        double t = (position - ray.origin.y) / ray.direction.y;
        if (t < 0)
            return -1;
        return t;
    }
    if (axe == 'Z' || axe == 'z') {
        if (ray.direction.z == 0)
            return -1;
        double t = (position - ray.origin.z) / ray.direction.z;
        if (t < 0)
            return -1;
        return t;
    }
    return -1;
}
