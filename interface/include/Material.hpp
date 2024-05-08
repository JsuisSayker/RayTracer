/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
#define MATERIAL_HPP_

#include <raytracer/IMaterial.hpp>

namespace Material {
class Material : virtual public IMaterial {
public:
  Material() : IMaterial() {};
  virtual ~Material() = default;

  virtual bool scatter(const RayTracer::Ray &r_in,
                       const PrimitivesRecord &rec,
                       Math::Vector3D &attenuation,
                       RayTracer::Ray &scattered) const = 0;
};
} // namespace Material

#endif /* !MATERIAL_HPP_ */
