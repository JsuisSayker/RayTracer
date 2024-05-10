/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Aabb
*/

#include <Aabb.hpp>

RayTracer::Aabb::Aabb()
{
  _x = Math::Interval();
  _y = Math::Interval();
  _z = Math::Interval();
}

RayTracer::Aabb::Aabb(const Math::Interval &x,
                      const Math::Interval &y,
                      const Math::Interval &z)
{
  this->_x = x;
  this->_y = y;
  this->_z = z;
}

RayTracer::Aabb::Aabb(const Math::Point3D &a, const Math::Point3D &b)
{
  // Treat the two points a and b as extrema for the bounding box, so we don't
  // require a particular minimum/maximum coordinate order.

  _x = (a._x <= b._x) ? Math::Interval(a._x, b._x) : Math::Interval(b._x, a._x);
  _y = (a._y <= b._y) ? Math::Interval(a._y, b._y) : Math::Interval(b._y, a._y);
  _z = (a._z <= b._z) ? Math::Interval(a._z, b._z) : Math::Interval(b._z, a._z);
}

RayTracer::Aabb::Aabb(const RayTracer::Aabb &box0, const RayTracer::Aabb &box1)
{
  _x = Math::Interval(box0._x, box1._x);
  _y = Math::Interval(box0._y, box1._y);
  _z = Math::Interval(box0._z, box1._z);
}

const Math::Interval &RayTracer::Aabb::axis_interval(int n) const
{
  if (n == 1)
    return _y;
  if (n == 2)
    return _z;
  return _x;
}

bool RayTracer::Aabb::hit(const RayTracer::Ray &r, Math::Interval ray_t) const
{
  const Math::Point3D &ray_orig = r._origin;
  const Math::Vector3D &ray_dir = r._direction;

  // x
  const Math::Interval &ax_x = axis_interval(0);
  const double adinv_x = 1.0 / ray_dir.x;

  double t0_x = (ax_x._min - ray_orig._x) * adinv_x;
  double t1_x = (ax_x._max - ray_orig._x) * adinv_x;

  if (t0_x < t1_x) {
    if (t0_x > ray_t._min)
      ray_t._min = t0_x;
    if (t1_x < ray_t._max)
      ray_t._max = t1_x;
  } else {
    if (t1_x > ray_t._min)
      ray_t._min = t1_x;
    if (t0_x < ray_t._max)
      ray_t._max = t0_x;
  }

  if (ray_t._max <= ray_t._min)
    return false;
  // y
  const Math::Interval &ax_y = axis_interval(1);
  const double adinv_y = 1.0 / ray_dir.y;

  double t0_y = (ax_y._min - ray_orig._y) * adinv_y;
  double t1_y = (ax_y._max - ray_orig._y) * adinv_y;

  if (t0_y < t1_y) {
    if (t0_y > ray_t._min)
      ray_t._min = t0_y;
    if (t1_y < ray_t._max)
      ray_t._max = t1_y;
  } else {
    if (t1_y > ray_t._min)
      ray_t._min = t1_y;
    if (t0_y < ray_t._max)
      ray_t._max = t0_y;
  }

  if (ray_t._max <= ray_t._min)
    return false;
  // z
  const Math::Interval &ax_z = axis_interval(2);
  const double adinv_z = 1.0 / ray_dir.z;

  double t0_z = (ax_z._min - ray_orig._z) * adinv_z;
  double t1_z = (ax_z._max - ray_orig._z) * adinv_z;

  if (t0_z < t1_z) {
    if (t0_z > ray_t._min)
      ray_t._min = t0_z;
    if (t1_z < ray_t._max)
      ray_t._max = t1_z;
  } else {
    if (t1_z > ray_t._min)
      ray_t._min = t1_z;
    if (t0_z < ray_t._max)
      ray_t._max = t0_z;
  }

  if (ray_t._max <= ray_t._min)
    return false;
  return true;
}

RayTracer::Aabb::~Aabb() {}
