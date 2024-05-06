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
#include "Ray.hpp"
#include "Scene.hpp"
#include <fstream>

namespace RayTracer
{
    class Camera {
    public:
        int _image_width = 100;
        double _aspect_ratio = 1.0;
        Rectangle3D _screen;
        Math::Point3D _origin;
        void render(const Scene& world);
        void initialize();

        Camera();
        ~Camera();

        Ray ray(double u, double v) const;

    protected:
        int _image_height;
        double _pixel_delta_u;
        double _pixel_delta_v;
    };
}

#endif /* !CAMERA_HPP_ */
