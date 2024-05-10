/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** RayTracer
*/

#ifndef RAY_HPP_
#define RAY_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
class Ray {
public:
  Ray();
  Ray(const Math::Point3D &origin, const Math::Vector3D &direction);
  Ray(const Math::Point3D& origin, const Math::Vector3D& direction, double time);
  ~Ray();

  double time() const;

  Math::Point3D at(double t) const;

  Math::Point3D _origin;
  Math::Vector3D _direction;
  double _tm;
};
} // namespace RayTracer

#endif /* !RAY_HPP_ */
