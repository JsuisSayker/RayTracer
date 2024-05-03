/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Raytracer
*/

#include "Raytracer.hpp"
#include <Camera.hpp>
#include <Sphere.hpp>
#include <Ray.hpp>
#include <Point3D.hpp>
#include <iostream>

RayTracer::Raytracer::Raytracer()
{
}

RayTracer::Raytracer::~Raytracer()
{
}

void write_color(const Math::Vector3D& color)
{
    int ir = static_cast<int>(color.x);
    int ig = static_cast<int>(color.y);
    int ib = static_cast<int>(color.z);
    std::cout << ir << ' ' << ig << ' ' << ib << '\n';
}

int RayTracer::Raytracer::run(std::string scene_file)
{
    RayTracer::Camera cam;
    RayTracer::Sphere s(Math::Point3D(0, 0, -1), 0.5);
    int len = 400;
    std::cout << "P3\n" << len << ' ' << len << "\n255\n";
    for (int y = 0; y < len; y+= 1) {
        for (int x = 0; x < len; x += 1) {
            double u = x / (double)len;
            double v = y / (double)len;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hits(r)) {
                write_color(Math::Vector3D(255, 0, 0));  // Red color
            } else {
                write_color(Math::Vector3D(0, 0, 255));  // Blue color
            }
        }
    }
    (void)scene_file;
    return 0;
}
