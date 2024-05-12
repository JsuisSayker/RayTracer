/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SceneBuilder
*/

#include <SceneBuilder.hpp>
#include <cstring>
#include <dlfcn.h>
#include <iostream>

SceneBuilder::SceneBuilder(const libconfig::Setting &list, Scene &scene, RayTracer::Camera &cam)
    : _scenesLists(list)
{
    // scene = std::make_shared<IScene>();
    std::string type;
    int index = 0;
    completeFile data;
    SceneBuilder::LightElement lightElement;

    if (strcmp(_scenesLists.getName(), "primitives") == 0) {
        for (int i = 0; i < _scenesLists.getLength(); i++) {
            const libconfig::Setting &element = _scenesLists[i];
            for (int j = 0; j < element.getLength(); j++) {
                if (element[j].exists("type")) {
                    element[j].lookupValue("type", type);
                    _typeList.push_back(type);
                    if (_typeList.size() > 1) {
                        if (_typeList[index] == _typeList[index + 1]) {
                            index += 1;
                        } else
                            index = 0;
                    }
                    saveSceneData(_scenesLists[i], type, index, data, lightElement, scene, cam);
                }
            }
        }

    } else {
        for (int i = 0; i < _scenesLists.getLength(); i++) {
            if (strcmp(_scenesLists[i].getName(), "type") == 0) {
                list.lookupValue("type", type);
            }
            if (strcmp(_scenesLists[i].getName(), "fieldOfView") == 0) {
                list.lookupValue("fieldOfView", data._camera.fov);
            }
            if (strcmp(_scenesLists[i].getName(), "ambient") == 0) {
                list.lookupValue("ambient", lightElement.ambient);
            }
            if (strcmp(_scenesLists[i].getName(), "diffuse") == 0) {
                list.lookupValue("diffuse", lightElement.diffuse);
            }
            saveSceneData(_scenesLists[i], type, index, data, lightElement, scene, cam);
        }
    }
    std::cout << "at the end" << std::endl;
    // cam.render(scene);
}

std::shared_ptr<Material::Material>
SceneBuilder::createMetalMaterial(UNUSED completeFile &data,
                                  UNUSED SceneBuilder::ActualObject actualObject, UNUSED int index)
{
    Math::Vector3D albedo = random_vector(0.5, 1);
    double fuzz = random_double(0, 0.5);
    return std::make_shared<Material::Metal>(albedo, fuzz);
}

std::shared_ptr<Material::Material> SceneBuilder::createLambertianMaterial(
    UNUSED completeFile &data, UNUSED SceneBuilder::ActualObject actualObject, UNUSED int index)
{
    Math::Vector3D albedo = random_vector() * random_vector();
    return std::make_shared<Material::Lambertian>(albedo);
}

std::shared_ptr<Material::Material> SceneBuilder::createDielectricMaterial(
    UNUSED completeFile &data, UNUSED SceneBuilder::ActualObject actualObject, UNUSED int index)
{
    return std::make_shared<Material::Dielectric>(1.5);
}

std::shared_ptr<Material::Material>
SceneBuilder::createFlatMaterial(completeFile &data, SceneBuilder::ActualObject actualObject,
                                 int index)
{
    Math::Vector3D albedo;
    if (actualObject == SceneBuilder::ActualObject::SPHERE) {
        albedo = Math::Vector3D(data._spheresList[index].colorValues.r,
                                data._spheresList[index].colorValues.g,
                                data._spheresList[index].colorValues.b);
    }
    if (actualObject == SceneBuilder::ActualObject::PLANE) {
        albedo = Math::Vector3D(data._planeList[index].colorValues.r,
                                data._planeList[index].colorValues.g,
                                data._planeList[index].colorValues.b);
    }
    return std::make_shared<Material::Lambertian>(albedo);
}

void SceneBuilder::createCamera(completeFile &data, UNUSED int index, Scene &scene,
                                RayTracer::Camera &cam)
{
    // std::shared_ptr<ICamera> camera = std::make_shared<RayTracer::Camera>();
    cam.setResolution(data._camera.width, data._camera.height);
    cam.setLookFrom(data._camera.position.x, data._camera.position.y, data._camera.position.z);
    cam.setFov(data._camera.fov);
    cam.setDefaultValues();
    // scene.addCamera(cam);
    std::cout << "MAGNIFIQUE" << std::endl;
}

void SceneBuilder::createSphere(completeFile &data, int index, Scene &scene,
                                UNUSED RayTracer::Camera &cam)
{
    std::shared_ptr<Material::Material> actualMaterial = _material.at(
        data._spheresList[index].material)(data, SceneBuilder::ActualObject::SPHERE, index);
    std::shared_ptr<IPrimitives> sphere = std::make_shared<RayTracer::Sphere>(
        Math::Point3D((double)data._spheresList[index].position.x,
                      (double)data._spheresList[index].position.y,
                      (double)data._spheresList[index].position.z),
        data._spheresList[index].radius, actualMaterial);
    scene.addPrimitive(sphere);
    std::cout << "BOUILLANT" << std::endl;
}

void SceneBuilder::createPlane(completeFile &data, int index, Scene &scene,
                               UNUSED RayTracer::Camera &cam)
{
    std::shared_ptr<Material::Material> actualMaterial = _material.at(
        data._planeList[index].material)(data, SceneBuilder::ActualObject::PLANE, index);
    std::shared_ptr<IPrimitives> plane = std::make_shared<RayTracer::Plane>(
        data._planeList[index].axis[0], data._planeList[index].position, actualMaterial);
    scene.addPrimitive(plane);
    std::cout << "LEGENDAIRE" << std::endl;
}

void SceneBuilder::createLight(completeFile &data, int index, UNUSED Scene &scene,
                               UNUSED RayTracer::Camera &cam)
{
    // std::shared_ptr<ILight> light = std::make_shared<RayTracer::Light>(
    //     data._lightList[index].ambient, data._lightList[index].diffuse,
    //     Math::Point3D(data._lightList[index].points.x,
    //         data._lightList[index].points.y,
    //         data._lightList[index].points.z)
    // );
    // scene->addLight(light);
    std::cout << "MYTHIQUE" << std::endl;
}

void SceneBuilder::saveCameraData(const libconfig::Setting &element, completeFile &data) const
{
    if (strcmp(element.getName(), "resolution") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting &resolutionElement = element;
            if (strcmp(resolutionElement[j].getName(), "width") == 0) {
                element.lookupValue("width", data._camera.width);
            }
            if (strcmp(resolutionElement[j].getName(), "height") == 0) {
                element.lookupValue("height", data._camera.height);
            }
        }
    }
    if (strcmp(element.getName(), "position") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting &positionElement = element;
            if (strcmp(positionElement[j].getName(), "x") == 0) {
                element.lookupValue("x", data._camera.position.x);
            }
            if (strcmp(positionElement[j].getName(), "y") == 0) {
                element.lookupValue("y", data._camera.position.y);
            }
            if (strcmp(positionElement[j].getName(), "z") == 0) {
                element.lookupValue("z", data._camera.position.z);
            }
        }
    }
    if (strcmp(element.getName(), "rotation") == 0) {
        for (int j = 0; j < element.getLength(); j++) {
            const libconfig::Setting &rotationElement = element;
            if (strcmp(rotationElement[j].getName(), "x") == 0) {
                element.lookupValue("x", data._camera.rotationX);
            }
            if (strcmp(rotationElement[j].getName(), "y") == 0) {
                element.lookupValue("y", data._camera.rotationY);
            }
            if (strcmp(rotationElement[j].getName(), "z") == 0) {
                element.lookupValue("z", data._camera.rotationZ);
            }
        }
    }
}

void SceneBuilder::saveSphereData(const libconfig::Setting &element, int start,
                                  completeFile &data) const
{
    SceneBuilder::SphereElement sphereElement;
    for (int i = start; i < element.getLength(); i++) {
        const libconfig::Setting &sphereElementInFile = element[i];
        for (int j = 0; j < sphereElementInFile.getLength(); j++) {
            const libconfig::Setting &nestedSphereElement = sphereElementInFile[j];
            if (strcmp(nestedSphereElement.getName(), "x") == 0) {
                sphereElementInFile.lookupValue("x", sphereElement.position.x);
            }
            if (strcmp(nestedSphereElement.getName(), "y") == 0) {
                sphereElementInFile.lookupValue("y", sphereElement.position.y);
            }
            if (strcmp(nestedSphereElement.getName(), "z") == 0) {
                sphereElementInFile.lookupValue("z", sphereElement.position.z);
            }
            if (strcmp(nestedSphereElement.getName(), "r") == 0) {
                sphereElementInFile.lookupValue("r", sphereElement.radius);
            }
            if (strcmp(nestedSphereElement.getName(), "material") == 0) {
                sphereElementInFile.lookupValue("material", sphereElement.material);
            }
            if (strcmp(nestedSphereElement.getName(), "color") == 0) {
                const libconfig::Setting &color = nestedSphereElement;
                for (int k = 0; k < color.getLength(); k++) {
                    if (strcmp(color[k].getName(), "r") == 0) {
                        nestedSphereElement.lookupValue("r", sphereElement.colorValues.r);
                    }
                    if (strcmp(color[k].getName(), "g") == 0) {
                        nestedSphereElement.lookupValue("g", sphereElement.colorValues.g);
                    }
                    if (strcmp(color[k].getName(), "b") == 0) {
                        nestedSphereElement.lookupValue("b", sphereElement.colorValues.b);
                    }
                }
            }
        }
        data._spheresList.push_back(sphereElement);
    }
}

void SceneBuilder::savePlaneData(const libconfig::Setting &element, int start,
                                 completeFile &data) const
{
    SceneBuilder::PlaneElement planeElement;
    for (int i = start; i < element.getLength(); i++) {
        const libconfig::Setting &planeElementInFile = element[i];
        for (int j = 0; j < planeElementInFile.getLength(); j++) {
            const libconfig::Setting &nestedPlaneElement = planeElementInFile[j];
            if (strcmp(nestedPlaneElement.getName(), "axis") == 0) {
                planeElementInFile.lookupValue("axis", planeElement.axis);
            }
            if (strcmp(nestedPlaneElement.getName(), "position") == 0) {
                planeElementInFile.lookupValue("position", planeElement.position);
            }
            if (strcmp(nestedPlaneElement.getName(), "material") == 0) {
                planeElementInFile.lookupValue("material", planeElement.material);
            }
            if (strcmp(nestedPlaneElement.getName(), "color") == 0) {
                const libconfig::Setting &color = nestedPlaneElement;
                for (int k = 0; k < color.getLength(); k++) {
                    if (strcmp(color[k].getName(), "r") == 0) {
                        nestedPlaneElement.lookupValue("r", planeElement.colorValues.r);
                    }
                    if (strcmp(color[k].getName(), "g") == 0) {
                        nestedPlaneElement.lookupValue("g", planeElement.colorValues.g);
                    }
                    if (strcmp(color[k].getName(), "b") == 0) {
                        nestedPlaneElement.lookupValue("b", planeElement.colorValues.b);
                    }
                }
            }
        }
        data._planeList.push_back(planeElement);
    }
}

void SceneBuilder::saveLightData(const libconfig::Setting &element, completeFile &data,
                                 SceneBuilder::LightElement lightElement) const
{
    if (strcmp(element.getName(), "point") == 0) {
        for (int i = 0; i < element.getLength(); i++) {
            const libconfig::Setting &pointElement = element[i];
            for (int j = 0; j < pointElement.getLength(); j++) {
                const libconfig::Setting &nestedPointElement = pointElement[j];
                if (strcmp(nestedPointElement.getName(), "x") == 0) {
                    pointElement.lookupValue("x", lightElement.points.x);
                }
                if (strcmp(nestedPointElement.getName(), "y") == 0) {
                    pointElement.lookupValue("y", lightElement.points.y);
                }
                if (strcmp(nestedPointElement.getName(), "z") == 0) {
                    pointElement.lookupValue("z", lightElement.points.z);
                }
            }
            data._lightList.push_back(lightElement);
        }
    }
}

void SceneBuilder::saveSceneData(const libconfig::Setting &element, std::string type, int index,
                                 completeFile &data, SceneBuilder::LightElement lightElement,
                                 Scene &scene, RayTracer::Camera &cam) const
{
    if (type == "Camera") {
        saveCameraData(element, data);
        if (strcmp(element.getName(), "fieldOfView") == 0)
            buildObject(type, data, index, scene, cam);
    }
    if (type == "Sphere") {
        saveSphereData(element, index, data);
        buildObject(type, data, index, scene, cam);
    }
    if (type == "Plane") {
        savePlaneData(element, index, data);
        buildObject(type, data, index, scene, cam);
    }
    if (type == "Lights") {
        saveLightData(element, data, lightElement);
        buildObject(type, data, index, scene, cam);
    }
}

void SceneBuilder::buildObject(std::string type, completeFile data, int index, Scene &scene,
                               RayTracer::Camera &cam) const
{
    _object.at(type)(data, index, scene, cam);
}

// std::shared_ptr<IScene> SceneBuilder::getScene()
// {
//     return scene;
// }

SceneBuilder::~SceneBuilder() {}
