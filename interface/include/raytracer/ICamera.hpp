/*
** EPITECH PROJECT, 2024
** RayTracer
** File description:
** ICamera
*/

#ifndef ICAMERA_HPP_
#define ICAMERA_HPP_

class ICamera
{
  public:
    ICamera(){};
    virtual ~ICamera() = default;

    virtual int getHeigth() = 0;
    virtual int getWidth() = 0;
    virtual int getFov() = 0;

    virtual void setFov(int fov) = 0;
    virtual void setHeigth(int heigth) = 0;
    virtual void setWidth(int width) = 0;

  protected:
  private:
};

#endif /* !ICAMERA_HPP_ */
