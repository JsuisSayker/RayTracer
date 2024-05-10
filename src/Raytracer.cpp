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
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -1.5, -1.1), 1));
    scene.addPrimitive(std::make_shared<RayTracer::Cylinder>(Math::Point3D(0, 0, -1), 0.5, 'z'));
    // scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -0.3, -1.1), 0.7));

    RayTracer::Camera cam;
    cam._image_width = 400;
    cam._aspect_ratio = 16.0 / 9.0;
    cam._samples_per_pixel = 100;

    cam.render(scene);
    printf("Raytracer running\n");
    (void)scene_file;
    return 0;
}
