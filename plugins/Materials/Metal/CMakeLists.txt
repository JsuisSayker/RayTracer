add_library(raytracer_metal SHARED
    Metal.cpp
)

target_link_libraries(raytracer_metal
    raytracer_interfaces
)