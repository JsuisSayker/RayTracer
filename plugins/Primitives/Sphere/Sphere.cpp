/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Sphere
*/

#include <Sphere.hpp>
#include <memory>
#include <Material.hpp>
#include <Lambertian.hpp>

RayTracer::Sphere::Sphere(const Math::Point3D &center,
                          double radius,
                          std::shared_ptr<Material::Material> mat)
    : _radius(fmax(0, radius))
{
  _center = center;
  _material = mat;
}

RayTracer::Sphere::~Sphere() {}

bool RayTracer::Sphere::hits(const RayTracer::Ray &ray,
                             Math::Interval ray_t,
                             Material::Material &rec) const
{
  Math::Vector3D oc = _center - ray.origin;
  double a = ray.direction.length_squared();
  double h = ray.direction.dot(oc);
  double c = oc.length_squared() - _radius * _radius;

  double discriminant = h * h - a * c;
  if (discriminant < 0)
    return false;

  double sqrt_discriminant = sqrt(discriminant);

  // Find the nearest root that lies in the acceptable range.
  double root = (h - sqrt_discriminant) / a;
  if (!ray_t.surrounds(root)) {
    root = (h + sqrt_discriminant) / a;
    if (!ray_t.surrounds(root))
      return false;
  }

  rec.t = root;
  rec.p = ray.at(rec.t);
  Math::Vector3D outward_normal = (rec.p - _center) / _radius;
  rec.set_face_normal(ray, outward_normal);
  rec.mat = _material;
  return true;
}

void RayTracer::Sphere::translate(const Math::Vector3D &translation)
{
  _center = _center + translation;
}

extern "C" std::shared_ptr<RayTracer::APrimitives> entryPoint()
{
  std::shared_ptr<Material::Material> material_ground = std::make_shared<Material::Lambertian>(Math::Vector3D(0.8, 0.8, 0.0));
  return std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, 0), 1, material_ground);
}