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
