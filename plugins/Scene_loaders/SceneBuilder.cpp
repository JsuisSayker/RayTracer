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
                        } else {
                            _typeList.clear();
                            index = 0;
                        }
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
                list.lookupValue("fieldOfView", cam._fov);
            }
            if (strcmp(_scenesLists[i].getName(), "ambient") == 0) {
                list.lookupValue("ambient", scene._ambient_light);
            }
            if (strcmp(_scenesLists[i].getName(), "diffuse") == 0) {
                list.lookupValue("diffuse", lightElement.diffuse);
            }
            saveSceneData(_scenesLists[i], type, index, data, lightElement, scene, cam);
        }
    }
}

std::shared_ptr<Materials::Material>
SceneBuilder::createMetalMaterial(UNUSED completeFile &data,
                                  UNUSED SceneBuilder::ActualObject actualObject, UNUSED int index)
{
    Math::Vector3D albedo = random_vector(0.5, 1);
    double fuzz = random_double(0, 0.5);
    return std::make_shared<Materials::Metal>(albedo, fuzz);
}

std::shared_ptr<Materials::Material> SceneBuilder::createDielectricMaterial(
    UNUSED completeFile &data, UNUSED SceneBuilder::ActualObject actualObject, UNUSED int index)
{
    return std::make_shared<Materials::Glass>(1.5);
}

std::shared_ptr<Materials::Material>
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
    if (actualObject == SceneBuilder::ActualObject::CONE) {
        albedo =
            Math::Vector3D(data._coneList[index].colorValues.r, data._coneList[index].colorValues.g,
                           data._coneList[index].colorValues.b);
    }
    if (actualObject == SceneBuilder::ActualObject::CYLINDER) {
        albedo = Math::Vector3D(data._cylinderList[index].colorValues.r,
                                data._cylinderList[index].colorValues.g,
                                data._cylinderList[index].colorValues.b);
    }
    return std::make_shared<Materials::Flat>(albedo);
}

void SceneBuilder::createCamera(completeFile &data, UNUSED int index, Scene &scene,
                                RayTracer::Camera &cam)
{
    cam.setResolution(data._camera.width, data._camera.height);
    cam.setLookFrom(data._camera.position.x, data._camera.position.y, data._camera.position.z);
    cam.setDefaultValues();
}

void SceneBuilder::createSphere(completeFile &data, int index, Scene &scene,
                                UNUSED RayTracer::Camera &cam)
{
    std::shared_ptr<Materials::Material> actualMaterial = _material.at(
        data._spheresList[index].material)(data, SceneBuilder::ActualObject::SPHERE, index);
    std::shared_ptr<IPrimitives> sphere = std::make_shared<RayTracer::Sphere>(
        Math::Point3D((double)data._spheresList[index].position.x,
                      (double)data._spheresList[index].position.y,
                      (double)data._spheresList[index].position.z),
        data._spheresList[index].radius, actualMaterial);
    scene.addPrimitive(sphere);
}

void SceneBuilder::createPlane(completeFile &data, int index, Scene &scene,
                               UNUSED RayTracer::Camera &cam)
{
    std::shared_ptr<Materials::Material> actualMaterial = _material.at(
        data._planeList[index].material)(data, SceneBuilder::ActualObject::PLANE, index);
    std::shared_ptr<IPrimitives> plane = std::make_shared<RayTracer::Plane>(
        data._planeList[index].axis[0], data._planeList[index].position, actualMaterial);
    scene.addPrimitive(plane);
}

void SceneBuilder::createCone(completeFile &data, int index, Scene &scene,
                              UNUSED RayTracer::Camera &cam)
{
    std::shared_ptr<Materials::Material> actualMaterial =
        _material.at(data._coneList[index].material)(data, SceneBuilder::ActualObject::CONE, index);
    if (data._coneList[index].height != -1.0) {
        std::shared_ptr<IPrimitives> cone = std::make_shared<RayTracer::Cone>(
            Math::Point3D(data._coneList[index].center.x, data._coneList[index].center.y,
                          data._coneList[index].center.z),
            data._coneList[index].radius, data._coneList[index].height, data._coneList[index].angle,
            actualMaterial, data._coneList[index].axis[0]);
        scene.addPrimitive(cone);
    } else {
        std::shared_ptr<IPrimitives> cone = std::make_shared<RayTracer::Cone>(
            Math::Point3D(data._coneList[index].center.x, data._coneList[index].center.y,
                          data._coneList[index].center.z),
            data._coneList[index].radius, data._coneList[index].angle, actualMaterial,
            data._coneList[index].axis[0]);
        scene.addPrimitive(cone);
    }
}

void SceneBuilder::createCylinder(completeFile &data, int index, Scene &scene,
                                  UNUSED RayTracer::Camera &cam)
{
    std::shared_ptr<Materials::Material> actualMaterial = _material.at(
        data._cylinderList[index].material)(data, SceneBuilder::ActualObject::CYLINDER, index);
    if (data._cylinderList[index].height != -1.0) {
        std::shared_ptr<IPrimitives> cylinder = std::make_shared<RayTracer::Cylinder>(
            Math::Point3D(data._cylinderList[index].center.x, data._cylinderList[index].center.y,
                          data._cylinderList[index].center.z),
            data._cylinderList[index].radius, data._cylinderList[index].height, actualMaterial,
            data._cylinderList[index].axis[0]);
        scene.addPrimitive(cylinder);
    } else {
        std::shared_ptr<IPrimitives> cylinder = std::make_shared<RayTracer::Cylinder>(
            Math::Point3D(data._cylinderList[index].center.x, data._cylinderList[index].center.y,
                          data._cylinderList[index].center.z),
            data._cylinderList[index].radius, actualMaterial, data._cylinderList[index].axis[0]);
        scene.addPrimitive(cylinder);
    }
}

void SceneBuilder::createLight(completeFile &data, int index, UNUSED Scene &scene,
                               UNUSED RayTracer::Camera &cam)
{
    std::shared_ptr<Lights::DirectionalLight> directionalLights =
        std::make_shared<Lights::DirectionalLight>(Math::Vector3D(
            data._lightList[index].directionalLights.x, data._lightList[index].directionalLights.y,
            data._lightList[index].directionalLights.z));
    scene._directional_lights.push_back(directionalLights);
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

void SceneBuilder::saveConeData(const libconfig::Setting &element, int start,
                                completeFile &data) const
{
    SceneBuilder::ConeElement coneElement;
    for (int i = start; i < element.getLength(); i++) {
        const libconfig::Setting &coneElementInFile = element[i];
        for (int j = 0; j < coneElementInFile.getLength(); j++) {
            const libconfig::Setting &nestedConeElement = coneElementInFile[j];
            if (strcmp(nestedConeElement.getName(), "axis") == 0) {
                coneElementInFile.lookupValue("axis", coneElement.axis);
            }
            if (strcmp(nestedConeElement.getName(), "angle") == 0) {
                coneElementInFile.lookupValue("angle", coneElement.angle);
            }
            if (strcmp(nestedConeElement.getName(), "radius") == 0) {
                coneElementInFile.lookupValue("radius", coneElement.radius);
            }
            if (strcmp(nestedConeElement.getName(), "height") == 0) {
                coneElementInFile.lookupValue("height", coneElement.height);
            }
            if (strcmp(nestedConeElement.getName(), "material") == 0) {
                coneElementInFile.lookupValue("material", coneElement.material);
            }
            if (strcmp(nestedConeElement.getName(), "center") == 0) {
                const libconfig::Setting &center = nestedConeElement;
                for (int k = 0; k < center.getLength(); k++) {
                    if (strcmp(center[k].getName(), "x") == 0) {
                        nestedConeElement.lookupValue("x", coneElement.center.x);
                    }
                    if (strcmp(center[k].getName(), "y") == 0) {
                        nestedConeElement.lookupValue("y", coneElement.center.y);
                    }
                    if (strcmp(center[k].getName(), "z") == 0) {
                        nestedConeElement.lookupValue("z", coneElement.center.z);
                    }
                }
            }
            if (strcmp(nestedConeElement.getName(), "color") == 0) {
                const libconfig::Setting &color = nestedConeElement;
                for (int k = 0; k < color.getLength(); k++) {
                    if (strcmp(color[k].getName(), "r") == 0) {
                        nestedConeElement.lookupValue("r", coneElement.colorValues.r);
                    }
                    if (strcmp(color[k].getName(), "g") == 0) {
                        nestedConeElement.lookupValue("g", coneElement.colorValues.g);
                    }
                    if (strcmp(color[k].getName(), "b") == 0) {
                        nestedConeElement.lookupValue("b", coneElement.colorValues.b);
                    }
                }
            }
        }
        data._coneList.push_back(coneElement);
    }
}

void SceneBuilder::saveCylinderData(const libconfig::Setting &element, int start,
                                    completeFile &data) const
{
    SceneBuilder::CylinderElement cylinderElement;
    for (int i = start; i < element.getLength(); i++) {
        const libconfig::Setting &cylinderElementInFile = element[i];
        for (int j = 0; j < cylinderElementInFile.getLength(); j++) {
            const libconfig::Setting &nestedcylinderElement = cylinderElementInFile[j];
            if (strcmp(nestedcylinderElement.getName(), "axis") == 0) {
                cylinderElementInFile.lookupValue("axis", cylinderElement.axis);
            }
            if (strcmp(nestedcylinderElement.getName(), "radius") == 0) {
                cylinderElementInFile.lookupValue("radius", cylinderElement.radius);
            }
            if (strcmp(nestedcylinderElement.getName(), "height") == 0) {
                cylinderElementInFile.lookupValue("height", cylinderElement.height);
            }
            if (strcmp(nestedcylinderElement.getName(), "material") == 0) {
                cylinderElementInFile.lookupValue("material", cylinderElement.material);
            }
            if (strcmp(nestedcylinderElement.getName(), "center") == 0) {
                const libconfig::Setting &center = nestedcylinderElement;
                for (int k = 0; k < center.getLength(); k++) {
                    if (strcmp(center[k].getName(), "x") == 0) {
                        nestedcylinderElement.lookupValue("x", cylinderElement.center.x);
                    }
                    if (strcmp(center[k].getName(), "y") == 0) {
                        nestedcylinderElement.lookupValue("y", cylinderElement.center.y);
                    }
                    if (strcmp(center[k].getName(), "z") == 0) {
                        nestedcylinderElement.lookupValue("z", cylinderElement.center.z);
                    }
                }
            }
            if (strcmp(nestedcylinderElement.getName(), "color") == 0) {
                const libconfig::Setting &color = nestedcylinderElement;
                for (int k = 0; k < color.getLength(); k++) {
                    if (strcmp(color[k].getName(), "r") == 0) {
                        nestedcylinderElement.lookupValue("r", cylinderElement.colorValues.r);
                    }
                    if (strcmp(color[k].getName(), "g") == 0) {
                        nestedcylinderElement.lookupValue("g", cylinderElement.colorValues.g);
                    }
                    if (strcmp(color[k].getName(), "b") == 0) {
                        nestedcylinderElement.lookupValue("b", cylinderElement.colorValues.b);
                    }
                }
            }
        }
        data._cylinderList.push_back(cylinderElement);
    }
}

void SceneBuilder::saveLightData(const libconfig::Setting &element, completeFile &data,
                                 SceneBuilder::LightElement &lightElement) const
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
        }
    }
    if (strcmp(element.getName(), "directional") == 0) {
        for (int i = 0; i < element.getLength(); i++) {
            const libconfig::Setting &pointElement = element[i];
            for (int j = 0; j < pointElement.getLength(); j++) {
                const libconfig::Setting &nestedPointElement = pointElement[j];
                if (strcmp(nestedPointElement.getName(), "x") == 0) {
                    pointElement.lookupValue("x", lightElement.directionalLights.x);
                }
                if (strcmp(nestedPointElement.getName(), "y") == 0) {
                    pointElement.lookupValue("y", lightElement.directionalLights.y);
                }
                if (strcmp(nestedPointElement.getName(), "z") == 0) {
                    pointElement.lookupValue("z", lightElement.directionalLights.z);
                }
            }
        }
    }
}

void SceneBuilder::saveSceneData(const libconfig::Setting &element, std::string type, int index,
                                 completeFile &data, SceneBuilder::LightElement &lightElement,
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
    if (type == "Cone") {
        saveConeData(element, index, data);
        buildObject(type, data, index, scene, cam);
    }
    if (type == "Cylinder") {
        saveCylinderData(element, index, data);
        buildObject(type, data, index, scene, cam);
    }
    if (type == "Lights") {
        saveLightData(element, data, lightElement);
        if (strcmp(element.getName(), "directional") == 0) {
            data._lightList.push_back(lightElement);
            buildObject(type, data, index, scene, cam);
        }
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
