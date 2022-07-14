#pragma once
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;
/********************************************************
* Howitzer
* The class that stores all the details of the howitzer.
*********************************************************/

class Howitzer
{
private:
   Position pt;
   double angle;
   bool fired;
   double age;

public:
   // constructors
   Howitzer()            { reset(); }
   Howitzer(Position pt) { this->pt = pt; }

   // setters
   void setPT(const Position& newPT) { pt = newPT; }
   void setAngle(double newAngle)    { angle = newAngle; }

   // getters
   Position getPT()    { return pt; }
   double   getAngle() { return angle; }
   double   getAge()   { return age; }

   // resets
   void reset();
   void resetAge() { age = 0.0; }

   // status
   void loadHowitzer() { fired = false; }
   bool isFired()      { return fired; }
   
   // gameplay loop
   void input(const Interface& pUI);
   void draw(ogstream& gout);
   void updateAge() { age += 0.5; }
};

