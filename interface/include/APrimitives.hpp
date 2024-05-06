/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitives
*/

#ifndef APRIMITIVES_HPP_
#define APRIMITIVES_HPP_

#include <raytracer/IPrimitives.hpp>
#include <memory>

namespace RayTracer {
class APrimitives : virtual public IPrimitives {
public:
  APrimitives();
  ~APrimitives();

  virtual double hits(const RayTracer::Ray &ray, double ray_tmin,
           double ray_tmax, RayTracer::Primitives_record &rec)  const = 0;

  void translate(const Math::Vector3D &translation);
  void rotate(double x, double y, double z);

protected:
  Math::Point3D center;
  Math::Vector3D *rotation;
private:
};
} // namespace RayTracer

#endif /* !APRIMITIVES_HPP_ */