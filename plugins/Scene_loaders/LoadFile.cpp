/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** LoadFile
*/

#include <LoadFile.hpp>
#include <cstring>

LoadFile::LoadFile(std::string path, Scene &scene, RayTracer::Camera &cam)
{
    libconfig::Config cfg;
    try {
        cfg.readFile(path.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine() << " - "
                  << pex.getError() << std::endl;
        return;
    }

    const libconfig::Setting &root = cfg.getRoot();

    for (int i = 0; i < root.getLength(); ++i) {
        const libconfig::Setting &element = root[i];

        if (element.exists("type")) {
            std::string type;
            element.lookupValue("type", type);
            _actualBuilder = std::make_shared<SceneBuilder>(element, scene, cam);
        }

        if (strcmp(element.getName(), "primitives") == 0)
            _actualBuilder = std::make_shared<SceneBuilder>(element, scene, cam);
    }
    cam.render_scene(scene);
}

LoadFile::~LoadFile() {}
