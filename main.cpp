/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** main
*/

#include "Camera.hpp"
#include "Sphere.hpp"
#include "RayTracer.hpp"
#include "Point3D.hpp"
#include <iostream>

void write_color(const Math::Vector3D& color)
{
    int ir = static_cast<int>(255.999 * color.x);
    int ig = static_cast<int>(255.999 * color.y);
    int ib = static_cast<int>(255.999 * color.z);
    std::cout << ir << ' ' << ig << ' ' << ib << '\n';
}

int main()
{
    RayTracer ::Camera cam;
    RayTracer ::Sphere s(Math::Point3D(0, 0, 0), 5);
    for (int y = 0; y < cam.screen.bottom_side.length(); y++) {
        for (int x = 0; x < cam.screen.left_side.length(); x++) {
            double u = x;
            double v = y;
            RayTracer ::Ray r = cam.ray(u, v);
            if (s.hits(r))
            {
                write_color(Math::Vector3D(1, 0, 0));  // Red color
            }
            else
            {
                write_color(Math::Vector3D(0, 0, 1));  // Blue color
            }
        }
    }
}