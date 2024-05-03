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
  Math::Point3D position;
  Math::Vector3D normal;

  Plane(const Math::Point3D &position, const Math::Vector3D &normal);
  ~Plane();

  bool hits(const Ray &ray) const;
  void translate(const Math::Vector3D &translation);

protected:
private:
};
} // namespace RayTracer

#endif /* !PLANE_HPP_ */
