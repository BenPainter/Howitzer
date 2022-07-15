#include "acceleration.h"

/***********************************************************************
 * Acceleration: uses the velocity to calculate 
 *               and return the acceleration. 
 ************************************************************************/

 /***********************************************************************
  * Acceleration
  * A non-default constructor that takes in a ddx and ddy
  ************************************************************************/
Acceleration::Acceleration(double ddx, double ddy)
{
   this->ddx = ddx;
   this->ddy = ddy;
}

/***********************************************************************
 * Acceleration COMPUTE HORIZONTAL COMP
 * Uses dx to calculate ddx.
 ************************************************************************/
double Acceleration::computeHorizontalComp(double angle, double velocity) const
{
   // Compute x componenent of acceleration
   return sin(angle) * velocity;
}

/***********************************************************************
 * Acceleration COMPUTE VERTICAL COMP
 * Uses dy to calculate ddy.
 ************************************************************************/
double Acceleration::computeVerticalComp(double angle, double velocity) const
{
   // Compute y componenent of acceleration
   return (cos(angle) * velocity);
}
