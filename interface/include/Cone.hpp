/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Cone
*/

#ifndef Cone_HPP_
#define Cone_HPP_
#include "APrimitives.hpp"

namespace RayTracer {
class Cone : virtual public APrimitives {
  public:
    Cone(const Math::Point3D &center, double radius, double height, double angle,
         std::shared_ptr<Materials::Material> mat, const char axe = 'y');
    Cone(const Math::Point3D &center, double radius, double angle,
         std::shared_ptr<Materials::Material> mat, const char axe = 'y');
    ~Cone();
    bool hits(const RayTracer::Ray &ray, Math::Interval ray_t, Materials::Material &rec) const;

  protected:
    double _angle;
    double _height;
    double _radius;
    char _axe;

  private:
};
} // namespace RayTracer

#endif /* !Cone_HPP_ */
