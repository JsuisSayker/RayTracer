/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Glass
*/

#ifndef DIELECTRIC_HPP_
#define DIELECTRIC_HPP_

#include "Material.hpp"

namespace Materials {
class Glass : virtual public Materials::Material {
  public:
    Glass(double refraction_index);
    ~Glass();
    bool scatter(const RayTracer::Ray &r_in, Materials::Material &rec, Math::Vector3D &attenuation,
                 RayTracer::Ray &scattered) const;

  protected:
    double _refraction_index;
};
} // namespace Materials

#endif /* !DIELECTRIC_HPP_ */
