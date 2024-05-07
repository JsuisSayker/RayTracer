/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitives
*/

#include <APrimitives.hpp>

RayTracer::APrimitives::APrimitives() {}

RayTracer::APrimitives::~APrimitives() {}

void RayTracer::APrimitives::translate(const Math::Vector3D &translation) {
  this->center = this->center + translation;
}

void RayTracer::APrimitives::rotate(double x, double y, double z) {
  this->rotation->rotateX(x);
  this->rotation->rotateY(y);
  this->rotation->rotateZ(z);
}
