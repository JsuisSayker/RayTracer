/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_
#include "APrimitives.hpp"

namespace RayTracer {
class Plane : virtual public APrimitives {
public:
  double position;
  char axe;

  Plane(const char axe, double position);
  ~Plane();

  bool hits(const RayTracer::Ray &ray, double ray_tmin,
           double ray_tmax, RayTracer::Primitives_record &rec) const;

protected:
private:
};
} // namespace RayTracer

#endif /* !PLANE_HPP_ */
