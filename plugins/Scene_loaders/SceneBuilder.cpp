/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SceneBuilder
*/

#include "SceneBuilder.hpp"
#include <dlfcn.h>
#include <iostream>
#include <cstring>

SceneBuilder::SceneBuilder(const libconfig::Setting &list) : _scenesLists(list)
{
    _scene = std::make_shared<Scene>();
    // loadPlugins();

    if (strcmp(_scenesLists.getName(), "primitives") == 0) {
        // std::cout << "primitives exist" << std::endl;
        for (int i = 0; i < _scenesLists.getLength(); i++) {
            const libconfig::Setting& element = _scenesLists[i];
            // std::cout << "element IN SCENEBUILDER: " << element.getName() << std::endl;
            for (int j = 0; j < element.getLength(); j++) {
                if (element[j].exists("type")) {
                    // std::cout << "je suis la" << std::endl;
                    std::string type;
                    element[j].lookupValue("type", type);
                    std::cout << "element VALUE : " << type << std::endl;
                    saveSceneData(_scenesLists[i]);
                }
            }
        }

    } else {
        for (int i = 0; i < _scenesLists.getLength(); i++) {
            // std::cout << "SceneBuilder : " << _scenesLists[i].getName() << std::endl;
            if (strcmp(_scenesLists[i].getName(), "type") == 0) {
                // std::cout << "it exists" << std::endl;
                std::string type;
                list.lookupValue("type", type);
                std::cout << "type value : " << type << std::endl;
                saveSceneData(_scenesLists[i]);
            }
        }
    }
}

void SceneBuilder::loadPlugins()
{
    std::string path = "./plugins";
    std::string fileWantedExtensions = ".so";

    for (const auto &entryFiles : std::filesystem::directory_iterator(path)) {
        if (entryFiles.path().extension() == fileWantedExtensions) {
            const std::string actualFilePath = entryFiles.path().string();
            auto pluginTypeFunc = SceneType::PRIMITIVE; // here we need to load the function from the plugin
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
    const libconfig::Setting& color = setting.lookup("color");
    int red = color.lookup("r");
    int green = color.lookup("g");
    int blue = color.lookup("b");
    std::shared_ptr<IPrimitives> sphere = std::make_shared<RayTracer::Sphere>(Math::Point3D((double)x, (double)y, (double)z), r);
    _scene->addPrimitive(sphere);
}


void SceneBuilder::saveSceneData(const libconfig::Setting &list)
{
    for (int i = 0; i < list.getLength(); i++) {
        const libconfig::Setting& element = list[i];
        std::cout << "element IN SCENEBUILDER: " << element.getName() << std::endl;
    }
}

void SceneBuilder::buildObject(libconfig::Setting &setting)
{

}


std::shared_ptr<IScene> SceneBuilder::getScene()
{
    return _scene;
}


SceneBuilder::~SceneBuilder()
{
}
