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

Math::Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z)
{
}

Math::Vector3D::~Vector3D()
{
}

double Math::Vector3D::length()
{
    return sqrt(x * x + y * y + z * z);
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
    return x * v.x + y * v.y + z * v.z;
}
