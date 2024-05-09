/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Cylinder
*/

#include <Cylinder.hpp>

RayTracer::Cylinder::Cylinder(const Math::Point3D &center,
                              double radius,
                              double height,
                              const char axe)
{
  this->center = center;
  this->radius = radius;
  this->height = height;
  this->axe = axe;
}

RayTracer::Cylinder::Cylinder(const Math::Point3D &center,
                              double radius,
                              const char axe)
{
  this->center = center;
  this->radius = radius;
  this->height = infinity;
  this->axe = axe;
}

RayTracer::Cylinder::~Cylinder() {}

bool RayTracer::Cylinder::hits(const RayTracer::Ray &ray,
                               double ray_tmin,
                               double ray_tmax,
                               Material::Material &rec) const
{
  double a;
  double b;
  double c;
  double discriminant;
  double t;
  double t0;
  double t1;
  Math::Vector3D oc = ray.origin - center;
  Math::Vector3D direction = ray.direction;

  if (axe == 'x' || axe == 'X') {
    a = pow(direction.y, 2) + pow(direction.z, 2);
    b = 2 * (direction.y * oc.y + direction.z * oc.z);
    c = pow(oc.y, 2) + pow(oc.z, 2) - pow(radius, 2);
  } else if (axe == 'y' || axe == 'Y') {
    a = pow(direction.x, 2) + pow(direction.z, 2);
    b = 2 * (direction.x * oc.x + direction.z * oc.z);
    c = pow(oc.x, 2) + pow(oc.z, 2) - pow(radius, 2);
  } else {
    a = pow(direction.x, 2) + pow(direction.y, 2);
    b = 2 * (direction.x * oc.x + direction.y * oc.y);
    c = pow(oc.x, 2) + pow(oc.y, 2) - pow(radius, 2);
  }
  discriminant = pow(b, 2) - 4 * a * c;
  if (discriminant < 0) {
    return false;
  }
  t0 = (-b - sqrt(discriminant)) / (2 * a);
  t1 = (-b + sqrt(discriminant)) / (2 * a);
  if (t0 > t1) {
    double temp = t0;
    t0 = t1;
    t1 = temp;
  }
  if (t0 < 0) {
    t0 = t1;
    if (t0 < 0) {
      return false;
    }
  }
  t = t0;

  rec.p = ray.at(t);
  if (height != infinity) {
    if ((axe == 'x' || axe == 'X') &&
        (rec.p.x < center.x - height / 2 || rec.p.x > center.x + height / 2)) {
      return false;
    } else if ((axe == 'y' || axe == 'Y') &&
               (rec.p.y < center.y - height / 2 ||
                rec.p.y > center.y + height / 2)) {
      return false;
    } else if ((axe == 'z' || axe == 'Z') &&
               (rec.p.z < center.z - height / 2 ||
                rec.p.z > center.z + height / 2)) {
      return false;
    }
  }

  rec.t = t;
  rec.normal = (rec.p - center) / radius;

  return true;
}
