/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Interval
*/

#ifndef INTERVAL_HPP_
#define INTERVAL_HPP_

#include <limits>

#include "ToolBox.hpp"

namespace Math {
class Interval
{
  public:
    Interval();
    Interval(double min, double max);
    Interval(const Math::Interval &a, const Math::Interval &b);
    ~Interval();

    double size() const;
    bool contains(double x) const;
    bool surrounds(double x) const;
    double clamp(double x) const;
    Math::Interval expand(double delta) const;

    double _min;
    double _max;

    static const Math::Interval empty() { return Math::Interval(+infinity, -infinity); }
    static const Math::Interval universe() { return Math::Interval(-infinity, +infinity); }
};
} // namespace Math

#endif /* !INTERVAL_HPP_ */
