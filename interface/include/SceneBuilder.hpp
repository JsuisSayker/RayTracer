/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** SceneBuilder
*/

#ifndef SCENEBUILDER_HPP_
#define SCENEBUILDER_HPP_

#include <libconfig.h++>
#include <filesystem>
#include <iostream>
#include <vector>
#include "Scene.hpp"
#include "Sphere.hpp"
#include <raytracer/ISceneBuilder.hpp>
#include <map>
#include <functional>

class SceneBuilder : virtual public ISceneBuilder{
    public:
        enum SceneType {
            PRIMITIVE,
            CAMERA,
            LIGHT,
            MATERIAL
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
            color colorValues;
        };

        struct PlaneElement {
            std::string axis;
            int position;
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
        std::map<std::string, std::function<void(completeFile &, int)>> _object = {
        {"Sphere", std::bind(&SceneBuilder::createSphere, this, std::placeholders::_1, std::placeholders::_2)}
        };

        SceneBuilder() = default;
        SceneBuilder(const libconfig::Setting &list);
        ~SceneBuilder();

        void loadPlugins();
        void buildObject(std::string type, completeFile data, int index) const;
        void createSphere(completeFile &data, int index);
        void saveSceneData(const libconfig::Setting &list, std::string type,
            int count, completeFile &data, SceneBuilder::LightElement lightElement) const;
        void saveCameraData(const libconfig::Setting &list, completeFile data);
        void saveSphereData(const libconfig::Setting &element, int start, completeFile &data) const;
        void savePlaneData(const libconfig::Setting &element, int start, completeFile data);
        void saveLightData(const libconfig::Setting &element, completeFile data, SceneBuilder::LightElement lightElement);
        std::shared_ptr<IScene> getScene();

    private:
};

#endif /* !SCENEBUILDER_HPP_ */
