/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Interval
*/

#include <Interval.hpp>

Math::Interval::Interval()
    : _min(+std::numeric_limits<double>::infinity()),
      _max(-std::numeric_limits<double>::infinity()) {}

Math::Interval::~Interval() {}

Math::Interval::Interval(double min, double max) : _min(min), _max(max) {}

double Math::Interval::size() const { return _max - _min; }

bool Math::Interval::contains(double x) const { return _min <= x && x <= _max; }

bool Math::Interval::surrounds(double x) const { return _min < x && x < _max; }