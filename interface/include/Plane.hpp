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

  Plane(double position, const char axe);
  ~Plane();

  bool hits(const Ray &ray) const;

protected:
private:
};
} // namespace RayTracer

#endif /* !PLANE_HPP_ */
