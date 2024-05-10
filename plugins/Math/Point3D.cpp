/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Point3D
*/

#include <Point3D.hpp>

Math::Point3D::Point3D()
{
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

Math::Point3D::Point3D(double x, double y, double z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Math::Point3D::~Point3D() {}

Math::Point3D Math::Point3D::operator+(const Math::Vector3D &v) const
{
    return Math::Point3D(_x + v.x, _y + v.y, _z + v.z);
}

Math::Point3D Math::Point3D::operator-(const Math::Vector3D &v) const
{
    return Math::Point3D(_x - v.x, _y - v.y, _z - v.z);
}

Math::Vector3D Math::Point3D::operator-(const Math::Point3D &p) const
{
    return Math::Vector3D(_x - p._x, _y - p._y, _z - p._z);
}

Math::Vector3D Math::Point3D::operator+(const Math::Point3D &p) const
{
    return Math::Vector3D(_x + p._x, _y + p._y, _z + p._z);
}

Math::Point3D Math::Point3D::operator+(const double &p) const
{
    return Math::Point3D(_x + p, _y + p, _z + p);
}

Math::Point3D Math::Point3D::operator-(const double &p) const
{
    return Math::Point3D(_x - p, _y - p, _z - p);
}

void Math::Point3D::translate(const Math::Vector3D &translation)
{
    _x += translation.x;
    _y += translation.y;
    _z += translation.z;
}

std::ostream &operator<<(std::ostream &s, const Math::Point3D &other)
{
    s << "x: " << other._x << " y: " << other._y << " z: " << other._z;
    return s;
}