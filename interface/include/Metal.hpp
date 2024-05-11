/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Metal
*/

#ifndef METAL_HPP_
#define METAL_HPP_

#include "Material.hpp"

namespace Material {
class Metal : virtual public Material
{
  public:
    Metal(const Math::Vector3D &albedo, double fuzz);
    ~Metal();
    bool scatter(const RayTracer::Ray &r_in, Material &rec, Math::Vector3D &attenuation,
                 RayTracer::Ray &scattered) const;

  protected:
    double _fuzz;
};
} // namespace Material

#endif /* !METAL_HPP_ */
