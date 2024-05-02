cmake_minimum_required(VERSION 3.10)

project(RaytracerInterfaces
    VERSION 1.0
    DESCRIPTION "Interfaces for the Raytracer project"
    LANGUAGES CXX
)

add_library(raytracer_interfaces INTERFACE)

target_include_directories(raytracer_interfaces
    INTERFACE include
)
