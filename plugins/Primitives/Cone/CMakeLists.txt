add_library(raytracer_cone SHARED
    Cone.cpp
)

target_link_libraries(raytracer_cone
    raytracer_interfaces
)