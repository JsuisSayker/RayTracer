/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Raytracer
*/

#include <Camera.hpp>
#include <Cone.hpp>
#include <Cylinder.hpp>
#include <Flat.hpp>
#include <Glass.hpp>
#include <Material.hpp>
#include <Metal.hpp>
#include <Plane.hpp>
#include <Point3D.hpp>
#include <Ray.hpp>
#include <Raytracer.hpp>
#include <Scene.hpp>
#include <Sphere.hpp>
#include <fstream>
#include <iostream>
#include <memory>

RayTracer::Raytracer::Raytracer() {}

RayTracer::Raytracer::~Raytracer() {}

int RayTracer::Raytracer::run(std::string scene_file)
{
    Scene scene;

    std::shared_ptr<Materials::Flat> ground_material =
        std::make_shared<Materials::Flat>(Math::Vector3D(0.5, 0.5, 0.5));
    scene.addPrimitive(
        std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -1000, 0), 1000, ground_material));

    std::shared_ptr<Materials::Glass> material1 = std::make_shared<Materials::Glass>(1.5);
    scene.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 1, 0), 1.0, material1));

    std::shared_ptr<Materials::Flat> material2 =
        std::make_shared<Materials::Flat>(Math::Vector3D(0.4, 0.2, 0.1));
    scene.addPrimitive(
        std::make_shared<RayTracer::Sphere>(Math::Point3D(-4, 1, 0), 1.0, material2));

    std::shared_ptr<Materials::Metal> material3 =
        std::make_shared<Materials::Metal>(Math::Vector3D(0, 0.6, 0.5), 0.0);
    scene.addPrimitive(
        std::make_shared<RayTracer::Cylinder>(Math::Point3D(4, 1, 0), 1.0, 0.8, material3));

    scene._ambient_light = 1.0;
    scene._directional_lights.push_back(
        std::make_shared<Lights::DirectionalLight>(Math::Vector3D(1, 1, 1)));

    RayTracer::Camera cam;

    cam._aspect_ratio = 16.0 / 9.0;
    cam._image_width = 400;
    cam._samples_per_pixel = 100;
    cam._max_depth = 50;

    cam._fov = 40;
    cam._lookfrom = Math::Point3D(13, 5, 3);
    cam._lookat = Math::Point3D(0, 0, 0);
    cam._vup = Math::Vector3D(0, 1, 0);

    cam._defocus_angle = 0.6;
    cam._focus_dist = 10.0;

    cam.render_scene(scene);
    (void)scene_file;
    return 0;
}
