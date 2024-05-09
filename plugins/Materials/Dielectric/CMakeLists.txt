add_library(raytracer_dielectric SHARED
    Dielectric.cpp
)

target_link_libraries(raytracer_dielectric
    raytracer_interfaces
)