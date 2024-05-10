/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory() {}

Factory::~Factory() {}

std::shared_ptr<Primitive> Factory::CreatePrimitive(std::string type) {
  if (type == "Sphere")
    return std::make_shared<Sphere>;
  // if (type == "Plane")
  //     return std::make_shared<Plane>;
  // if (type == "Triangle")
  //     return std::make_shared<Triangle>;
  // if (type == "Square")
  //     return std::make_shared<Square>;
  // if (type == "Cylinder")
  //     return std::make_shared<Cylinder>;
  // if (type == "Cone")
  //     return std::make_shared<Cone>;
  // if (type == "Torus")
  //     return std::make_shared<Torus>;
  // if (type == "Cube")
  //     return std::make_shared<Cube>;
  // if (type == "Pyramid")
  //     return std::make_shared<Pyramid>;
  // if (type == "Parallelogram")
  //     return std::make_shared<Parallelogram>;
  // if (type == "Tetrahedron")
  //     return std::make_shared<Tetrahedron>;
  // if (type == "Octahedron")
  //     return std::make_shared<Octahedron>;
  // if (type == "Dodecahedron")
  //     return std::make_shared<Dodecahedron>;
  // if (type == "Icosahedron")
  //     return std::make_shared<Icosahedron>;
  return nullptr;
}