/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ISceneBuilder
*/

#ifndef ISCENEBUILDER_HPP_
#define ISCENEBUILDER_HPP_

#include <libconfig.h++>


class ISceneBuilder {
    public:
        ISceneBuilder(){};
        ISceneBuilder(libconfig::Setting &list){};
        virtual ~ISceneBuilder(){};

    protected:
    private:
};

#endif /* !ISCENEBUILDER_HPP_ */
