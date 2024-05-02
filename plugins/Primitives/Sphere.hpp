/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "Vector3D.hpp"
#include "Ray.hpp"
#include "Point3D.hpp"
#include "APrimitives.hpp"

namespace RayTracer
{

    class Sphere: public APrimitives
    {
    public:
        Math::Point3D center;
        double radius;

        Sphere(const Math::Point3D &center, double radius);
        ~Sphere();

        bool hits(const Ray &ray) const;
        void translate(const Math::Vector3D &translation);
    };

}

#endif /* !SPHERE_HPP_ */