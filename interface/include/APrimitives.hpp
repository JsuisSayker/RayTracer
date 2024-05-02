/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitives
*/

#ifndef APRIMITIVES_HPP_
#define APRIMITIVES_HPP_

#include <raytracer/IPrimitives.hpp>
#include <raytracer/IVector3D.hpp>
#include <raytracer/IPoint3D.hpp>

class APrimitives : virtual public IPrimitives {
public:
  APrimitives();
  ~APrimitives();

  virtual bool hits(const RayTracer::Ray &ray) const = 0;

  void translate(const Math::Vector3D &translation);
  void rotate(double x, double y, double z);

protected:
  Math::Point3D *center;
  Math::IVector3D *rotation;
private:
};

#endif /* !APRIMITIVES_HPP_ */
