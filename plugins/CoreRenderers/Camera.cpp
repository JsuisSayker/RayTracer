/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** Camera
*/

#include <Camera.hpp>
#include <Flat.hpp>

RayTracer::Camera::Camera()
{
    _origin = Math::Point3D(0, 0, 0);
    _screen = Rectangle3D();
}

RayTracer::Camera::~Camera() {}

double linear_to_gamma(double linear_component)
{
    if (linear_component > 0)
        return sqrt(linear_component);

    return 0;
}

void write_color(std::ostream &out, const Math::Vector3D &color)
{
    double r = color.x;
    double g = color.y;
    double b = color.z;

    // Apply a linear to gamma transform for gamma 2
    r = linear_to_gamma(r);
    g = linear_to_gamma(g);
    b = linear_to_gamma(b);

    // Translate the [0,1] component values to the byte range [0,255].
    static const Math::Interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // Write out the pixel color components.
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

Math::Vector3D light_color(const Scene &world, Material::Flat &rec, const Math::Vector3D &ray_color_value)
{
    Math::Vector3D directional_light = world._directional_lights.front().get()->_direction;
    double coeff = directional_light.dot(rec.normal);
    return ray_color_value * world._ambient_light * coeff;
}

Math::Vector3D ray_color(const RayTracer::Ray &r, int depth, const Scene &world)
{
    if (depth <= 0)
        return Math::Vector3D(0, 0, 0);
    Material::Flat rec(Math::Vector3D(0, 0, 0));
    if (world.hits(r, Math::Interval(0.001, infinity), rec)) {
        RayTracer::Ray scattered;
        Math::Vector3D attenuation;
        if (rec.mat->scatter(r, rec, attenuation, scattered))
            return light_color(world, rec, attenuation * ray_color(scattered, depth - 1, world));
        return Math::Vector3D(0.0, 0.0, 0.0);
    }

    Math::Vector3D unit_direction = unit_vector(r._direction);
    double a = 0.5 * (unit_direction.y + 1.0);
    return Math::Vector3D(1.0, 1.0, 1.0) * (1.0 - a) + Math::Vector3D(0.5, 0.7, 1.0) * a * world._ambient_light;
}

void RayTracer::Camera::render(const Scene &world)
{
    this->initialize();

    std::ofstream output_file("output.ppm");
    output_file << "P3\n" << _image_width << ' ' << _image_height << "\n255\n";
    for (int y = 0; y < _image_height; y += 1) {
        std::cout << "\rScanlines remaining: " << (_image_height - y) << ' ' << std::flush;
        for (int x = 0; x < _image_width; x += 1) {
            Math::Vector3D pixel_color(0, 0, 0);
            for (int sample = 0; sample < _samples_per_pixel; sample++) {
                RayTracer::Ray r = get_ray(x, y);
                pixel_color += ray_color(r, _max_depth, world);
            }
            write_color(output_file, pixel_color * _pixel_samples_scale);
        }
    }
    output_file.close();
    std::cout << "\rDone.                 " << std::endl;
}

void RayTracer::Camera::initialize()
{
    _image_height = int(_image_width / _aspect_ratio);
    _image_height = (_image_height < 1) ? 1 : _image_height;

    _pixel_samples_scale = 1.0 / _samples_per_pixel;

    _origin = _lookfrom;

    double theta = degrees_to_radians(_vfov);
    double h = tan(theta / 2);
    double viewport_height = 2 * h * _focus_dist;
    double viewport_width = viewport_height * (double(_image_width) / _image_height);

    _w = unit_vector(_lookfrom - _lookat);
    _u = unit_vector(cross(_vup, _w));
    _v = cross(_w, _u);

    Math::Vector3D viewport_u = _u * viewport_width;
    Math::Vector3D viewport_v = (_v * -1) * viewport_height;

    // Calculate the horizontal and vertical delta vectors from pixel to pixel.
    _pixel_delta_u = viewport_u / _image_width;
    _pixel_delta_v = viewport_v / _image_height;

    Math::Point3D viewport_upper_left =
        _origin - (_w * _focus_dist) - viewport_u / 2 - viewport_v / 2;
    Math::Point3D pixel00_loc = viewport_upper_left + (_pixel_delta_u + _pixel_delta_v) * 0.5;

    this->_screen.origin = Math::Point3D(pixel00_loc._x, pixel00_loc._y, pixel00_loc._z);
    this->_screen.left_side = Math::Vector3D(0, viewport_height, 0);
    this->_screen.bottom_side = Math::Vector3D(viewport_width, 0, 0);

    double defocus_radius = _focus_dist * tan(degrees_to_radians(_defocus_angle / 2));
    _defocus_disk_u = _u * defocus_radius;
    _defocus_disk_v = _v * defocus_radius;
}

RayTracer::Ray RayTracer::Camera::get_ray(int x, int y) const
{
    // Construct a camera ray originating from the origin and directed at randomly
    // sampled point around the pixel location i, j.

    Math::Vector3D offset = sample_square();
    Math::Point3D pixel_sample = this->_screen.origin + (_pixel_delta_u * (x + offset.x)) +
                                 (_pixel_delta_v * (y + offset.y));

    Math::Point3D ray_origin = (_defocus_angle <= 0) ? _origin : defocus_disk_sample();
    Math::Vector3D ray_direction = pixel_sample - ray_origin;
    double ray_time = random_double();

    return RayTracer::Ray(ray_origin, ray_direction, ray_time);
}

Math::Vector3D RayTracer::Camera::sample_square() const
{
    // Returns the vector to a random point in the [-.5,-.5]-[+.5,+.5] unit
    // square.
    return Math::Vector3D(random_double() - 0.5, random_double() - 0.5, 0);
}

Math::Point3D RayTracer::Camera::defocus_disk_sample() const
{
    // Returns a random point in the camera defocus disk.
    Math::Vector3D p = random_in_unit_disk();
    return _origin + (_defocus_disk_u * p.x) + (_defocus_disk_v * p.y);
}
