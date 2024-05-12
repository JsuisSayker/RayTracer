add_library(raytracer_flat SHARED
    Flat.cpp
)

target_link_libraries(raytracer_flat
    raytracer_interfaces
)