/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ICamera
*/

#ifndef ICAMERA_HPP_
#define ICAMERA_HPP_

class ICamera {
public:
  ICamera(){};
  virtual ~ICamera() = default;
  virtual void setResolution(int width, int height) = 0;
  virtual void setLookFrom(double x, double y, double z) = 0;
  virtual void setFov(double fov) = 0;
  virtual void setDefaultValues() = 0;

  protected:
  private:
};

#endif /* !ICAMERA_HPP_ */
