/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** main
*/

#include <Camera.hpp>
#include <Sphere.hpp>
#include <Ray.hpp>
#include <Point3D.hpp>
#include <iostream>
#include <Raytracer.hpp>

void write_color(const Math::Vector3D& color)
{
    int ir = static_cast<int>(color.x);
    int ig = static_cast<int>(color.y);
    int ib = static_cast<int>(color.z);
    std::cout << ir << ' ' << ig << ' ' << ib << '\n';
}

void help()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        help();
        return 84;
    }
    std::string arg = av[1];
    if (arg == "--help") {
        help();
        return 0;
    }
    std::shared_ptr<RayTracer::Raytracer> raytracer = std::make_shared<RayTracer::Raytracer>();


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
}