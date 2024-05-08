/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Point3D.hpp"
#include "Ray.hpp"
#include "Rectangle3D.hpp"
#include "Scene.hpp"
#include "Vector3D.hpp"
#include "Material.hpp"
#include <fstream>

namespace RayTracer {
class Camera {
public:
  int _image_width = 100;
  double _aspect_ratio = 1.0;
  int _samples_per_pixel = 10;
  int _max_depth = 10;
  Rectangle3D _screen;
  Math::Point3D _origin;

  Camera();
  ~Camera();

  void render(const Scene &world);
  void initialize();
  RayTracer::Ray get_ray(int i, int j) const;
  Math::Vector3D sample_square() const;

protected:
  int _image_height;
  double _pixel_samples_scale;
  Math::Vector3D _pixel_delta_u;
  Math::Vector3D _pixel_delta_v;
};
} // namespace RayTracer

#endif /* !CAMERA_HPP_ */
