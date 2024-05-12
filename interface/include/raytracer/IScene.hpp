/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include <memory>
#include <vector>
#include "ICamera.hpp"
#include "IPrimitives.hpp"

class IScene {
    public:
        IScene(){};
        virtual ~IScene() = default;
        virtual void addPrimitive(std::shared_ptr<IPrimitives> primitive) = 0;
        virtual void addCamera(std::shared_ptr<ICamera> camera) = 0;
        virtual std::shared_ptr<ICamera> getCamera() = 0;

  protected:
  private:
};

#endif /* !ISCENE_HPP_ */
