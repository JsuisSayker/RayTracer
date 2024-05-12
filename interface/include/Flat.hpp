/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Flat
*/

#ifndef LAMBERTIAN_HPP_
#define LAMBERTIAN_HPP_

#include "Material.hpp"

namespace Materials {
class Flat : virtual public Materials::Material {
  public:
    Flat(const Math::Vector3D &albedo);
    ~Flat();

    bool scatter(const RayTracer::Ray &r_in, Materials::Material &rec, Math::Vector3D &attenuation,
                 RayTracer::Ray &scattered) const;

  protected:
};
} // namespace Materials

#endif /* !LAMBERTIAN_HPP_ */
