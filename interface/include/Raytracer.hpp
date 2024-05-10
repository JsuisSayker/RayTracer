/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Raytracer
*/

#ifndef RAYTRACER_HPP_
#define RAYTRACER_HPP_

#include <iostream>

namespace RayTracer {
class Raytracer {
public:
  Raytracer();
  ~Raytracer();
  int run(std::string scene_file);
};
} // namespace RayTracer

#endif /* !RAYTRACER_HPP_ */
