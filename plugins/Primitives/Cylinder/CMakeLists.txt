add_library(raytracer_cylinder SHARED
    Cylinder.cpp
)

target_link_libraries(raytracer_cylinder
    raytracer_interfaces
)