/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Plane
*/

#include <Plane.hpp>
#include <cstdio>

RayTracer::Plane::Plane(const char axe, double position, std::shared_ptr<Material::Material> mat)
{
    this->_position = position;
    this->_axe = axe;
    this->_material = mat;
}

RayTracer::Plane::~Plane() {}

bool RayTracer::Plane::hits(const RayTracer::Ray &ray, Math::Interval ray_t,
                            Material::Material &rec) const
{
    double t;
    if (_axe == 'X' || _axe == 'x') {
        if (ray.direction.x == 0)
            return false;
        t = (_position - ray.origin._x) / ray.direction.x;
        if (t < 0)
            return false;
    }
    if (_axe == 'Y' || _axe == 'y') {
        if (ray.direction.y == 0)
            return false;
        t = (_position - ray.origin._y) / ray.direction.y;
        if (t < 0)
            return false;
    }
    if (_axe == 'Z' || _axe == 'z') {
        if (ray.direction.z == 0)
            return false;
        t = (_position - ray.origin._z) / ray.direction.z;
        if (t < 0)
            return false;
    }
    rec.t = t;
    rec.p = ray.at(rec.t);
    rec.mat = _material;
    return true;
    return true;
}
