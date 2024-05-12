add_library(raytracer_primitives SHARED
    APrimitives.cpp
)

target_link_libraries(raytracer_primitives
    raytracer_interfaces
)

add_subdirectory(Sphere)
add_subdirectory(Plane)
add_subdirectory(Cylinder)
add_subdirectory(Cone)
