/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Point3D
*/

#ifndef POINT3D_HPP_
#define POINT3D_HPP_

#include "IPoint3D.hpp"

namespace Math
{
    class Point3D : virtual public Math::IPoint3D {
    public:
        Point3D();
        Point3D(double x, double y, double z);
        ~Point3D();

        Point3D operator+(const IVector3D &v) const;
        Point3D operator-(const IVector3D &v) const;
        Vector3D operator-(const Math::IPoint3D &p) const;
        Vector3D operator+(const Math::IPoint3D &p) const;
        void translate(const Math::IVector3D &translation);
    };
}

#endif /* !POINT3D_HPP_ */
