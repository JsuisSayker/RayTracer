/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Camera
*/

#include "Camera.hpp"

RayTracer::Camera::Camera()
{
    origin = Math::Point3D(-200, -200, 0);
    screen = Rectangle3D(Math::Point3D(0, 0, 0), Math::Vector3D(400, 0, 0), Math::Vector3D(0, 400, 0));
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v) const
{
    return RayTracer::Ray(origin, screen.pointAt(u, v) - origin);
}

RayTracer::Camera::~Camera()
{
}
