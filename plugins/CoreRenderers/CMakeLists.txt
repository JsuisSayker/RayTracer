add_library(raytracer_core_rendrers SHARED
    Camera.cpp
    Ray.cpp
    Rectangle3D.cpp
)

target_link_libraries(raytracer_core_rendrers
    raytracer_interfaces
)
