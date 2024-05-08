/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** PrimitivesRecord
*/

#ifndef PRIMITIVESRECORD_HPP_
#define PRIMITIVESRECORD_HPP_

#include "Material.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Vector3D.hpp"
#include <memory>

class PrimitivesRecord {
public:
  PrimitivesRecord(){};
  ~PrimitivesRecord(){};
  Math::Point3D p;
  Math::Vector3D normal;
  std::shared_ptr<Material::Material> mat;
  double t;
  bool front_face;

  void set_face_normal(const RayTracer::Ray &ray,
                       const Math::Vector3D &outward_normal)
  {
    // Sets the hit record normal vector.
    // NOTE: the parameter `outward_normal` is assumed to have unit length.

    front_face = ray.direction.dot(outward_normal) < 0;
    normal = front_face ? outward_normal : outward_normal * (-1);
  }
};

#endif /* !PRIMITIVESRECORD_HPP_ */
