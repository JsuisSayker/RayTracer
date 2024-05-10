/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** APrimitives
*/

#ifndef APRIMITIVES_HPP_
#define APRIMITIVES_HPP_

#include <raytracer/IPrimitives.hpp>

namespace RayTracer {
class APrimitives : virtual public IPrimitives {
public:
  APrimitives();
  ~APrimitives();

  virtual bool hits(const RayTracer::Ray &ray,
                    Math::Interval ray_t,
                    Material::Material &rec) const = 0;
  virtual RayTracer::Aabb bounding_box() const = 0;

  void translate(const Math::Vector3D &translation);
  void rotate(double x, double y, double z);

protected:
  Math::Point3D _center;
  Math::Vector3D *_rotation;
  std::shared_ptr<Material::Material> _material;
};
} // namespace RayTracer

#endif /* !APRIMITIVES_HPP_ */
