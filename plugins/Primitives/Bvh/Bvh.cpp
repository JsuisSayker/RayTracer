/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Bvh
*/

#include "Bvh.hpp"

#include <algorithm>

RayTracer::Bvh::Bvh(Scene list) : Bvh(list._primitives, 0, list._primitives.size()) {}

RayTracer::Bvh::Bvh(std::vector<std::shared_ptr<IPrimitives>> &objects, size_t start, size_t end)
{
    int axis = random_int(0, 2);

    auto comparator = (axis == 0) ? box_x_compare : (axis == 1) ? box_y_compare : box_z_compare;

    size_t object_span = end - start;

    if (object_span == 1) {
        _left = _right = objects[start];
    } else if (object_span == 2) {
        _left = objects[start];
        _right = objects[start + 1];
    } else {
        std::sort(objects.begin() + start, objects.begin() + end, comparator);

        auto mid = start + object_span / 2;
        _left = std::make_shared<RayTracer::Bvh>(objects, start, mid);
        _right = std::make_shared<RayTracer::Bvh>(objects, mid, end);
    }

    _bbox = std::make_shared<RayTracer::Aabb>(_left->bounding_box(), _right->bounding_box());
}

~Bvh();

bool RayTracer::Bvh::hits(const RayTracer::Ray &r, Math::Interval ray_t,
                          Material::Material &rec) const
{
    if (!_bbox.get()->hit(r, ray_t))
        return false;

    bool hit_left = _left.get()->hits(r, ray_t, rec);
    bool hit_right =
        _right.get()->hits(r, Math::Interval(ray_t._min, hit_left ? rec.t : ray_t._max), rec);

    return hit_left || hit_right;
}

RayTracer::Aabb RayTracer::Bvh::bounding_box() const { return bbox; }

RayTracer::Bvh::~Bvh() {}

static bool box_compare(const shared_ptr<hittable> a, const shared_ptr<hittable> b, int axis_index)
{
    auto a_axis_interval = a->bounding_box().axis_interval(axis_index);
    auto b_axis_interval = b->bounding_box().axis_interval(axis_index);
    return a_axis_interval.min < b_axis_interval.min;
}

static bool box_x_compare(const shared_ptr<hittable> a, const shared_ptr<hittable> b)
{
    return box_compare(a, b, 0);
}

static bool box_y_compare(const shared_ptr<hittable> a, const shared_ptr<hittable> b)
{
    return box_compare(a, b, 1);
}

static bool box_z_compare(const shared_ptr<hittable> a, const shared_ptr<hittable> b)
{
    return box_compare(a, b, 2);
}