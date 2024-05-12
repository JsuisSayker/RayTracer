/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Cone
*/

#include <Cone.hpp>

RayTracer::Cone::Cone(const Math::Point3D &center, double radius, double height, double angle,
                      std::shared_ptr<Material::Material> mat, const char axe)
    : _radius(fmax(0, radius))
{
    _angle = angle;
    _center = center;
    _radius = radius;
    _height = height;
    _axe = axe;
    _material = mat;
}

RayTracer::Cone::Cone(const Math::Point3D &center, double radius, double angle,
                      std::shared_ptr<Material::Material> mat, const char axe)
    : _radius(fmax(0, radius))
{
    _angle = angle;
    _center = center;
    _radius = radius;
    _height = infinity;
    _axe = axe;
    _material = mat;
}

RayTracer::Cone::~Cone() {}

bool RayTracer::Cone::hits(const RayTracer::Ray &ray, Math::Interval ray_t,
                           Material::Material &rec) const
{
    double a, b, c, discriminant, t, t0, t1;
    Math::Vector3D oc = ray._origin - _center;
    Math::Vector3D direction = ray._direction;

    double cos2 = cos(_angle) * cos(_angle);
    double sin2 = sin(_angle) * sin(_angle);

    if (_axe == 'x' || _axe == 'X') {
        a = direction.y * direction.y + direction.z * direction.z -
            direction.x * direction.x * cos2;
        b = 2 * (oc.y * direction.y + oc.z * direction.z - oc.x * direction.x * cos2);
        c = oc.y * oc.y + oc.z * oc.z - oc.x * oc.x * cos2;
    } else if (_axe == 'y' || _axe == 'Y') {
        a = direction.x * direction.x + direction.z * direction.z -
            direction.y * direction.y * cos2;
        b = 2 * (oc.x * direction.x + oc.z * direction.z - oc.y * direction.y * cos2);
        c = oc.x * oc.x + oc.z * oc.z - oc.y * oc.y * cos2;
    } else {
        a = direction.x * direction.x + direction.y * direction.y -
            direction.z * direction.z * cos2;
        b = 2 * (oc.x * direction.x + oc.y * direction.y - oc.z * direction.z * cos2);
        c = oc.x * oc.x + oc.y * oc.y - oc.z * oc.z * cos2;
    }

    discriminant = pow(b, 2) - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }
    t0 = (-b - sqrt(discriminant)) / (2 * a);
    t1 = (-b + sqrt(discriminant)) / (2 * a);
    if (t0 > t1) {
        double temp = t0;
        t0 = t1;
        t1 = temp;
    }
    if (t0 < 0) {
        t0 = t1;
        if (t0 < 0) {
            return false;
        }
    }
    t = t0;

    rec.t = t;
    rec.p = ray.at(rec.t);

    if (_axe == 'x' || _axe == 'X') {
        if (rec.p._x < _center._x || rec.p._x > _center._x + _height) {
            return false;
        }
    } else if (_axe == 'y' || _axe == 'Y') {
        if (rec.p._y < _center._y || rec.p._y > _center._y + _height) {
            return false;
        }
    } else {
        if (rec.p._z < _center._z || rec.p._z > _center._z + _height) {
            return false;
        }
    }

    Math::Vector3D outward_normal = (rec.p - _center) / _radius;
    rec.set_face_normal(ray, outward_normal);
    rec.mat = _material;

    return true;
}
