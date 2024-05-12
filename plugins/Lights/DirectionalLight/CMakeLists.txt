add_library(raytracer_directionallight SHARED
    Directionallight.cpp
)

target_link_libraries(raytracer_directionallight
    raytracer_interfaces
)