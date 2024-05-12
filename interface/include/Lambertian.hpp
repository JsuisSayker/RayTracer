/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Lambertian
*/

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

#include "Material.hpp"

namespace Material {
class Lambertian : virtual public Material::Material {
  public:
    Lambertian(const Math::Vector3D &albedo);
    ~Lambertian();

    bool scatter(const RayTracer::Ray &r_in, Material &rec, Math::Vector3D &attenuation,
                 RayTracer::Ray &scattered) const;

  protected:
};
} // namespace Material

#endif /* !LAMBERTIAN_HPP_ */
