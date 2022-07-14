#include <math.h> 
#include "physics.h"


// vectors based on various charts
vector <double> altitudeTable = { 0.0, 1000.0, 2000.0, 3000.0, 4000.0, 5000.0, 6000.0, 7000.0, 8000.0, 9000.0, 10000.0, 15000.0, 20000.0, 25000.0 };
vector <double> densityTable = { 1.225, 1.112, 1.007, 0.9093, 0.8194, 0.7364, 0.6601, 0.59, 0.5258, 0.4671, 0.4135, 0.1948, 0.08891, 0.04008 };
vector <double> soundTable = { 340.0, 336.0, 332.0, 328.0, 324.0, 320.0, 316.0, 312.0, 308.0, 303.0, 299.0, 295.0, 295.0, 295.0 };
vector <double> gravityTable = { 9.807, 9.804, 9.801, 9.797, 9.794, 9.791, 9.788, 9.785, 9.782, 9.779, 9.776, 9.761, 9.745, 9.730 };
vector <double> machTable = { 0.0, 0.3, 0.5, 0.7, 0.89, 0.92, 0.96, 0.98, 1.0, 1.02, 1.06, 1.24, 1.53, 1.99, 2.87, 2.89, 5.0 };
vector <double> dragTable = { 0.1629, 0.1629, 0.1659, 0.2031, 0.2597, 0.301, 0.3287, 0.4002, 0.4258, 0.4335, 0.4483, 0.4064, 0.3663, 0.2897, 0.2297, 0.2306, 0.2656 };


/*******************************************************
* VECTOR FROM ID
* A method that takes in an ENUM value and returns the
* correct corresponding vector/table.
********************************************************/
vector <double> vectorFromID(vectorNames tableName)
{
   switch(tableName)
   {
   case ALTITUDE:
      return altitudeTable;
   case DENSITY:
      return densityTable;
   case SOUND:
      return soundTable;
   case GRAVITY:
      return gravityTable;
   case MACH:
      return machTable;
   case DRAG:
      return dragTable;
   }
}


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

/*******************************************************
* TABLE LOOK UP
* Takes in two vectors, composed of values from tables,
* and uses linear interpolation, if needed, to find
* the correct value.
********************************************************/
double tableLookUp(const vector<double> chart1, const vector <double> chart2, const double d)
{
   assert(chart1.size() == chart2.size()); // the two charts should always be the same size

   int i = 0;

   assert(chart1[i] <= d);

   while (i < chart1.size()) // needs to be inside the table
   {
      if (chart1[i] == d)
      {
         return chart2[i];
      }
      else if (chart1[i] > d)
      {
         return linearInter(d, chart1[i - 1], chart2[i - 1], chart1[i], chart2[i]);
      }
      i++;
   }

   return 0.0;
}