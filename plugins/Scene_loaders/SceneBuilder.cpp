/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SceneBuilder
*/

#include "SceneBuilder.hpp"
#include <dlfcn.h>

SceneBuilder::SceneBuilder(libconfig::Setting &list) : _scenesLists(list)
{
    loadPlugins();
    for (int i = 0; i < _scenesLists.getLength(); i++) {
        buildObject(_scenesLists[i]);
    }
}

void SceneBuilder::loadPlugins()
{
    std::string path = "./plugins";
    std::string fileWantedExtensions = ".so";

    for (const auto &entryFiles : std::filesystem::directory_iterator(path)) {
        if (entryFiles.path().extension() == fileWantedExtensions) {
            const std::string actualFilePath = entryFiles.path().string();
            auto pluginTypeFunc = SceneType::PRIMITIVE;
            // if (pluginTypeFunc == nullptr)
            //     throw std::runtime_error("Error while loading plugin type");
            if (pluginTypeFunc == SceneType::PRIMITIVE)
                _pathToPlugins.push_back(actualFilePath);
            _pathToPlugins.push_back(actualFilePath);
        }
    }
}

void SceneBuilder::createSphere(libconfig::Setting &setting)
{
    int x, y, z;
    std::string type = setting.lookup("type");
    x = setting.lookup("x");
    y = setting.lookup("y");
    z = setting.lookup("z");
    int r = setting.lookup("r");
    const libconfig::Setting &color = setting.lookup("color");
    int red = color.lookup("r");
    int green = color.lookup("g");
    int blue = color.lookup("b");
    // std::shared_ptr<Materials::Material> mat = std::make_shared<Materials::Material>();
    // std::shared_ptr<IPrimitives> sphere = std::make_shared<RayTracer::Sphere>(
    //     Math::Point3D((double)x, (double)y, (double)z), r, mat);
    // _scene->addPrimitive(sphere);
}

void SceneBuilder::buildObject(libconfig::Setting &setting)
{
    // SceneType type = static_cast<SceneType>(setting["type"]);
    std::string type = setting["type"];
    std::cout << type << std::endl;
}

SceneBuilder::~SceneBuilder() {}
