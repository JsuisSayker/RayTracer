/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Sphere
*/

#include "Sphere.hpp"

RayTracer::Sphere::Sphere(const Math::Point3D &center, double radius) : center(center), radius(radius)
{
}

RayTracer::Sphere::~Sphere()
{
}

bool RayTracer::Sphere::hits(const Ray &ray) const
{
    Math::Vector3D oc = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

void RayTracer::Sphere::translate(const Math::Vector3D &translation)
{
    center = center + translation;
}
