/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Camera
*/

#include <Camera.hpp>

RayTracer::Camera::Camera()
{
    origin = Math::Point3D(0, 0, 0);
    screen = Rectangle3D();
    screen.translate(Math::Vector3D(-0.5, -0.5, -0.5));
}

RayTracer::Camera::~Camera()
{
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v) const
{
    return RayTracer::Ray(origin, screen.pointAt(u, v) - origin);
}
