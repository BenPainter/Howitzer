#pragma once
#include "position.h"
#include "uiDraw.h"
#include "uiInteract.h"

using namespace std;
/*****************************************************
* Howitzer
******************************************************/

class Howitzer
{
private:
   Position pt;
   double angle;
   bool fired;
   double age;

public:
   Howitzer() { reset(); };
   Howitzer(Position pt) { this->pt = pt; };
   void input(const Interface& pUI);
   bool isFired();
   Position getPT();
   double getAngle() { return angle; }


   void setPT(const Position &newPT);
   double setAngle();
   void loadHowitzer() { fired = false; };

   void draw(ogstream& gout);
   double getAge() { return age; };
   void updateAge() { age += 0.5; };
   void reset();
   void resetAge() { age = 0.0; }

};

