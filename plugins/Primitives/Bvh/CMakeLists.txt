add_library(raytracer_bvh SHARED
    Bvh.cpp
)

target_link_libraries(raytracer_bvh
    raytracer_interfaces
)