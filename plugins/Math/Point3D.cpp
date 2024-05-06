/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Point3D
*/

#include <Point3D.hpp>

Math::Point3D::Point3D()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Math::Point3D::Point3D(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Math::Point3D::~Point3D()
{
}

Math::Point3D Math::Point3D::operator+(const Math::Vector3D &v) const
{
    return Math::Point3D(x + v.x, y + v.y, z + v.z);
}

Math::Point3D Math::Point3D::operator-(const Math::Vector3D &v) const
{
    return Math::Point3D(x - v.x, y - v.y, z - v.z);
}

Math::Vector3D Math::Point3D::operator-(const Math::Point3D &p) const
{
    return Math::Vector3D(x - p.x, y - p.y, z - p.z);
}

Math::Vector3D Math::Point3D::operator+(const Math::Point3D &p) const
{
    return Math::Vector3D(x + p.x, y + p.y, z + p.z);
}

void Math::Point3D::translate(const Math::Vector3D &translation)
{
    x += translation.x;
    y += translation.y;
    z += translation.z;
}

std::ostream &operator<<(std::ostream &s, const Math::Point3D &other)
{
    s << "x: " << other.x << " y: " << other.y << " z: " << other.z;
    return s;
}