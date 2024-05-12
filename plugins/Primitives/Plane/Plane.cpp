/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Plane
*/

#include <Plane.hpp>
#include <cstdio>

RayTracer::Plane::Plane(const char axe, double position, std::shared_ptr<Materials::Material> mat)
{
    this->_position = position;
    this->_axe = axe;
    this->_material = mat;
}

RayTracer::Plane::~Plane() {}

bool RayTracer::Plane::hits(const RayTracer::Ray &ray, Math::Interval ray_t,
                            Materials::Material &rec) const
{
    double t;
    if (_axe == 'X' || _axe == 'x') {
        if (ray._direction.x == 0)
            return false;
        t = (_position - ray._origin._x) / ray._direction.x;
        if (t < 0)
            return false;
    }
    if (_axe == 'Y' || _axe == 'y') {
        if (ray._direction.y == 0)
            return false;
        t = (_position - ray._origin._y) / ray._direction.y;
        if (t < 0)
            return false;
    }
    if (_axe == 'Z' || _axe == 'z') {
        if (ray._direction.z == 0)
            return false;
        t = (_position - ray._origin._z) / ray._direction.z;
        if (t < 0)
            return false;
    }
    rec.t = t;
    rec.p = ray.at(rec.t);
    rec.mat = _material;
    return true;
    return true;
}
