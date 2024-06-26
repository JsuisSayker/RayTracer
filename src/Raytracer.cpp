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
#include <LoadFile.hpp>
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
    RayTracer::Camera cam;

    LoadFile loader(scene_file, world, cam);
    return OK;
}
