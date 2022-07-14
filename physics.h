#pragma once
#include <vector>
#include <cassert>

using namespace std;

// for the VectorFromID function
enum vectorNames {ALTITUDE, DENSITY, SOUND, GRAVITY, MACH, DRAG};

// converts the ID into the correct table
vector <double> vectorFromID(vectorNames tableName);

// physic functions for projectile
double linearInter(const double d, const double d0, const double  r0, const double d1, const double r1);
double verticalComp(const double s, const double a);
double horizontalComp(const double s, const double a);
double dragForce(const double c, const double p, const double v, const double a);
double tableLookUp(const vector<double> chart1, const vector <double> chart2, const double d);