/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Camera
*/

#include <Camera.hpp>

Math::Vector3D ray_color(const RayTracer::Ray& r, const Scene& world) {
    RayTracer::Primitives_record rec;
    if (world.hits(r, 0, std::numeric_limits<double>::infinity(), rec)) {
        return Math::Vector3D(255, 0, 0);
    }
    return Math::Vector3D(0, 0, 0);
}

RayTracer::Camera::Camera()
{
    _origin = Math::Point3D(0, 0, 0);
    _screen = Rectangle3D();
    _screen.translate(Math::Vector3D(-0.5, -0.5, -0.5));
}

RayTracer::Camera::~Camera()
{
}

void write_color(std::ostream &out, const Math::Vector3D& color)
{
    int ir = static_cast<int>(color.x);
    int ig = static_cast<int>(color.y);
    int ib = static_cast<int>(color.z);
    out << ir << ' ' << ig << ' ' << ib << '\n';
}

RayTracer::Ray RayTracer::Camera::ray(double u, double v) const
{
    return RayTracer::Ray(_origin, _screen.pointAt(u, v) - _origin);
}

void RayTracer::Camera::render(const Scene& world) {
    this->initialize();

    std::ofstream output_file("output.ppm");
    output_file << "P3\n" << _image_width << ' ' << _image_height << "\n255\n";
    for (int y = 0; y < _image_height; y += 1) {
        for (int x = 0; x < _image_width; x += 1) {
            double u = x * _pixel_delta_u;
            double v = y * _pixel_delta_v;
            RayTracer::Ray r = this->ray(u, v);
            write_color(output_file, ray_color(r, world));
        }
    }
}

void RayTracer::Camera::initialize() {
    _image_height = int(_image_width / _aspect_ratio);
    _image_height = (_image_height < 1) ? 1 : _image_height;

    double viewport_height = 2.0;
    double viewport_width = viewport_height * (double(_image_width)/_image_height);

    Math::Vector3D viewport_u = Math::Vector3D(viewport_width, 0, 0);
    Math::Vector3D viewport_v = Math::Vector3D(0, -viewport_height, 0);
    this->_screen.origin = Math::Point3D(-(viewport_width/(double)2), (viewport_height/(double)2), -0.5);
    this->_screen.left_side = Math::Vector3D(0, viewport_height, 0);
    this->_screen.bottom_side = Math::Vector3D(viewport_width,0, 0);

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    _pixel_delta_u = viewport_u.x / _image_width;
    _pixel_delta_v = viewport_v.y / _image_height;
}