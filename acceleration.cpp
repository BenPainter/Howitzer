#include "acceleration.h"

/***********************************************************************
 * Acceleration: uses the velocity to calculate acceleration and return
 *               acceleration of the lunar module.
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
double Acceleration::computeHorizontalComp(double angle, double thrust)
{
   // Compute x componenent of acceleration
   return sin(angle) * thrust;
}

/***********************************************************************
 * Acceleration COMPUTE VERTICAL COMP
 * Uses dy to calculate ddy.
 ************************************************************************/
double Acceleration::computeVerticalComp(double angle, double thrust)
{
   // Compute y componenent of acceleration
   return (cos(angle) * thrust);
}
