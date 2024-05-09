/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** IScene
*/

#ifndef ISCENE_HPP_
#define ISCENE_HPP_
#include <Sphere.hpp>
#include <Point3D.hpp>
#include <vector>
#include <iostream>
#include <memory>
#include <raytracer/IPrimitives.hpp>
#include <raytracer/ICamera.hpp>


class IScene {
    public:
        IScene(){};
        virtual ~IScene(){};
        virtual void addPrimitive(std::shared_ptr<IPrimitives> primitive) = 0;
        virtual void addCamera(std::shared_ptr<ICamera> camera) = 0;
        virtual bool hits(const RayTracer::Ray &r, double ray_tmin, double ray_tmax, RayTracer::Primitives_record &rec) const = 0;

    protected:
    private:
};

#endif /* !ISCENE_HPP_ */