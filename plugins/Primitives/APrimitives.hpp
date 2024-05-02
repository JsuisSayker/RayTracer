/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitives
*/

#ifndef APRIMITIVES_HPP_
#define APRIMITIVES_HPP_

#include "IPrimitives.hpp"
#include "IVector3D.hpp"
#include "IPoint3D.hpp"

class APrimitives : virtual public IPrimitives {
public:
  APrimitives();
  ~APrimitives();

  virtual bool hits(const RayTracer::Ray &ray) const = 0;

  void translate(const Math::IVector3D &translation);
  void rotate(double x, double y, double z);

protected:
  Math::IPoint3D *center;
  Math::IVector3D *rotation;
private:
};

#endif /* !APRIMITIVES_HPP_ */
