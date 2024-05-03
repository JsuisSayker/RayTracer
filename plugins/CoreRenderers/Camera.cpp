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
    this->_width = 1920;
    this->_height = 1080;
    this->_fov = 90;
}

RayTracer::Camera::~Camera()
{
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v) const
{
    return RayTracer::Ray(origin, screen.pointAt(u, v) - origin);
}

int RayTracer::Camera::getHeigth()
{
    return this->_height;
}

int RayTracer::Camera::getWidth()
{
    return this->_width;
}

int RayTracer::Camera::getFov()
{
    return this->_fov;
}

void RayTracer::Camera::setFov(int fov)
{
    this->_fov = fov;
}

void RayTracer::Camera::setHeigth(int heigth)
{
    this->_height = heigth;
}

void RayTracer::Camera::setWidth(int width)
{
    this->_width = width;
}
