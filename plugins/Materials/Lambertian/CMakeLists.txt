add_library(raytracer_lambertian SHARED
    Lambertian.cpp
)

target_link_libraries(raytracer_lambertian
    raytracer_interfaces
)