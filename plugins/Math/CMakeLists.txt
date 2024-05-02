add_library(raytracer_math SHARED
    Point3D.cpp
    Vector3D.cpp
)

target_link_libraries(raytracer_math
    raytracer_interfaces
)
