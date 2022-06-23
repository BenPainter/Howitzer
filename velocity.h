#pragma once
#include "acceleration.h"

class testVelocity;


class Velocity
{
private:
   double dx;
   double dy;

public:
   friend testVelocity;

   // constructors
   Velocity() : dx(0.0), dy(0.0) {};
   Velocity(double dx, double dy);

   double getDX() const { return dx; };
   double getDY() const { return dy; };
   double computeVelocity();

   void setDX(double dx);
   void setDY(double dy);

   void addVelocity(Acceleration accel, double time);
};

