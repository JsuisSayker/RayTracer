/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <iostream>
#include <memory>
#include <raytracer/ICamera.hpp>
#include <raytracer/IPrimitives.hpp>
#include <vector>

#include "Aabb.hpp"
#include "Interval.hpp"
#include "Point3D.hpp"
#include "Sphere.hpp"

class Scene
{
  public:
    Scene();
    ~Scene();

    void addPrimitive(std::shared_ptr<IPrimitives> primitive);
    void addCamera(std::shared_ptr<ICamera> camera);
    bool hits(const RayTracer::Ray &r, Math::Interval ray_t, Material::Material &rec) const;
    RayTracer::Aabb bounding_box() const;

    std::vector<std::shared_ptr<ICamera>> _camera;
    std::vector<std::shared_ptr<IPrimitives>> _primitives;
    RayTracer::Aabb _bbox;
};

#endif /* !SCENE_HPP_ */
