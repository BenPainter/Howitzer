#pragma once


class testVelocity;


class Velocity
{
public:
   friend testVelocity;

   Velocity();
   Velocity(double dx, double dy);
   double getDX();
   double getDY();
   double computeVelocity();
   void setDX(double dx);
   void setDY(double dy);
   void addVelocity(Acceleration accel, double time);

private:
   double dx;
   double dy;
};

