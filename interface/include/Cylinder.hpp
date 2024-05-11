/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Cylinder
*/

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_
#include "APrimitives.hpp"

namespace RayTracer {
class Cylinder : virtual public APrimitives
{
  public:
    Cylinder(const Math::Point3D &center, double radius, double height,
             std::shared_ptr<Material::Material> mat, const char axe = 'y');
    Cylinder(const Math::Point3D &center, double radius, std::shared_ptr<Material::Material> mat,
             const char axe = 'y');
    ~Cylinder();
    bool hits(const RayTracer::Ray &ray, Math::Interval ray_t, Material::Material &rec) const;

  protected:
    double _height;
    double _radius;
    char _axe;

  private:
};
} // namespace RayTracer

#endif /* !CYLINDER_HPP_ */
