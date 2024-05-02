add_library(raytracer_sphere SHARED
    Sphere.cpp
)

target_link_libraries(raytracer_sphere
    raytracer_interfaces
)