add_library(raytracer_materials SHARED
    Material.cpp
)

target_link_libraries(raytracer_materials
    raytracer_interfaces
)

add_subdirectory(Lambertian)
add_subdirectory(Metal)
add_subdirectory(Dielectric)

