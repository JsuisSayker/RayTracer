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

        struct CameraElement {
            int width;
            int height;
            int positionX;
            int positionY;
            int positionZ;
            int rotationX;
            int rotationY;
            int rotationZ;
            double fov;
        };

        SceneBuilder() = default;
        SceneBuilder(const libconfig::Setting &list);
        ~SceneBuilder();

        void loadPlugins();
        void buildObject(libconfig::Setting &setting);
        void createSphere(libconfig::Setting &setting);
        void saveSceneData(const libconfig::Setting &list);
        std::shared_ptr<IScene> getScene();

    protected:
        std::shared_ptr<IScene> _scene;
        std::vector<std::string> _pathToPlugins;
        const libconfig::Setting &_scenesLists;
    private:
};

#endif /* !SCENEBUILDER_HPP_ */
