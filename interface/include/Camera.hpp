/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Material.hpp"
#include "Point3D.hpp"
#include "Ray.hpp"
#include "Rectangle3D.hpp"
#include "Scene.hpp"
#include "Vector3D.hpp"
#include <fstream>

namespace RayTracer {
class Camera {
  public:
    Rectangle3D _screen;
    Math::Point3D _origin;

    int _image_width = 100;
    double _aspect_ratio = 1.0;
    int _samples_per_pixel = 10;
    int _max_depth = 10;

    double _fov = 90;
    Math::Point3D _lookfrom = Math::Point3D(0, 0, 0);
    Math::Point3D _lookat = Math::Point3D(0, 0, -1);
    Math::Vector3D _vup = Math::Vector3D(0, 1, 0);

    double _defocus_angle = 0;
    double _focus_dist = 10;

    Camera();
    ~Camera();

    void render_scene(const Scene &world);
    void initialize();
    RayTracer::Ray get_ray(int i, int j) const;
    Math::Vector3D sample_square() const;
    Math::Point3D defocus_disk_sample() const;

  protected:
    int _image_height;
    double _pixel_samples_scale;
    Math::Vector3D _pixel_delta_u;
    Math::Vector3D _pixel_delta_v;
    Math::Vector3D _u;
    Math::Vector3D _v;
    Math::Vector3D _w;
    Math::Vector3D _defocus_disk_u;
    Math::Vector3D _defocus_disk_v;
};
} // namespace RayTracer

#endif /* !CAMERA_HPP_ */
