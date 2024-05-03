/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** main
*/

#include <Raytracer.hpp>
#include <memory>

void help()
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "\tSCENE_FILE: scene configuration" << std::endl;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        help();
        return 84;
    }
    std::string arg = av[1];
    if (arg == "--help") {
        help();
        return 0;
    }
    std::shared_ptr<RayTracer::Raytracer> raytracer = std::make_shared<RayTracer::Raytracer>();
    return raytracer->run(arg);
}