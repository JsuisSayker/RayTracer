/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Rectangle3D.hpp"
#include "RayTracer.hpp"

namespace RayTracer
{
    class Camera {
    public:
        Math::Point3D origin;
        Rectangle3D screen;

        Camera();
        ~Camera();

        Ray ray(double u, double v) const;
    };
}

#endif /* !CAMERA_HPP_ */
