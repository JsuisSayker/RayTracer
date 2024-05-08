/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Raytracer
*/

#include <Raytracer.hpp>
#include <Camera.hpp>
#include <Plane.hpp>
#include <Point3D.hpp>
#include <Ray.hpp>
#include <Scene.hpp>
#include <Sphere.hpp>
#include <Cylinder.hpp>
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
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, -1), 0.5));
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -100.5, -1), 100));
    // scene.addPrimitive(std::make_shared<RayTracer::Cylinder>(Math::Point3D(0, 0, -1), 0.5));

    RayTracer::Camera cam;
    cam._image_width = 500;
    cam._aspect_ratio = 16.0 / 9.0;
    cam._samples_per_pixel = 20;
    cam._max_depth = 50;

    cam.render(scene);
    (void)scene_file;
    return 0;
}
