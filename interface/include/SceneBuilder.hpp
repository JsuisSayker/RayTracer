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
#include <raytracer/ISceneBuilder.hpp>

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

        SceneBuilder() = default;
        SceneBuilder(const libconfig::Setting &list);
        ~SceneBuilder();

        void loadPlugins();
        void buildObject(libconfig::Setting &setting);
        void createSphere(libconfig::Setting &setting);
        void saveSceneData(const libconfig::Setting &list, std::string type);
        void saveCameraData(const libconfig::Setting &list);
        void saveSphereData(const libconfig::Setting &element);
        std::shared_ptr<IScene> getScene();

    protected:
        std::shared_ptr<IScene> _scene;
        std::vector<std::string> _pathToPlugins;
        const libconfig::Setting &_scenesLists;
        std::vector<std::string> _typeList;
        std::vector<SphereElement> _spheresList;
    private:
};

#endif /* !SCENEBUILDER_HPP_ */
