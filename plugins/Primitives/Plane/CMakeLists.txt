add_library(raytracer_plane SHARED
    Plane.cpp
)

target_link_libraries(raytracer_plane
    raytracer_interfaces
)