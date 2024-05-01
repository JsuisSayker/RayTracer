/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Rectangle3D
*/

#ifndef RECTANGLE3D_HPP_
#define RECTANGLE3D_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"

class Rectangle3D {
    public:
    Math::Point3D origin;
    Math::Vector3D bottom_side;
    Math::Vector3D left_side;

    Rectangle3D();
    Rectangle3D(const Math::Point3D &origin, const Math::Vector3D &bottom_side, const Math::Vector3D &left_side);
    ~Rectangle3D();

    Math::Point3D pointAt(double u, double v) const;
    void translate(const Math::Vector3D &translation);
};

#endif /* !RECTANGLE3D_HPP_ */
