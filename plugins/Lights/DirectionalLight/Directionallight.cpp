/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** DirectionalLight
*/

#include "DirectionalLight.hpp"

Lights::DirectionalLight::DirectionalLight(const Math::Vector3D &direction) : Lights::Light()
{
    _direction = direction;
}

Lights::DirectionalLight::~DirectionalLight() {}
