/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** main
*/

#include "Camera.hpp"
#include "Sphere.hpp"
#include "Ray.hpp"
#include "Point3D.hpp"
#include <iostream>

void write_color(const Math::Vector3D& color)
{
    int ir = static_cast<int>(color.x);
    int ig = static_cast<int>(color.y);
    int ib = static_cast<int>(color.z);
    std::cout << ir << ' ' << ig << ' ' << ib << '\n';
}

int main()
{
    RayTracer ::Camera cam;
    RayTracer ::Sphere s(Math::Point3D(0, 0, -1), 0.5);
    std::cout << "P3\n" << 400 << ' ' << 400 << "\n255\n";
    for (int y = 0; y < 400; y+= 1) {
        for (int x = 0; x < 400; x += 1) {
            double u = x / 400.0;
            double v = y / 400.0;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hits(r)) {
                write_color(Math::Vector3D(255, 0, 0));  // Red color
            } else {
                write_color(Math::Vector3D(0, 0, 255));  // Blue color
            }
        }
    }
}