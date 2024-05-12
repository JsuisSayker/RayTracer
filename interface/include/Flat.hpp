/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Flat
*/

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

#include "Material.hpp"

namespace Material {
class Flat : virtual public Material::Material {
  public:
    Flat(const Math::Vector3D &albedo);
    ~Flat();

    bool scatter(const RayTracer::Ray &r_in, Material &rec, Math::Vector3D &attenuation,
                 RayTracer::Ray &scattered) const;

  protected:
};
} // namespace Material

#endif /* !LAMBERTIAN_HPP_ */
