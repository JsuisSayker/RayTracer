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

Math::Vector3D::~Vector3D()
{
}

double Math::Vector3D::length() const
{
    return sqrt(length_squared());
}

double Math::Vector3D::length_squared() const
{
    return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
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


double Math::Vector3D::dot(const Math::Vector3D &v) const
{
    return (x * v.x) + (y * v.y) + (z * v.z);
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
