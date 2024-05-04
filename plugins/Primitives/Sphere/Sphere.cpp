/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Sphere
*/

#include <Sphere.hpp>

RayTracer::Sphere::Sphere(const Math::Point3D &center, double radius)
{
    this->center = center;
    this->radius = radius;
}

RayTracer::Sphere::~Sphere()
{
}

double RayTracer::Sphere::hits(const Ray &ray) const
{
    Math::Vector3D oc = this->center - ray.origin;
    double a = ray.direction.dot(ray.direction);
    double b = -2.0 * oc.dot(ray.direction);
    double c = oc.length() - (radius * radius);
    double discriminant = (b * b) - (4 * a * c);
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - sqrt(discriminant)) / (2.0 * a);
    }
}

void RayTracer::Sphere::translate(const Math::Vector3D &translation)
{
    center = center + translation;
}

extern "C" std::shared_ptr<RayTracer::APrimitives> entryPoint()
{
    return std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, 0), 1);
}