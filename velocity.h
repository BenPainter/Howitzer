#pragma once
#include "acceleration.h"

class TestVelocity;


class Velocity
{
private:
   double dx;
   double dy;

public:
   friend TestVelocity;

   // constructors
   Velocity() : dx(0.0), dy(0.0) {};
   Velocity(double dx, double dy);

   double getDX() const { return dx; };
   double getDY() const { return dy; };
   double computeVelocity();
   double computeAngle();

   void setDX(double dx) { this->dx = dx; };
   void setDY(double dy) { this->dy = dy; };

   void updateVelocity(Acceleration accel, double time);
};

