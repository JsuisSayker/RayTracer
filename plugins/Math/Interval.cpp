/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Interval
*/

#include <Interval.hpp>

Math::Interval::Interval() : _min(+infinity), _max(-infinity) {}

Math::Interval::~Interval() {}

Math::Interval::Interval(double min, double max) : _min(min), _max(max) {}

double Math::Interval::size() const { return _max - _min; }

bool Math::Interval::contains(double x) const { return _min <= x && x <= _max; }

bool Math::Interval::surrounds(double x) const { return _min < x && x < _max; }

double Math::Interval::clamp(double x) const
{
    if (x < _min)
        return _min;
    if (x > _max)
        return _max;
    return x;
}