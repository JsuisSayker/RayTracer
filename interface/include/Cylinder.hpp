/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_
#include "APrimitives.hpp"

namespace RayTracer {
class Cylinder : virtual public APrimitives {
public:
  Math::Point3D center;
  double radius;
  double height;
  char axe;
  Cylinder(const Math::Point3D &center,
           double radius,
           double height,
           const char axe = 'y');
  Cylinder(const Math::Point3D &center,
           double radius,
           const char axe = 'y');
  ~Cylinder();
  bool hits(const RayTracer::Ray &ray, Math::Interval ray_t,
                    RayTracer::Primitives_record &rec) const;

protected:
private:
};
} // namespace RayTracer

#endif /* !CYLINDER_HPP_ */
