/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Sphere
*/

#include <Lambertian.hpp>
#include <Material.hpp>
#include <Sphere.hpp>
#include <memory>

RayTracer::Sphere::Sphere(const Math::Point3D &center,
                          double radius,
                          std::shared_ptr<Material::Material> mat)
    : _radius(fmax(0, radius)), _is_moving(false)
{
  _center = center;
  _material = mat;
  Math::Vector3D rvec = Math::Vector3D(radius, radius, radius);
  _bbox = RayTracer::Aabb(center - rvec, center + rvec);
}

RayTracer::Sphere::Sphere(const Math::Point3D &center1,
                          const Math::Point3D &center2,
                          double radius,
                          std::shared_ptr<Material::Material> mat)
    : _radius(fmax(0, radius)), _is_moving(true)
{
  _center = center1;
  _material = mat;
  _center_vec = center2 - center1;

  Math::Vector3D rvec = Math::Vector3D(radius, radius, radius);
  RayTracer::Aabb aabb1 = RayTracer::Aabb(center1 - rvec, center1 + rvec);
  RayTracer::Aabb aabb2 = RayTracer::Aabb(center2 - rvec, center2 + rvec);
  _bbox = RayTracer::Aabb(aabb1, aabb2);
}

RayTracer::Sphere::~Sphere() {}

bool RayTracer::Sphere::hits(const RayTracer::Ray &ray,
                             Math::Interval ray_t,
                             Material::Material &rec) const
{
  Math::Point3D center = _is_moving ? sphere_center(ray.time()) : _center;
  Math::Vector3D oc = center - ray._origin;
  double a = ray._direction.length_squared();
  double h = ray._direction.dot(oc);
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
  Math::Vector3D outward_normal = (rec.p - center) / _radius;
  rec.set_face_normal(ray, outward_normal);
  rec.mat = _material;
  return true;
}

void RayTracer::Sphere::translate(const Math::Vector3D &translation)
{
  _center = _center + translation;
}

Math::Point3D RayTracer::Sphere::sphere_center(double time) const
{
  // Linearly interpolate from center1 to center2 according to time, where t=0
  // yields center1, and t=1 yields center2.
  return _center + _center_vec * time;
}

RayTracer::Aabb RayTracer::Sphere::bounding_box() const { return _bbox; }

extern "C" std::shared_ptr<RayTracer::APrimitives> entryPoint()
{
  std::shared_ptr<Material::Material> material_ground =
      std::make_shared<Material::Lambertian>(Math::Vector3D(0.8, 0.8, 0.0));
  return std::make_shared<RayTracer::Sphere>(
      Math::Point3D(0, 0, 0), 1, material_ground);
}