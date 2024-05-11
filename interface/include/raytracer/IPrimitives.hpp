/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** IPrimitives
*/

#ifndef IPRIMITIVES_HPP_
#define IPRIMITIVES_HPP_

#include <Ray.hpp>

#include <Interval.hpp>
#include <Material.hpp>
#include <PrimitivesRecord.hpp>
#include <memory>

class IPrimitives
{
  public:
    IPrimitives(){};
    ~IPrimitives(){};

    virtual bool hits(const RayTracer::Ray &ray, Math::Interval ray_t,
                      Material::Material &rec) const = 0;
    virtual void rotate(double x, double y, double z) = 0;
    virtual void translate(const Math::Vector3D &translation) = 0;
};

#endif /* !IPRIMITIVES_HPP_ */
