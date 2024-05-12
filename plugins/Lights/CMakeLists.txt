add_library(raytracer_light SHARED
    Light.cpp
)

target_link_libraries(raytracer_light
    raytracer_interfaces
)

add_subdirectory(DirectionalLight)