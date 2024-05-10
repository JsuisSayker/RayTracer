/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Dielectric
*/

#ifndef DIELECTRIC_HPP_
#define DIELECTRIC_HPP_

#include "Material.hpp"

namespace Material {
class Dielectric : virtual public Material::Material {
    public:
        Dielectric(double refraction_index);
        ~Dielectric();
        bool scatter(const RayTracer::Ray &r_in,
               Material &rec,
               Math::Vector3D &attenuation,
               RayTracer::Ray &scattered) const;


protected:
    double _refraction_index;
};
}

#endif /* !DIELECTRIC_HPP_ */
