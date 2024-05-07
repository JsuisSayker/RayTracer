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
  Math::Point3D origin;
  Math::Vector3D direction;
  Ray();
  Ray(const Math::Point3D &origin, const Math::Vector3D &direction);
  ~Ray();
  Math::Point3D at(double t) const;
};
} // namespace RayTracer

#endif /* !RAY_HPP_ */
