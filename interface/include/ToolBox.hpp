/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ToolBox
*/

#ifndef TOOLBOX_HPP_
#define TOOLBOX_HPP_

#include <cmath>
#include <limits>

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

double degrees_to_radians(double degrees);
double random_double();
double random_double(double min, double max);

#endif /* !TOOLBOX_HPP_ */
