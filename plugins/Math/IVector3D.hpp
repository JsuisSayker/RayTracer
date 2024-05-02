/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** test
*/

#ifndef IVECTOR3D_HPP__
#define IVECTOR3D_HPP__

#include <cmath>
#include <vector>

namespace Math {

    class IVector3D {
        public:
        double x;
        double y;
        double z;

        IVector3D() {};
        IVector3D(double x, double y, double z) {};
        virtual ~IVector3D() {};

        virtual double length() = 0;

        //rotate functions
        virtual void rotateX(double angle) = 0;
        virtual void rotateY(double angle) = 0;
        virtual void rotateZ(double angle) = 0;

        virtual double dot(const Math::IVector3D& v) const = 0;

        template <int N>
        class IVector {
            public:
                std::vector<double> values;

                IVector() : values(N, 0) {};
                IVector(const std::vector<double>& components){};

                virtual double dot(const IVector& v) const = 0;
        };
    };
}


#endif /* !IVECTOR3D */

