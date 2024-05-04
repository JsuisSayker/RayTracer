/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Raytracer
*/

#include "Raytracer.hpp"
#include "Camera.hpp"
#include "Plane.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include <iostream>

RayTracer::Raytracer::Raytracer()
{
}

RayTracer::Raytracer::~Raytracer()
{
}

Math::Vector3D ray_color(const RayTracer::Ray& r, const Scene& world) {
    if (wolrd.hits(r))
        return Math::Vector3D(255, 0, 0);
    Math::Vector3D unit_direction = r.direction;
    double a = 0.5*(unit_direction.y + 1.0);
    return Math::Vector3D(1.0, 1.0, 1.0) * (1.0-a) + Math::Vector3D(0.5, 0.7, 1.0) * a;
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
    // Image
    double aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = int(image_width / aspect_ratio);
    image_height = (image_height < 1) ? 1 : image_height;

    // Camera
    double focal_length = 1.0;
    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(image_width)/image_height);
    RayTracer::Camera cam;

    // Calculate the vectors across the horizontal and down the vertical viewport edges.
    Math::Vector3D viewport_u = Math::Vector3D(viewport_width, 0, 0);
    Math::Vector3D viewport_v = Math::Vector3D(0, -viewport_height, 0);
    cam.screen.origin = Math::Point3D(-(viewport_width/(double)2), (viewport_height/(double)2), -0.5);
    cam.screen.left_side = Math::Vector3D(0, viewport_height, 0);
    cam.screen.bottom_side = Math::Vector3D(viewport_width,0, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    double pixel_delta_u = viewport_u.x / image_width;
    double pixel_delta_v = viewport_v.y / image_height;

    double variation = 255 / (double)image_width;

    // World
    Scene scene;
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, -1), 0.5));
    RayTracer::Sphere s(Math::Point3D(0, 0, -1), 0.5);
    // RayTracer::Sphere s2(Math::Point3D(0,-100.5,-1), 100);
    // RayTracer::Plane p(0, 'z');
    // RayTracer::Plane p2(0, 'y');
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int y = 0; y < image_height; y += 1) {
        for (int x = 0; x < image_width; x += 1) {
            double u = x * (pixel_delta_u);
            double v = y * (pixel_delta_v);
            RayTracer::Ray r = cam.ray(u, v);
            write_color(ray_color(r, scene));
        }
    }
    (void)scene_file;
    return 0;
}
