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

Math::Interval::Interval(const Math::Interval &a, const Math::Interval &b)
{
    // Create the interval tightly enclosing the two input intervals.
    _min = a._min <= b._min ? a._min : b._min;
    _max = a._max >= b._max ? a._max : b._max;
}

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

Math::Interval Math::Interval::expand(double delta) const
{
    auto padding = delta / 2;
    return Math::Interval(_min - padding, _max + padding);
}