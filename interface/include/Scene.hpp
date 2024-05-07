/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <raytracer/IScene.hpp>

class Scene : virtual public IScene {
    public:
        Scene();
        ~Scene();

        void addPrimitive(std::shared_ptr<IPrimitives> primitive);
        void addCamera(std::shared_ptr<ICamera> camera);
        bool hits(const RayTracer::Ray &r, double ray_tmin, double ray_tmax, RayTracer::Primitives_record &rec) const;
    protected:
        std::vector<std::shared_ptr<ICamera>> _camera;
        std::vector<std::shared_ptr<IPrimitives>> _primitives;
    private:
};

#endif /* !SCENE_HPP_ */
