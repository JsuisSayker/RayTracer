/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Raytracer
*/

#include <Camera.hpp>
#include <Cylinder.hpp>
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

RayTracer::Raytracer::Raytracer() {}

RayTracer::Raytracer::~Raytracer() {}

int RayTracer::Raytracer::run(std::string scene_file)
{
  Scene scene;

  shared_ptr<Material::Material> material_ground =
      make_shared<Material::Lambertian>(color(0.8, 0.8, 0.0));
  shared_ptr<Material::Material> material_center =
      make_shared<Material::Lambertian>(color(0.1, 0.2, 0.5));
  shared_ptr<Material::Material> material_left =
      make_shared<Material::Metal>(color(0.8, 0.8, 0.8));
  shared_ptr<Material::Material> material_right =
      make_shared<Material::Metal>(color(0.8, 0.6, 0.2));

  world.add(
      make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, material_ground));
  world.add(make_shared<sphere>(point3(0.0, 0.0, -1.2), 0.5, material_center));
  world.add(make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, material_left));
  world.add(make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, material_right));
  scene.addPrimitive(
      std::make_shared<RayTracer::Sphere>(Math::Point3D(0, 0, -1), 0.5));
  scene.addPrimitive(
      std::make_shared<RayTracer::Sphere>(Math::Point3D(0, -100.5, -1), 100));
  // scene.addPrimitive(std::make_shared<RayTracer::Cylinder>(Math::Point3D(0,
  // 0, -1), 0.5));

  RayTracer::Camera cam;
  cam._image_width = 500;
  cam._aspect_ratio = 16.0 / 9.0;
  cam._samples_per_pixel = 20;
  cam._max_depth = 50;

  cam.render(scene);
  (void)scene_file;
  return 0;
}
