/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Glass
*/

#ifndef DIELECTRIC_HPP_
#define DIELECTRIC_HPP_

#include "Material.hpp"

namespace Material {
class Glass : virtual public Material::Material {
  public:
    Glass(double refraction_index);
    ~Glass();
    bool scatter(const RayTracer::Ray &r_in, Material &rec, Math::Vector3D &attenuation,
                 RayTracer::Ray &scattered) const;

  protected:
    double _refraction_index;
};
} // namespace Material

#endif /* !DIELECTRIC_HPP_ */
