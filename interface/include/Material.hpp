/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

// #include <raytracer/IMaterial.hpp>
#include <PrimitivesRecord.hpp>
#include <Ray.hpp>
#include <Vector3D.hpp>

namespace Material {
class Material {
public:
  Material() {};
  virtual ~Material() = default;

  virtual bool scatter(const RayTracer::Ray &r_in,
                       Material &rec,
                       Math::Vector3D &attenuation,
                       RayTracer::Ray &scattered) const = 0;
  std::shared_ptr<Material> mat;
  double t;
  Math::Point3D p;
  Math::Vector3D normal;
  bool front_face;
  void set_face_normal(const RayTracer::Ray &ray,
                       const Math::Vector3D &outward_normal)
  {
    // Sets the hit record normal vector.
    // NOTE: the parameter `outward_normal` is assumed to have unit length.

    front_face = ray._direction.dot(outward_normal) < 0;
    normal = front_face ? outward_normal : outward_normal * (-1);
  }
  protected:
    Math::Vector3D _albedo;
};
}

#endif /* !MATERIAL_HPP_ */
