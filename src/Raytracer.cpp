/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Raytracer
*/

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
  Scene world;

  auto material_ground =
      std::make_shared<Material::Lambertian>(Math::Vector3D(0.8, 0.8, 0.0));
  auto material_center =
      std::make_shared<Material::Lambertian>(Math::Vector3D(0.1, 0.2, 0.5));
  auto material_left = std::make_shared<Material::Dielectric>(1.50);
  auto material_bubble = std::make_shared<Material::Dielectric>(1.00 / 1.50);
  auto material_right =
      std::make_shared<Material::Metal>(Math::Vector3D(0.8, 0.6, 0.2), 1.0);

  world.addPrimitive(std::make_shared<RayTracer::Sphere>(
      Math::Point3D(0.0, -100.5, -1.0), 100.0, material_ground));
  world.addPrimitive(std::make_shared<RayTracer::Sphere>(
      Math::Point3D(0.0, 0.0, -1.2), 0.5, material_center));
  world.addPrimitive(std::make_shared<RayTracer::Sphere>(
      Math::Point3D(-1.0, 0.0, -1.0), 0.5, material_left));
  world.addPrimitive(std::make_shared<RayTracer::Sphere>(
      Math::Point3D(-1.0, 0.0, -1.0), 0.4, material_bubble));
  world.addPrimitive(std::make_shared<RayTracer::Sphere>(
      Math::Point3D(1.0, 0.0, -1.0), 0.5, material_right));

  RayTracer::Camera cam;
  cam._aspect_ratio = 16.0 / 9.0;
  cam._image_width = 400;
  cam._samples_per_pixel = 20;
  cam._max_depth = 50;

  cam._vfov = 20;
  cam._lookfrom = Math::Point3D(-2, 2, 1);
  cam._lookat = Math::Point3D(0, 0, -1);
  cam._vup = Math::Vector3D(0, 1, 0);

  cam._defocus_angle = 10.0;
  cam._focus_dist = 3.4;

  cam.render(world);
  (void)scene_file;
  return 0;
}
