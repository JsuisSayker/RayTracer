/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Raytracer
*/

#include <Bvh.hpp>
#include <Camera.hpp>
#include <Cylinder.hpp>
#include <Dielectric.hpp>
#include <Lambertian.hpp>
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
<<<<<<< HEAD
<<<<<<< HEAD
    Scene world = Scene(std::make_shared<RayTracer::Bvh>(world));
=======
    Scene world;
>>>>>>> dev
=======
    Scene world;
>>>>>>> origin/dev

    std::shared_ptr<Material::Lambertian> ground_material =
        std::make_shared<Material::Lambertian>(Math::Vector3D(0.5, 0.5, 0.5));
    world.addPrimitive(
        std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -1000, 0), 1000, ground_material));

    for (int a = -6; a < 6; a++) {
        for (int b = -6; b < 6; b++) {
            double choose_mat = random_double();
            Math::Point3D center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());

            if ((center - Math::Point3D(4, 0.2, 0)).length() > 0.9) {
                std::shared_ptr<Material::Material> sphere_material;

                if (choose_mat < 0.8) {
                    // diffuse
                    Math::Vector3D albedo = random_vector() * random_vector();
                    sphere_material = std::make_shared<Material::Lambertian>(albedo);
                    Math::Point3D center2 = center + Math::Vector3D(0, random_double(0, .5), 0);
                    world.addPrimitive(
                        std::make_shared<RayTracer::Sphere>(center, center2, 0.2, sphere_material));
                } else if (choose_mat < 0.95) {
                    // metal
                    Math::Vector3D albedo = random_vector(0.5, 1);
                    double fuzz = random_double(0, 0.5);
                    sphere_material = std::make_shared<Material::Metal>(albedo, fuzz);
                    world.addPrimitive(
                        std::make_shared<RayTracer::Sphere>(center, 0.2, sphere_material));
                } else {
                    // glass
                    sphere_material = std::make_shared<Material::Dielectric>(1.5);
                    world.addPrimitive(
                        std::make_shared<RayTracer::Sphere>(center, 0.2, sphere_material));
                }
            }
        }
    }

    std::shared_ptr<Material::Dielectric> material1 = std::make_shared<Material::Dielectric>(1.5);
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 1, 0), 1.0, material1));

    std::shared_ptr<Material::Lambertian> material2 =
        std::make_shared<Material::Lambertian>(Math::Vector3D(0.4, 0.2, 0.1));
    world.addPrimitive(
        std::make_shared<RayTracer::Sphere>(Math::Point3D(-4, 1, 0), 1.0, material2));

    std::shared_ptr<Material::Metal> material3 =
        std::make_shared<Material::Metal>(Math::Vector3D(0.7, 0.6, 0.5), 0.0);
    world.addPrimitive(std::make_shared<RayTracer::Sphere>(Math::Point3D(4, 1, 0), 1.0, material3));

    RayTracer::Camera cam;

    cam._aspect_ratio = 16.0 / 9.0;
    cam._image_width = 400;
    cam._samples_per_pixel = 20;
    cam._max_depth = 50;

    cam._vfov = 20;
    cam._lookfrom = Math::Point3D(13, 2, 3);
    cam._lookat = Math::Point3D(0, 0, 0);
    cam._vup = Math::Vector3D(0, 1, 0);

    cam._defocus_angle = 0.6;
    cam._focus_dist = 10.0;

    cam.render(world);
    (void)scene_file;
    return 0;
}
