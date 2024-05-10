/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include "Interval.hpp"
#include "Sphere.hpp"
#include <iostream>
#include <memory>
#include <raytracer/ICamera.hpp>
#include <raytracer/IPrimitives.hpp>
#include <raytracer/IScene.hpp>
#include <vector>

class Scene : virtual public IScene {
public:
  Scene();
  ~Scene();

  void addPrimitive(std::shared_ptr<IPrimitives> primitive);
  void addCamera(std::shared_ptr<ICamera> camera);
  bool hits(const RayTracer::Ray &r, Math::Interval ray_t,
            Material::Material &rec) const;

protected:
  std::vector<std::shared_ptr<ICamera>> _camera;
  std::vector<std::shared_ptr<IPrimitives>> _primitives;

private:
};

#endif /* !SCENE_HPP_ */
