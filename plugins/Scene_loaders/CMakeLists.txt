add_library(raytracer_scenes SHARED
    SceneBuilder.cpp
    Scene.cpp
)

target_link_libraries(raytracer_scenes
    raytracer_interfaces
    -lconfig++
)
