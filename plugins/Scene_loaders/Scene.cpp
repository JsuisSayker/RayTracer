/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#include "Scene.hpp"
#include "Lambertian.hpp"

Scene::Scene() { _ambient_light = 0.0; }

Scene::~Scene() {}

void Scene::addPrimitive(std::shared_ptr<IPrimitives> primitive)
{
  _primitives.push_back(primitive);
}

void Scene::addCamera(std::shared_ptr<ICamera> camera)
{
  _camera.push_back(camera);
}

std::shared_ptr<ICamera> Scene::getCamera()
{
  return _camera[0];
}

bool Scene::hits(const RayTracer::Ray &r, Math::Interval ray_t,
                 Material::Material &rec) const {
  Material::Lambertian temp_rec(Math::Vector3D(0, 0, 0));
  bool hit_anything = false;
  double closest_so_far = ray_t._max;

    for (const std::shared_ptr<IPrimitives> &primitive : _primitives) {
        RayTracer::Sphere *temp_sphere = dynamic_cast<RayTracer::Sphere *>(primitive.get());
        if (primitive->hits(r, Math::Interval(ray_t._min, closest_so_far), temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }
    return hit_anything;
}