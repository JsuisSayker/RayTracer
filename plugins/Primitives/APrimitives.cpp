/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitives
*/

#include <APrimitives.hpp>

RayTracer::APrimitives::APrimitives() {}

RayTracer::APrimitives::~APrimitives() {}

void RayTracer::APrimitives::translate(const Math::Vector3D &translation)
{
    this->_center = this->_center + translation;
}

void RayTracer::APrimitives::rotate(double x, double y, double z)
{
    this->_rotation->rotateX(x);
    this->_rotation->rotateY(y);
    this->_rotation->rotateZ(z);
}
