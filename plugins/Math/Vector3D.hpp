/*
** EPITECH PROJECT, 2024
** bootstrap_Raytracer
** File description:
** test
*/

#ifndef VECTOR3D_HPP__
#define VECTOR3D_HPP__

#include "IVector3D.hpp"

namespace Math {

    class Vector3D : virtual public IVector3D {
        public:

        Vector3D();
        Vector3D(double x, double y, double z);
        ~Vector3D();

        double length();

        //rotate functions
        void rotateX(double angle);
        void rotateY(double angle);
        void rotateZ(double angle);

        // Operator overloading
        Vector3D operator+(const Vector3D& v) const;
        Vector3D operator+=(const Vector3D& v);
        Vector3D operator-(const Vector3D& v) const;
        Vector3D operator-= (const Vector3D& v);

        Vector3D operator*(double k) const;
        Vector3D operator*= (double k);
        Vector3D operator/(double k) const;
        Vector3D operator/= (double k);

        double dot(const Vector3D& v) const;


        template <int N>
        class Vector {
            public:
                std::vector<double> values;

                Vector() : values(N, 0) {};
                Vector(const std::vector<double>& components){};

                // Operator overloading
                Vector<N> operator+(const Vector& v) const {
                    Vector result;
                    for (int i = 0; i < N; i++) {
                        result.values[i] = values[i] + v.values[i];
                    }
                    return result;
                };

                Vector<N> operator+=(const Vector& v) {
                    for (int i = 0; i < N; i++) {
                        values[i] += v.values[i];
                    }
                    return *this;
                };

                Vector<N> operator-(const Vector& v) const {
                    Vector result;
                    for (int i = 0; i < N; i++) {
                        result.values[i] = values[i] - v.values[i];
                    }
                    return result;
                };

                Vector<N> operator-=(const Vector& v) {
                    for (int i = 0; i < N; i++) {
                        values[i] -= v.values[i];
                    }
                    return *this;
                };

                Vector<N> operator*(double k) const {
                    Vector result;
                    for (int i = 0; i < N; i++) {
                        result.values[i] = values[i] * k;
                    }
                    return result;
                };

                Vector<N> operator*=(double k) {
                    for (int i = 0; i < N; i++) {
                        values[i] *= k;
                    }
                    return *this;
                };

                Vector<N> operator/(double k) const {
                    Vector result;
                    for (int i = 0; i < N; i++) {
                        result.values[i] = values[i] / k;
                    }
                    return result;
                };

                Vector<N> operator/=(double k) {
                    for (int i = 0; i < N; i++) {
                        values[i] /= k;
                    }
                    return *this;
                };

                double dot(const Vector& v) const {
                    double result = 0;
                    for (int i = 0; i < N; i++) {
                        result += values[i] * v.values[i];
                    }
                    return result;
                };
        };
    };
}


#endif /* !VECTOR3D */

