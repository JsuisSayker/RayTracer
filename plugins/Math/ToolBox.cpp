/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ToolBox
*/

#include <ToolBox.hpp>

double degrees_to_radians(double degrees) { return degrees * pi / 180.0; }

double random_double()
{
    // Returns a random real in [0,1).
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max)
{
    // Returns a random real in [min,max).
    return min + (max - min) * random_double();
}

int random_int(int min, int max)
{
    // Returns a random integer in [min,max].
    return int(random_double(min, max + 1));
}