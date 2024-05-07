/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "APrimitives.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
class Sphere : virtual public APrimitives {
public:
  Math::Point3D center;
  double radius;

  Sphere(const Math::Point3D &center, double radius);
  ~Sphere();

  bool hits(const RayTracer::Ray &ray, Math::Interval ray_t,
            RayTracer::Primitives_record &rec) const;
  void translate(const Math::Vector3D &translation);
};
} // namespace RayTracer

#endif /* !SPHERE_HPP_ */
