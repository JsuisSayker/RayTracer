/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** Interval
*/

#ifndef INTERVAL_HPP_
#define INTERVAL_HPP_

#include <limits>

namespace Math {
class Interval {
public:
  Interval();
  Interval(double min, double max);
  ~Interval();

  double size() const;
  bool contains(double x) const;
  bool surrounds(double x) const;
  double clamp(double x) const;


  double _min;
  double _max;

  static const Math::Interval empty() {
    return Math::Interval(+std::numeric_limits<double>::infinity(),
                          -std::numeric_limits<double>::infinity());
  }
  static const Math::Interval universe() {
    return Math::Interval(-std::numeric_limits<double>::infinity(),
                          +std::numeric_limits<double>::infinity());
  }
};
} // namespace Math

#endif /* !INTERVAL_HPP_ */
