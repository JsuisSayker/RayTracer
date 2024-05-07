/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include "Vector3D.hpp"

namespace Math {
class Point3D {
public:
  double x;
  double y;
  double z;

  Point3D();
  Point3D(double x, double y, double z);
  ~Point3D();

  Point3D operator+(const Vector3D &v) const;
  Point3D operator-(const Vector3D &v) const;
  Vector3D operator-(const Math::Point3D &p) const;
  Vector3D operator+(const Math::Point3D &p) const;
  Point3D operator+(const double &p) const;
  Point3D operator-(const double &p) const;
  void translate(const Math::Vector3D &translation);
};
} // namespace Math

std::ostream &operator<<(std::ostream &s, const Math::Point3D &other);

#endif /* !POINT3D_HPP_ */
