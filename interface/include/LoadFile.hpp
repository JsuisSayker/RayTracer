/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** LoadFile
*/

#ifndef LOADFILE_HPP_
#define LOADFILE_HPP_

#include <memory>
#include <raytracer/ILoadFile.hpp>
#include <SceneBuilder.hpp>

class LoadFile : virtual public ILoadFile {
    public:
        LoadFile(std::string path);
        ~LoadFile();

    protected:
        std::shared_ptr<ISceneBuilder> _actualBuilder;
    private:
};

#endif /* !LOADFILE_HPP_ */
