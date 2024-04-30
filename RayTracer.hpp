/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** RayTracer
*/

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include "Vector3D.hpp"
#include "Point3D.hpp"

namespace RayTracer {
    class Ray {
        public:
            Math::Point3D origin;
            Math::Vector3D direction;
            Ray();
            Ray(const Math::Point3D& origin, const Math::Vector3D& direction);
            ~Ray();
    };
}

#endif /* !RAYTRACER_HPP_ */
