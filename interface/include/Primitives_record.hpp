/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Primitives_record
*/

#ifndef PRIMITIVES_RECORD_HPP_
#define PRIMITIVES_RECORD_HPP_

#include "Ray.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

namespace RayTracer {
class Primitives_record {
  public:
    Math::Point3D p;
    Math::Vector3D normal;
    double t;
    bool front_face;

    void set_face_normal(const RayTracer::Ray &ray, const Math::Vector3D &outward_normal)
    {
      // Sets the hit record normal vector.
      // NOTE: the parameter `outward_normal` is assumed to have unit length.

      front_face = ray.direction.dot(outward_normal) < 0;
      normal = front_face ? outward_normal : outward_normal * (-1);
    }
};
}

#endif /* !PRIMITIVES_RECORD_HPP_ */
