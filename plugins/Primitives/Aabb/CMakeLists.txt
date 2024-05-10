add_library(raytracer_aabb SHARED
    Aabb.cpp
)

target_link_libraries(raytracer_aabb
    raytracer_interfaces
)