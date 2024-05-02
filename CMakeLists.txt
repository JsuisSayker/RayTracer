cmake_minimum_required(VERSION 3.10)

project(Raytracer
    VERSION 0.1
    DESCRIPTION "A simple raytracer"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_BUILD_TYPE Debug)  # Set build type to Debug

# Enable AddressSanitizer
# set(CMAKE_CXX_FLAGS
#     "${CMAKE_CXX_FLAGS} -fsanitize=address -fno-omit-frame-pointer")
# set(CMAKE_EXE_LINKER_FLAGS
#     "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address -fno-omit-frame-pointer")

# Add debug flags
if(CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
endif()

add_executable(raytracer app/main.cpp)

add_subdirectory(interface)
add_subdirectory(plugins)

target_link_libraries(raytracer
  raytracer_interfaces
  raytracer_math
  raytracer_primitives
  raytracer_core_rendrers
  raytracer_sphere
)

# # Move .so files out of the build folder
set(DESTINATION ${CMAKE_SOURCE_DIR}/plugins)

add_custom_command(
  TARGET raytracer
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:raytracer> ${CMAKE_SOURCE_DIR})

set(WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/plugins/Primitives/Sphere)
add_custom_command(
  TARGET raytracer
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:raytracer_sphere>
          ${DESTINATION}/raytracer_sphere.so
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
