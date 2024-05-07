/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** LoadFile
*/

#include "LoadFile.hpp"
#include <cstring>

LoadFile::LoadFile(std::string path) {
    libconfig::Config cfg;
    try {
        cfg.readFile(path.c_str());
    } catch (const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
        return;
    } catch (const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        return;
    }

    const libconfig::Setting& root = cfg.getRoot();

    for (int i = 0; i < root.getLength(); ++i) {
        const libconfig::Setting& element = root[i];

        if (element.exists("type")) {
            std::string type;
            element.lookupValue("type", type);
            _actualBuilder = std::make_shared<SceneBuilder>(element);
        }

        if (strcmp(element.getName(), "primitives") == 0)
            _actualBuilder = std::make_shared<SceneBuilder>(element);
    }
}


LoadFile::~LoadFile()
{
}
