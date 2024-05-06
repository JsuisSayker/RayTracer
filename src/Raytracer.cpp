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
#include <fstream>

RayTracer::Raytracer::Raytracer()
{
}

RayTracer::Raytracer::~Raytracer()
{
}

int RayTracer::Raytracer::run(std::string scene_file)
{
    // Image
    // double aspect_ratio = 16.0 / 9.0;
    // int image_width = 400;

    // // Calculate the image height, and ensure that it's at least 1.
    // int image_height = int(image_width / aspect_ratio);
    // image_height = (image_height < 1) ? 1 : image_height;

    // // Camera
    // double focal_length = 1.0;
    // double viewport_height = 2.0;
    // double viewport_width = viewport_height * (double(image_width)/image_height);
    RayTracer::Camera cam;

    // // Calculate the vectors across the horizontal and down the vertical viewport edges.
    // Math::Vector3D viewport_u = Math::Vector3D(viewport_width, 0, 0);
    // Math::Vector3D viewport_v = Math::Vector3D(0, -viewport_height, 0);
    // cam.screen.origin = Math::Point3D(-(viewport_width/(double)2), (viewport_height/(double)2), -0.5);
    // cam.screen.left_side = Math::Vector3D(0, viewport_height, 0);
    // cam.screen.bottom_side = Math::Vector3D(viewport_width,0, 0);

    // // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    // double pixel_delta_u = viewport_u.x / image_width;
    // double pixel_delta_v = viewport_v.y / image_height;

    // double variation = 255 / (double)image_width;

    // World
    Scene scene;
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, -1), 0.5));
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -100, -1), 100));

    cam._image_width = 400;
    cam._aspect_ratio = 16.0 / 9.0;

    cam.render(scene);

    (void)scene_file;
    return 0;
}
