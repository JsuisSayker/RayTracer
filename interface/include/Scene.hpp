/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <memory>
#include <raytracer/IPrimitives.hpp>
#include <raytracer/ICamera.hpp>
#include <Sphere.hpp>
#include <Point3D.hpp>
#include <vector>
#include <iostream>


class Scene {
    public:
        Scene();
        ~Scene();

        void addPrimitive(std::shared_ptr<IPrimitives> primitive);
        void addCamera(std::shared_ptr<ICamera> camera);
        bool hits(const RayTracer::Ray &r, double ray_tmin, double ray_tmax, RayTracer::Primitives_record &rec) const;
    protected:
        std::vector<std::shared_ptr<ICamera>> _camera;
        std::vector<std::shared_ptr<IPrimitives>> _primitives;
    private:
};

#endif /* !SCENE_HPP_ */
