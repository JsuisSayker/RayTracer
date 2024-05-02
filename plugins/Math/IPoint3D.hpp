/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Point3D
*/

#ifndef IPOINT3D_HPP_
#define IPOINT3D_HPP_

#include "Vector3D.hpp"

namespace Math
{
    class IPoint3D {
    public:
        double x;
        double y;
        double z;

        IPoint3D() {};
        IPoint3D(double x, double y, double z) {};
        virtual ~IPoint3D() {};

        virtual void translate(const Math::Vector3D &translation) = 0;
    };
}

#endif /* !IPOINT3D_HPP_ */
