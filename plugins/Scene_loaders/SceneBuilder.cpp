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
    std::string type;
    bool isSamePrimitive = false;
    // std::string primitiveValue;
    int count = 0;

    if (strcmp(_scenesLists.getName(), "primitives") == 0) {
        for (int i = 0; i < _scenesLists.getLength(); i++) {
            const libconfig::Setting& element = _scenesLists[i];
            for (int j = 0; j < element.getLength(); j++) {
                if (element[j].exists("type")) {
                    element[j].lookupValue("type", type);
                    std::cout << "element VALUE : " << type << std::endl;
                    saveSceneData(_scenesLists[i], type);
                }
                // std::cout << "SceneBuilder : " << _scenesLists[i].getName() << std::endl;
            }
            // saveSceneData(_scenesLists[i]);
        }

    } else {
        for (int i = 0; i < _scenesLists.getLength(); i++) {
            if (strcmp(_scenesLists[i].getName(), "type") == 0) {
                list.lookupValue("type", type);
                std::cout << "type value : " << type << std::endl;
            }
            if (strcmp(_scenesLists[i].getName(), "fieldOfView") == 0) {
                SceneBuilder::CameraElement cameraElement;
                list.lookupValue("fieldOfView", cameraElement.fov);
                std::cout << "type value : " << cameraElement.fov << std::endl;
            }
            std::cout << "SceneBuilder : " << _scenesLists[i].getName() << std::endl;
            saveSceneData(_scenesLists[i], type);
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

void SceneBuilder::saveCameraData(const libconfig::Setting &element)
{
    if (strcmp(element.getName(), "resolution") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting& resolutionElement = element;
            std::cout << "resolutionElement : " << resolutionElement[j].getName() << std::endl;
            if (strcmp(resolutionElement[j].getName(), "width") == 0) {
                int width;
                SceneBuilder::CameraElement cameraElement;
                element.lookupValue("width", width);
                cameraElement.width = width;
                std::cout << "width value : " << cameraElement.width << std::endl;
            }
            if (strcmp(resolutionElement[j].getName(), "height") == 0) {
                int height;
                SceneBuilder::CameraElement cameraElement;
                element.lookupValue("height", height);
                cameraElement.height = height;
                std::cout << "height value : " << cameraElement.height << std::endl;
            }
        }
    }
    if (strcmp(element.getName(), "position") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting& positionElement = element;
            std::cout << "positionElement : " << positionElement[j].getName() << std::endl;
            if (strcmp(positionElement[j].getName(), "x") == 0) {
                int x;
                SceneBuilder::CameraElement cameraElement;
                element.lookupValue("x", x);
                cameraElement.position.x = x;
                std::cout << "x value : " << cameraElement.position.x << std::endl;
            }
            if (strcmp(positionElement[j].getName(), "y") == 0) {
                int y;
                SceneBuilder::CameraElement cameraElement;
                element.lookupValue("y", y);
                cameraElement.position.y = y;
                std::cout << "y value : " << cameraElement.position.y << std::endl;
            }
            if (strcmp(positionElement[j].getName(), "z") == 0) {
                int z;
                SceneBuilder::CameraElement cameraElement;
                element.lookupValue("z", z);
                cameraElement.position.z = z;
                std::cout << "z value : " << cameraElement.position.z << std::endl;
            }
        }
    }
    if (strcmp(element.getName(), "rotation") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting& rotationElement = element;
            std::cout << "rotationElement : " << rotationElement[j].getName() << std::endl;
            if (strcmp(rotationElement[j].getName(), "x") == 0) {
                int x;
                SceneBuilder::CameraElement cameraElement;
                element.lookupValue("x", x);
                cameraElement.rotationX = x;
                std::cout << "x value : " << cameraElement.rotationX << std::endl;
            }
            if (strcmp(rotationElement[j].getName(), "y") == 0) {
                int y;
                SceneBuilder::CameraElement cameraElement;
                element.lookupValue("y", y);
                cameraElement.rotationY = y;
                std::cout << "y value : " << cameraElement.rotationY << std::endl;
            }
            if (strcmp(rotationElement[j].getName(), "z") == 0) {
                int z;
                SceneBuilder::CameraElement cameraElement;
                element.lookupValue("z", z);
                cameraElement.rotationZ = z;
                std::cout << "z value : " << cameraElement.rotationZ << std::endl;
            }
        }
    }
}

void SceneBuilder::saveSphereData(const libconfig::Setting &element)
{
    SceneBuilder::SphereElement sphereElement;

    for (int i = 0; i < element.getLength(); i++) {
        const libconfig::Setting& sphereElementInFile = element[i];
        std::cout << "sphereEllllllllllllllllllllll len : " << element.getLength() << std::endl;
        for (int j = 0; sphereElementInFile.getLength(); j++) {
            const libconfig::Setting& nestedSphereElement = sphereElementInFile[j];
            if (strcmp(nestedSphereElement.getName(), "x") == 0) {
                nestedSphereElement.lookupValue("x", sphereElement.position.x);
                std::cout << "x value in sphere: " << sphereElement.position.x << std::endl;
            }
            if (strcmp(nestedSphereElement.getName(), "y") == 0) {
                nestedSphereElement.lookupValue("y", sphereElement.position.y);
                std::cout << "y value in sphere: " << sphereElement.position.y << std::endl;
            }
            if (strcmp(nestedSphereElement.getName(), "z") == 0) {
                nestedSphereElement.lookupValue("z", sphereElement.position.z);
                std::cout << "z value in sphere: " << sphereElement.position.z << std::endl;
            }
            if (strcmp(nestedSphereElement.getName(), "r") == 0) {
                nestedSphereElement.lookupValue("r", sphereElement.radius);
                std::cout << "radius value in sphere: " << sphereElement.radius << std::endl;
            }
            if (strcmp(nestedSphereElement.getName(), "color") == 0) {

                const libconfig::Setting& color = nestedSphereElement;
                std::cout << "color len : " << color.getLength() << std::endl;
                for (int k = 0; k < color.getLength(); k++) {
                    if (strcmp(color[k].getName(), "r") == 0) {
                        color.lookupValue("r", sphereElement.colorValues.r);
                        std::cout << "r value in sphere: " << sphereElement.colorValues.r << std::endl;
                    }
                    if (strcmp(color[k].getName(), "g") == 0) {
                        color.lookupValue("g", sphereElement.colorValues.g);
                        std::cout << "g value in sphere: " << sphereElement.colorValues.g << std::endl;
                    }
                    if (strcmp(color[k].getName(), "b") == 0) {
                        color.lookupValue("b", sphereElement.colorValues.b);
                        std::cout << "b value in sphere: " << sphereElement.colorValues.b << std::endl;
                    }
                }
            }
        }
        _spheresList.push_back(sphereElement);
    }
}

void SceneBuilder::saveSceneData(const libconfig::Setting &element, std::string type)
{
    if (type == "Camera")
        saveCameraData(element);
    try {
        if (type == "Sphere")
            saveSphereData(element);
    } catch (const libconfig::SettingNotFoundException &e) {
        std::cerr << "Error at " << e.getPath() << std::endl;
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
