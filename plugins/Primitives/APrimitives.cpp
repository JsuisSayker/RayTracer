/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitives
*/

#include "APrimitives.hpp"

APrimitives::APrimitives() {}

APrimitives::~APrimitives() {}

void APrimitives::translate(const Math::IVector3D &translation)
{
  this->center = this->center + translation;
}

void APrimitives::rotate(double x, double y, double z)
{
  this->rotation->rotateX(x);
  this->rotation->rotateY(y);
  this->rotation->rotateZ(z);
}
