/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** main
*/

#include <Camera.hpp>
#include <Plane.hpp>
#include <Point3D.hpp>
#include <Ray.hpp>
#include <Sphere.hpp>

#include <iostream>

void write_color(const Math::Vector3D &color)
{
  int ir = static_cast<int>(color.x);
  int ig = static_cast<int>(color.y);
  int ib = static_cast<int>(color.z);
  std::cout << ir << ' ' << ig << ' ' << ib << '\n';
}

int main()
{
  RayTracer::Camera cam;
  RayTracer::Sphere s(Math::Point3D(0, 0, -1), 0.5);
  RayTracer::Plane p(-4, 'z');
  RayTracer::Plane p2(-2, 'x');
  int len = 400;
  std::cout << "P3\n" << len << ' ' << len << "\n255\n";
  for (int y = 0; y < len; y += 1) {
    for (int x = 0; x < len; x += 1) {
      double u = x / (double)len;
      double v = y / (double)len;
      RayTracer::Ray r = cam.ray(u, v);
      if (s.hits(r)) {
        write_color(Math::Vector3D(255, 0, 0)); // Red color
      } else if (p2.hits(r)) {
        write_color(Math::Vector3D(0, 255, 0)); // Green color
      } else if (p.hits(r)) {
        write_color(Math::Vector3D(0, 0, 255)); // Blue color
      } else {
       write_color(Math::Vector3D(0, 0, 0)); // Black color
      }
    }
  }
}