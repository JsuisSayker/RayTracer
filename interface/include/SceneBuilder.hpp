/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SceneBuilder
*/

#ifndef SCENEBUILDER_HPP_
#define SCENEBUILDER_HPP_

#include <libconfig.h++>
#include <Macros.hpp>
#include <Camera.hpp>
#include <filesystem>
#include <iostream>
#include <vector>
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Material.hpp"
#include "Metal.hpp"
#include "Lambertian.hpp"
#include "Dielectric.hpp"
#include "Plane.hpp"
#include <raytracer/ISceneBuilder.hpp>
#include <map>
#include <functional>

class SceneBuilder : virtual public ISceneBuilder{
    public:
        enum ActualObject {
            CAMERA,
            LIGHT,
            SPHERE,
            PLANE,
            DONE
        };

        struct coordinates {
            int x;
            int y;
            int z;
        };

        struct color {
            int r;
            int g;
            int b;
        };

        struct CameraElement {
            int width;
            int height;
            coordinates position;
            int rotationX;
            int rotationY;
            int rotationZ;
            double fov;
        };

        struct SphereElement {
            coordinates position;
            int radius;
            std::string material;
            color colorValues;
        };

        struct PlaneElement {
            std::string axis;
            int position;
            std::string material;
            color colorValues;
        };

        struct LightElement {
            double ambient;
            double diffuse;
            coordinates points;
        };

        std::shared_ptr<IScene> _scene;
        std::vector<std::string> _pathToPlugins;
        const libconfig::Setting &_scenesLists;
        std::vector<std::string> _typeList;
        struct completeFile {
            std::vector<SphereElement> _spheresList;
            std::vector<PlaneElement> _planeList;
            std::vector<LightElement> _lightList;
            CameraElement _camera;
        };
        std::map<std::string, std::function<void(completeFile &, int, Scene &, RayTracer::Camera &)>> _object = {
            {"Sphere", std::bind(&SceneBuilder::createSphere, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)},
            {"Plane", std::bind(&SceneBuilder::createPlane, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)},
            {"Camera", std::bind(&SceneBuilder::createCamera, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)},
            {"Lights", std::bind(&SceneBuilder::createLight, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4)}
        };

        std::map<std::string, std::function<std::shared_ptr<Material::Material>(completeFile &, SceneBuilder::ActualObject, int)>> _material = {
            {"Metal", std::bind(&SceneBuilder::createMetalMaterial, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
            {"Lambertian", std::bind(&SceneBuilder::createLambertianMaterial, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
            {"Dielectric", std::bind(&SceneBuilder::createDielectricMaterial, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)},
            {"Flat", std::bind(&SceneBuilder::createFlatMaterial, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3)}
        };

        SceneBuilder() = default;
        SceneBuilder(const libconfig::Setting &list, Scene &scene, RayTracer::Camera &cam);
        ~SceneBuilder();

        void buildObject(std::string type, completeFile data, int index, Scene &scene, RayTracer::Camera &cam) const;
        std::shared_ptr<Material::Material> createMetalMaterial(completeFile &data, SceneBuilder::ActualObject actualObject, int index);
        std::shared_ptr<Material::Material> createLambertianMaterial(completeFile &data, SceneBuilder::ActualObject actualObject, int index);
        std::shared_ptr<Material::Material> createDielectricMaterial(completeFile &data, SceneBuilder::ActualObject actualObject, int index);
        std::shared_ptr<Material::Material> createFlatMaterial(completeFile &data, SceneBuilder::ActualObject actualObject, int index);

        void createCamera(completeFile &data, int index, Scene &scene, RayTracer::Camera &cam);
        void createSphere(completeFile &data, int index, Scene &scene, RayTracer::Camera &cam);
        void createPlane(completeFile &data, int index, Scene &scene, RayTracer::Camera &cam);
        void createLight(completeFile &data, int index, Scene &scene, RayTracer::Camera &cam);

        void saveSceneData(const libconfig::Setting &list, std::string type,
            int count, completeFile &data, SceneBuilder::LightElement lightElement, Scene &scene, RayTracer::Camera &cam) const;
        void saveCameraData(const libconfig::Setting &list, completeFile &data) const;
        void saveSphereData(const libconfig::Setting &element, int start, completeFile &data) const;
        void savePlaneData(const libconfig::Setting &element, int start, completeFile &data) const;
        void saveLightData(const libconfig::Setting &element, completeFile &data, SceneBuilder::LightElement lightElement) const;
        // std::shared_ptr<IScene> getScene();

    private:
};

#endif /* !SCENEBUILDER_HPP_ */
