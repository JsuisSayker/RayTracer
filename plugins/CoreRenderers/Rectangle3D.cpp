/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Rectangle3D
*/

#include "Rectangle3D.hpp"

Rectangle3D::Rectangle3D()
{
    this->origin = Math::Point3D(0, 0, 0);
    this->bottom_side = Math::Vector3D(1, 0, 0);
    this->left_side = Math::Vector3D(0, 1, 0);
}
Rectangle3D::~Rectangle3D() {}

Rectangle3D::Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &bottom_side,
                         const Math::Vector3D &left_side)
{
    this->origin = origin;
    this->bottom_side = bottom_side;
    this->left_side = left_side;
}

Math::Point3D Rectangle3D::pointAt(double u, double v) const
{
    return Math::Point3D(this->origin._x + u, this->origin._y + v, this->origin._z);
}

void Rectangle3D::translate(const Math::Vector3D &translation)
{
    this->origin = this->origin + translation;
}