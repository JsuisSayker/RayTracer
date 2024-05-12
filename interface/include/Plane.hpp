/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Plane
*/

#ifndef PLANE_HPP_
#define PLANE_HPP_
#include "APrimitives.hpp"

namespace RayTracer {
class Plane : virtual public APrimitives {
  public:
    Plane(const char axe, double position, std::shared_ptr<Materials::Material> mat);
    ~Plane();

    bool hits(const RayTracer::Ray &ray, Math::Interval ray_t, Materials::Material &rec) const;

  protected:
    double _position;
    char _axe;

  private:
};
} // namespace RayTracer

#endif /* !PLANE_HPP_ */
