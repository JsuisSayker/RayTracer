/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** DirectionalLight
*/

#ifndef DIRECTIONALLIGHT_HPP_
#define DIRECTIONALLIGHT_HPP_

#include "Light.hpp"
#include "Vector3D.hpp"

namespace Lights {
class DirectionalLight : public Lights::Light {
  public:
    Math::Vector3D _direction;
    DirectionalLight(const Math::Vector3D &direction);
    ~DirectionalLight();
};
} // namespace Lights

#endif /* !DIRECTIONALLIGHT_HPP_ */
