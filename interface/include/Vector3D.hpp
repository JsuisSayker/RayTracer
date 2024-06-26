/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** test
*/

#ifndef VECTOR3D_HPP__
#define VECTOR3D_HPP__

#include "ToolBox.hpp"
#include <cmath>
#include <ostream>
#include <vector>

namespace Math {

class Vector3D {
  public:
    double x;
    double y;
    double z;

    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();

    double length() const;
    double length_squared() const;
    bool near_zero() const;

    // rotate functions
    void rotateX(double angle);
    void rotateY(double angle);
    void rotateZ(double angle);

    double dot(const Vector3D &v) const;

    // Operator overloading
    Vector3D operator+(const Vector3D &v) const;
    Vector3D operator+=(const Vector3D &v);
    Vector3D operator-(const Vector3D &v) const;
    Vector3D operator-=(const Vector3D &v);
    Vector3D operator*(const Vector3D &v) const;
    bool operator!=(const Vector3D &v) const;

    Vector3D operator+(double k) const;
    Vector3D operator-(double k) const;
    Vector3D operator*(double k) const;
    Vector3D operator*=(double k);
    Vector3D operator/(double k) const;
    Vector3D operator/=(double k);

    // template <int N> class Vector {
    // public:
    //   std::vector<double> values;

    //   Vector() : values(N, 0){};
    //   Vector(const std::vector<double> &components){};

    //   // Operator overloading
    //   Vector<N> operator+(const Vector &v) const {
    //     Vector result;
    //     for (int i = 0; i < N; i++) {
    //       result.values[i] = values[i] + v.values[i];
    //     }
    //     return result;
    //   };

    //   Vector<N> operator+=(const Vector &v) {
    //     for (int i = 0; i < N; i++) {
    //       values[i] += v.values[i];
    //     }
    //     return *this;
    //   };

    //   Vector<N> operator-(const Vector &v) const {
    //     Vector result;
    //     for (int i = 0; i < N; i++) {
    //       result.values[i] = values[i] - v.values[i];
    //     }
    //     return result;
    //   };

    //   Vector<N> operator-=(const Vector &v) {
    //     for (int i = 0; i < N; i++) {
    //       values[i] -= v.values[i];
    //     }
    //     return *this;
    //   };

    //   Vector<N> operator*(double k) const {
    //     Vector result;
    //     for (int i = 0; i < N; i++) {
    //       result.values[i] = values[i] * k;
    //     }
    //     return result;
    //   };

    //   Vector<N> operator*=(double k) {
    //     for (int i = 0; i < N; i++) {
    //       values[i] *= k;
    //     }
    //     return *this;
    //   };

    //   Vector<N> operator/(double k) const {
    //     Vector result;
    //     for (int i = 0; i < N; i++) {
    //       result.values[i] = values[i] / k;
    //     }
    //     return result;
    //   };

    //   Vector<N> operator/=(double k) {
    //     for (int i = 0; i < N; i++) {
    //       values[i] /= k;
    //     }
    //     return *this;
    //   };

    //   double dot(const Vector &v) const {
    //     double result = 0;
    //     for (int i = 0; i < N; i++) {
    //       result += values[i] * v.values[i];
    //     }
    //     return result;
    //   };
    // };
};
} // namespace Math

Math::Vector3D cross(const Math::Vector3D &u, const Math::Vector3D &v);
Math::Vector3D unit_vector(const Math::Vector3D &v);
Math::Vector3D random_vector();
Math::Vector3D random_vector(double min, double max);
Math::Vector3D random_in_unit_sphere();
Math::Vector3D random_unit_vector();
Math::Vector3D random_on_hemisphere(const Math::Vector3D &normal);
Math::Vector3D reflect(const Math::Vector3D &v, const Math::Vector3D &n);
Math::Vector3D refract(const Math::Vector3D &uv, const Math::Vector3D &n, double etai_over_etat);
Math::Vector3D random_in_unit_disk();

std::ostream &operator<<(std::ostream &s, const Math::Vector3D &other);

#endif /* !VECTOR3D */
