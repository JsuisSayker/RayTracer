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

class SceneBuilder {
    public:
        enum SceneType {
            PRIMITIVE,
            CAMERA,
            LIGHT,
            MATERIAL
        };

        SceneBuilder(libconfig::Setting &list);
        ~SceneBuilder();

        void loadPlugins();
        void buildObject(libconfig::Setting &setting);
        void createSphere(libconfig::Setting &setting);

    protected:
        std::shared_ptr<Scene> _scene;
        std::vector<std::string> _pathToPlugins;
        libconfig::Setting &_scenesLists;
    private:
};

#endif /* !SCENEBUILDER_HPP_ */
