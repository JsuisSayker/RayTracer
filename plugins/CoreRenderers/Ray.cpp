/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** RayTracer
*/

#include "Ray.hpp"

RayTracer::Ray::Ray()
{
    _origin = Math::Point3D(0, 0, 0);
    _direction = Math::Vector3D(0, 0, 0);
}

RayTracer::Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction)
{
    this->_origin = origin;
    this->_direction = direction;
    this->_tm = 0;
}

RayTracer::Ray::Ray(const Math::Point3D &origin, const Math::Vector3D &direction, double time)
{
    this->_origin = origin;
    this->_direction = direction;
    this->_tm = time;
}

RayTracer::Ray::~Ray() {}

double RayTracer::Ray::time() const { return _tm; }

Math::Point3D RayTracer::Ray::at(double t) const { return _origin + _direction * t; }