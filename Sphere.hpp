/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "Vector3D.hpp"
#include "RayTracer.hpp"
#include "Point3D.hpp"


namespace RayTracer
{

    class Sphere
    {
    public:
        Math::Point3D center;
        double radius;

        Sphere(const Math::Point3D &center, double radius);
        ~Sphere();

        bool hits(const Ray &ray) const;
    };

}

#endif /* !SPHERE_HPP_ */
