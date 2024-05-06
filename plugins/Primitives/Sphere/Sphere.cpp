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

double RayTracer::Sphere::hits(const RayTracer::Ray &r, double ray_tmin,
        double ray_tmax, RayTracer::Primitives_record &rec) const
{
    Math::Vector3D oc = center - r.origin;
    double a = r.direction.length_squared();
    double h = r.direction.dot(oc);
    double c = oc.length_squared() - radius * radius;

    double discriminant = h * h - a * c;
    if (discriminant < 0)
      return false;

    double sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    double root = (h - sqrtd) / a;
    if (root <= ray_tmin || ray_tmax <= root) {
      root = (h + sqrtd) / a;
      if (root <= ray_tmin || ray_tmax <= root)
        return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    Math::Vector3D outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    return true;
}

void RayTracer::Sphere::translate(const Math::Vector3D &translation)
{
    center = center + translation;
}

extern "C" std::shared_ptr<RayTracer::APrimitives> entryPoint()
{
    return std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, 0), 1);
}