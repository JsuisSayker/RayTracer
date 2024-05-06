/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::addPrimitive(std::shared_ptr<IPrimitives> primitive)
{
    _primitives.push_back(primitive);
}

void Scene::addCamera(std::shared_ptr<ICamera> camera)
{
    _camera.push_back(camera);
}

bool Scene::hits(const RayTracer::Ray &r, double ray_tmin, double ray_tmax,
    RayTracer::Primitives_record &rec) const
{
    RayTracer::Primitives_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = ray_tmax;

    for (const std::shared_ptr<IPrimitives> &primitive : _primitives) {
        RayTracer::Sphere *temp_sphere = dynamic_cast<RayTracer::Sphere *>
            (primitive.get());
        if (primitive->hits(r, ray_tmin, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}