/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Vector3D
*/

#include "Vector3D.hpp"

Math::Vector3D::Vector3D()
{
  x = 0;
  y = 0;
  z = 0;
}

Math::Vector3D::Vector3D(double x, double y, double z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

Math::Vector3D::~Vector3D() {}

double Math::Vector3D::length() const { return sqrt(length_squared()); }

double Math::Vector3D::length_squared() const
{
  return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
}

bool Math::Vector3D::near_zero() const
{
  // Return true if the vector is close to zero in all dimensions.
  double s = 1e-8;
  return (fabs(x) < s) && (fabs(y) < s) && (fabs(z) < s);
}

Math::Vector3D Math::Vector3D::operator+(const Math::Vector3D &v) const
{
  return Math::Vector3D(x + v.x, y + v.y, z + v.z);
}

Math::Vector3D Math::Vector3D::operator+=(const Math::Vector3D &v)
{
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

Math::Vector3D Math::Vector3D::operator-(const Math::Vector3D &v) const
{
  return Math::Vector3D(x - v.x, y - v.y, z - v.z);
}

Math::Vector3D Math::Vector3D::operator-=(const Math::Vector3D &v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

Math::Vector3D Math::Vector3D::operator*(const Math::Vector3D &v) const
{
  return Math::Vector3D(x * v.x, y * v.y, z * v.z);
}

Math::Vector3D Math::Vector3D::operator+(double k) const
{
  return Math::Vector3D(x + k, y + k, z + k);
}

Math::Vector3D Math::Vector3D::operator-(double k) const
{
  return Math::Vector3D(x - k, y - k, z - k);
}

Math::Vector3D Math::Vector3D::operator*(double k) const
{
  return Math::Vector3D(x * k, y * k, z * k);
}

Math::Vector3D Math::Vector3D::operator/(double k) const
{
  return Math::Vector3D(x / k, y / k, z / k);
}

Math::Vector3D Math::Vector3D::operator*=(double k)
{
  x *= k;
  y *= k;
  z *= k;
  return *this;
}

Math::Vector3D Math::Vector3D::operator/=(double k)
{
  x /= k;
  y /= k;
  z /= k;
  return *this;
}

void Math::Vector3D::rotateX(double angle)
{
  double rad = angle * M_PI / 180;
  double new_y = this->y * cos(rad) - this->z * sin(rad);
  double new_z = this->y * sin(rad) + this->z * cos(rad);
}

void Math::Vector3D::rotateY(double angle)
{
  double rad = angle * M_PI / 180;
  double new_x = this->x * cos(rad) + this->z * sin(rad);
  double new_z = -this->x * sin(rad) + this->z * cos(rad);
}

void Math::Vector3D::rotateZ(double angle)
{
  double rad = angle * M_PI / 180;
  double new_x = this->x * cos(rad) - this->y * sin(rad);
  double new_y = this->x * sin(rad) + this->y * cos(rad);
}

double Math::Vector3D::dot(const Math::Vector3D &v) const
{
  return (x * v.x) + (y * v.y) + (z * v.z);
}

Math::Vector3D random_vector()
{
  return Math::Vector3D(random_double(), random_double(), random_double());
}

Math::Vector3D random_vector(double min, double max)
{
  return Math::Vector3D(random_double(min, max),
                        random_double(min, max),
                        random_double(min, max));
}

Math::Vector3D cross(const Math::Vector3D &u, const Math::Vector3D &v)
{
  return Math::Vector3D(
      u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x);
}

Math::Vector3D unit_vector(const Math::Vector3D &v) { return v / v.length(); }

Math::Vector3D random_in_unit_sphere()
{
  while (true) {
    Math::Vector3D p = random_vector(-1, 1);
    if (p.length_squared() < 1)
      return p;
  }
}

Math::Vector3D random_unit_vector()
{
  return unit_vector(random_in_unit_sphere());
}

Math::Vector3D random_on_hemisphere(const Math::Vector3D &normal)
{
  Math::Vector3D on_unit_sphere = random_unit_vector();
  if (on_unit_sphere.dot(normal) > 0.0) // In the same hemisphere as the normal
    return on_unit_sphere;
  else
    return on_unit_sphere * -1;
}

Math::Vector3D reflect(const Math::Vector3D &v, const Math::Vector3D &n)
{
  return v - n * 2 * v.dot(n);
}

Math::Vector3D refract(const Math::Vector3D &uv,
                       const Math::Vector3D &n,
                       double etai_over_etat)
{
  double cos_theta = fmin(-uv.dot(n), 1.0);
  Math::Vector3D r_out_perp = (uv + n * cos_theta) * etai_over_etat;
  Math::Vector3D r_out_parallel =
      n * -sqrt(fabs(1.0 - r_out_perp.length_squared()));
  return r_out_perp + r_out_parallel;
}

Math::Vector3D random_in_unit_disk()
{
  while (true) {
    Math::Vector3D p = Math::Vector3D(random_double(-1, 1), random_double(-1, 1), 0);
    if (p.length_squared() < 1)
      return p;
  }
}

std::ostream &operator<<(std::ostream &s, const Math::Vector3D &other)
{
  s << "Vector3D(" << other.x << ", " << other.y << ", " << other.z << ")";
  return s;
}