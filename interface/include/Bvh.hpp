/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Bvh
*/

#ifndef BVH_HPP_
#define BVH_HPP_

#include <Aabb.hpp>

#include "Scene.hpp"

namespace RayTracer {
class Bvh
{
  public:
    Bvh(Scene list);

    Bvh(std::vector<std::shared_ptr<IPrimitives>> &objects, size_t start, size_t end);
    ~Bvh();

    bool hits(const RayTracer::Ray &r, Math::Interval ray_t, Material::Material &rec) const;

    RayTracer::Aabb bounding_box() const;

    std::shared_ptr<IPrimitives> _left;
    std::shared_ptr<IPrimitives> _right;
    std::shared_ptr<RayTracer::Aabb> _bbox;
};
} // namespace RayTracer

#endif /* !BVH_HPP_ */
