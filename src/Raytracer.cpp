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
    Scene scene;
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -100.5, -1), 100));
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, -1), 0.5));

    RayTracer::Camera cam;
    cam._image_width = 400;
    cam._aspect_ratio = 16.0 / 9.0;

    cam.render(scene);

    (void)scene_file;
    return 0;
}
