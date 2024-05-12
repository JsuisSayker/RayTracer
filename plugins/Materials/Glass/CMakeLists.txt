add_library(raytracer_glass SHARED
    Glass.cpp
)

target_link_libraries(raytracer_glass
    raytracer_interfaces
)