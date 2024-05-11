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
                              std::shared_ptr<Material::Material> mat,
                              const char axe)
    : _radius(fmax(0, radius))
{
  _center = center;
  _radius = radius;
  _height = height;
  _axe = axe;
  _material = mat;
}

RayTracer::Cylinder::Cylinder(const Math::Point3D &center,
                              double radius,
                              std::shared_ptr<Material::Material> mat,
                              const char axe)
    : _radius(fmax(0, radius))
{
  _center = center;
  _radius = radius;
  _height = infinity;
  _axe = axe;
  _material = mat;
}

RayTracer::Cylinder::~Cylinder() {}

bool RayTracer::Cylinder::hits(const RayTracer::Ray &ray,
                               Math::Interval ray_t,
                               Material::Material &rec) const
{
  double a, b, c, discriminant, t, t0, t1;
  Math::Vector3D oc = ray.origin - _center;
  Math::Vector3D direction = ray.direction;

  if (_axe == 'x' || _axe == 'X') {
    a = pow(direction.y, 2) + pow(direction.z, 2);
    b = 2 * (direction.y * oc.y + direction.z * oc.z);
    c = pow(oc.y, 2) + pow(oc.z, 2) - pow(_radius, 2);
  } else if (_axe == 'y' || _axe == 'Y') {
    a = pow(direction.x, 2) + pow(direction.z, 2);
    b = 2 * (direction.x * oc.x + direction.z * oc.z);
    c = pow(oc.x, 2) + pow(oc.z, 2) - pow(_radius, 2);
  } else {
    a = pow(direction.x, 2) + pow(direction.y, 2);
    b = 2 * (direction.x * oc.x + direction.y * oc.y);
    c = pow(oc.x, 2) + pow(oc.y, 2) - pow(_radius, 2);
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
        t0 = t1;
        if (t0 < 0) {
            return false;
        }
    }
    t = t0;

  rec.p = ray.at(t);
  // limite la taille du cylindre
  if (_height != infinity) {
    if ((_axe == 'x' || _axe == 'X') && (rec.p._x < _center._x - _height / 2 ||
                                         rec.p._x > _center._x + _height / 2)) {
      return false;
    } else if ((_axe == 'y' || _axe == 'Y') &&
               (rec.p._y < _center._y - _height / 2 ||
                rec.p._y > _center._y + _height / 2)) {
      return false;
    } else if ((_axe == 'z' || _axe == 'Z') &&
               (rec.p._z < _center._z - _height / 2 ||
                rec.p._z > _center._z + _height / 2)) {
      return false;
    }
  }
  rec.t = t;
  rec.normal = (rec.p - _center) / _radius;
  rec.p = ray.at(rec.t);
  Math::Vector3D outward_normal = (rec.p - _center) / _radius;
  rec.set_face_normal(ray, outward_normal);
  rec.mat = _material;

    return true;
}
