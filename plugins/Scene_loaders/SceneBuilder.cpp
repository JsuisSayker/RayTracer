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
    std::string type;
    int count = 0;

    if (strcmp(_scenesLists.getName(), "primitives") == 0) {
        for (int i = 0; i < _scenesLists.getLength(); i++) {
            const libconfig::Setting& element = _scenesLists[i];
            for (int j = 0; j < element.getLength(); j++) {
                if (element[j].exists("type")) {
                    element[j].lookupValue("type", type);
                    std::cout << "element VALUE : " << type << std::endl;
                    _typeList.push_back(type);
                    if (_typeList.size() > 1) {
                        if (_typeList[count] == _typeList[count + 1]) {
                            count += 1;
                        } else
                            count = 0;
                    }
                    saveSceneData(_scenesLists[i], type, count);

                }
            }
        }

    } else {
        for (int i = 0; i < _scenesLists.getLength(); i++) {
            if (strcmp(_scenesLists[i].getName(), "type") == 0) {
                list.lookupValue("type", type);
            }
            if (strcmp(_scenesLists[i].getName(), "fieldOfView") == 0) {
                SceneBuilder::CameraElement cameraElement;
                list.lookupValue("fieldOfView", cameraElement.fov);
                std::cout << "type value : " << cameraElement.fov << std::endl;
            }
            if (strcmp(_scenesLists[i].getName(), "ambient") == 0) {
                SceneBuilder::LightElement lightElement;
                list.lookupValue("ambient", lightElement.ambient);
                std::cout << "type value : " << lightElement.ambient << std::endl;
            }
            if (strcmp(_scenesLists[i].getName(), "diffuse") == 0) {
                SceneBuilder::LightElement lightElement;
                list.lookupValue("diffuse", lightElement.diffuse);
                std::cout << "type value : " << lightElement.diffuse << std::endl;
            }
            saveSceneData(_scenesLists[i], type, count);
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
    SceneBuilder::CameraElement cameraElement;

    if (strcmp(element.getName(), "resolution") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting& resolutionElement = element;
            if (strcmp(resolutionElement[j].getName(), "width") == 0) {
                element.lookupValue("width", cameraElement.width);
                std::cout << "width value : " << cameraElement.width << std::endl;
            }
            if (strcmp(resolutionElement[j].getName(), "height") == 0) {
                element.lookupValue("height", cameraElement.height);
                std::cout << "height value : " << cameraElement.height << std::endl;
            }
        }
    }
    if (strcmp(element.getName(), "position") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting& positionElement = element;
            if (strcmp(positionElement[j].getName(), "x") == 0) {
                element.lookupValue("x", cameraElement.position.x);
                std::cout << "x value : " << cameraElement.position.x << std::endl;
            }
            if (strcmp(positionElement[j].getName(), "y") == 0) {
                element.lookupValue("y", cameraElement.position.y);
                std::cout << "y value : " << cameraElement.position.y << std::endl;
            }
            if (strcmp(positionElement[j].getName(), "z") == 0) {
                element.lookupValue("z", cameraElement.position.z);
                std::cout << "z value : " << cameraElement.position.z << std::endl;
            }
        }
    }
    if (strcmp(element.getName(), "rotation") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting& rotationElement = element;
            if (strcmp(rotationElement[j].getName(), "x") == 0) {
                element.lookupValue("x", cameraElement.rotationX);
                std::cout << "x value : " << cameraElement.rotationX << std::endl;
            }
            if (strcmp(rotationElement[j].getName(), "y") == 0) {
                element.lookupValue("y", cameraElement.rotationY);
                std::cout << "y value : " << cameraElement.rotationY << std::endl;
            }
            if (strcmp(rotationElement[j].getName(), "z") == 0) {
                element.lookupValue("z", cameraElement.rotationZ);
                std::cout << "z value : " << cameraElement.rotationZ << std::endl;
            }
        }
    }
}

void SceneBuilder::saveSphereData(const libconfig::Setting &element, int start)
{
    SceneBuilder::SphereElement sphereElement;
    try {
        for (int i = start; i < element.getLength(); i++) {
            const libconfig::Setting& sphereElementInFile = element[i];
            for (int j = 0; sphereElementInFile.getLength(); j++) {
                const libconfig::Setting& nestedSphereElement = sphereElementInFile[j];
                if (strcmp(nestedSphereElement.getName(), "x") == 0) {
                    sphereElementInFile.lookupValue("x", sphereElement.position.x);
                    std::cout << "x value in sphere: " << sphereElement.position.x << std::endl;
                }
                if (strcmp(nestedSphereElement.getName(), "y") == 0) {
                    sphereElementInFile.lookupValue("y", sphereElement.position.y);
                    std::cout << "y value in sphere: " << sphereElement.position.y << std::endl;
                }
                if (strcmp(nestedSphereElement.getName(), "z") == 0) {
                    sphereElementInFile.lookupValue("z", sphereElement.position.z);
                    std::cout << "z value in sphere: " << sphereElement.position.z << std::endl;
                }
                if (strcmp(nestedSphereElement.getName(), "r") == 0) {
                    sphereElementInFile.lookupValue("r", sphereElement.radius);
                    std::cout << "radius value in sphere: " << sphereElement.radius << std::endl;
                }
                if (strcmp(nestedSphereElement.getName(), "color") == 0) {

                    const libconfig::Setting& color = nestedSphereElement;
                    for (int k = 0; k < color.getLength(); k++) {
                        if (strcmp(color[k].getName(), "r") == 0) {
                            nestedSphereElement.lookupValue("r", sphereElement.colorValues.r);
                            std::cout << "r value in sphere: " << sphereElement.colorValues.r << std::endl;
                        }
                        if (strcmp(color[k].getName(), "g") == 0) {
                            nestedSphereElement.lookupValue("g", sphereElement.colorValues.g);
                            std::cout << "g value in sphere: " << sphereElement.colorValues.g << std::endl;
                        }
                        if (strcmp(color[k].getName(), "b") == 0) {
                            nestedSphereElement.lookupValue("b", sphereElement.colorValues.b);
                            std::cout << "b value in sphere: " << sphereElement.colorValues.b << std::endl;
                        }
                    }
                }
            }
            _spheresList.push_back(sphereElement);
        }
    } catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

void SceneBuilder::savePlaneData(const libconfig::Setting &element, int start)
{
    SceneBuilder::PlaneElement planeElement;
    try {
        for (int i = start; i < element.getLength(); i++) {
            const libconfig::Setting& planeElementInFile = element[i];
            for (int j = 0; planeElementInFile.getLength(); j++) {
                const libconfig::Setting& nestedPlaneElement = planeElementInFile[j];
                if (strcmp(nestedPlaneElement.getName(), "axis") == 0) {
                    planeElementInFile.lookupValue("axis", planeElement.axis);
                    std::cout << "axis value in plane: " << planeElement.axis << std::endl;
                }
                if (strcmp(nestedPlaneElement.getName(), "position") == 0) {
                    planeElementInFile.lookupValue("position", planeElement.position);
                    std::cout << "position value in plane: " << planeElement.position << std::endl;
                }
                if (strcmp(nestedPlaneElement.getName(), "color") == 0) {
                    const libconfig::Setting& color = nestedPlaneElement;
                    for (int k = 0; k < color.getLength(); k++) {
                        if (strcmp(color[k].getName(), "r") == 0) {
                            nestedPlaneElement.lookupValue("r", planeElement.colorValues.r);
                            std::cout << "r value in plane: " << planeElement.colorValues.r << std::endl;
                        }
                        if (strcmp(color[k].getName(), "g") == 0) {
                            nestedPlaneElement.lookupValue("g", planeElement.colorValues.g);
                            std::cout << "g value in plane: " << planeElement.colorValues.g << std::endl;
                        }
                        if (strcmp(color[k].getName(), "b") == 0) {
                            nestedPlaneElement.lookupValue("b", planeElement.colorValues.b);
                            std::cout << "b value in plane: " << planeElement.colorValues.b << std::endl;
                        }
                    }
                }
            }
            _planeList.push_back(planeElement);
        }
    }
    catch (const libconfig::SettingNotFoundException &e) {
        return;
    }
}

void SceneBuilder::saveLightData(const libconfig::Setting &element)
{
    SceneBuilder::LightElement lightElement;
    if (strcmp(element.getName(), "point") == 0) {
        for (int i = 0; i < element.getLength(); i++) {
            const libconfig::Setting& pointElement = element[i];
            for (int j = 0; j < pointElement.getLength(); j++) {
                const libconfig::Setting& nestedPointElement = pointElement[j];
                if (strcmp(nestedPointElement.getName(), "x") == 0) {
                    pointElement.lookupValue("x", lightElement.points.x);
                    std::cout << "x value in light: " << lightElement.points.x << std::endl;
                }
                if (strcmp(nestedPointElement.getName(), "y") == 0) {
                    pointElement.lookupValue("y", lightElement.points.y);
                    std::cout << "y value in light: " << lightElement.points.y << std::endl;
                }
                if (strcmp(nestedPointElement.getName(), "z") == 0) {
                    pointElement.lookupValue("z", lightElement.points.z);
                    std::cout << "z value in light: " << lightElement.points.z << std::endl;
                }
            }
            _lightList.push_back(lightElement);
        }
    }
}

void SceneBuilder::saveSceneData(const libconfig::Setting &element, std::string type, int count)
{
    if (type == "Camera")
        saveCameraData(element);
    if (type == "Sphere")
        saveSphereData(element, count);
    if (type == "Plane")
        savePlaneData(element, count);
    if (type == "Lights")
        saveLightData(element);

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
