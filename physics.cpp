#include <math.h> 
#include "physics.h"

/*******************************************************
* LINEAR INTERPOLATION
* A method of curve fitting using linear polynomials to
* construct new data points within the range of a discrete
* set of known data points.
********************************************************/
double linearInter(const double d, const double d0, const double  r0, const double d1, const double r1)
{
   if (d1 != d0)    // check for dividing by zero
      return r0 + ((d - d0) * (r1 - r0)) / (d1 - d0);
   return r0;
}

/*******************************************************
* VERTICAL COMPONENT
* Calculates the change in the y position.
********************************************************/
double verticalComp(const double s, const double a)
{
   return s * cos(a);
}

/*******************************************************
* HORIZONTAL COMPONENT
* Calculates the change in the x position.
********************************************************/
double horizontalComp(const double s, const double a)
{
   return s * sin(a);
}

/*******************************************************
* DRAGFORCE
* Uses the drag coefficient, air density, velocity, and
* surface area to calculate the drag force in newtons.
********************************************************/
double dragForce(const double c, const double p, const double v, const double a)
{
   // returns d (force in newtons)
   return (.5 * c * p * (v * v) * a);
}