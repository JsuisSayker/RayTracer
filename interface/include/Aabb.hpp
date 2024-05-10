/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** aabb
*/

#ifndef AABB_HPP_
#define AABB_HPP_

#include "APrimitives.hpp"

namespace RayTracer {
class Aabb
{
  public:
    Aabb();
    Aabb(const Math::Interval &x, const Math::Interval &y, const Math::Interval &z);
    Aabb(const Math::Point3D &a, const Math::Point3D &b);
    Aabb(const RayTracer::Aabb &box0, const RayTracer::Aabb &box1);
    ~Aabb();

    const Math::Interval &axis_interval(int n) const;

    bool hit(const RayTracer::Ray &r, Math::Interval ray_t) const;

    Math::Interval _x;
    Math::Interval _y;
    Math::Interval _z;
};
} // namespace RayTracer

#endif /* !AABB_HPP_ */
