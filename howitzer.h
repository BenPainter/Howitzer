#pragma once
#include "position.h"
#include "uiDraw.h"

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
   void input();
   bool isFired();
   Position getPT();
   double getAngle();
   Position setPT();
   double setAngle();
   void draw(ogstream& gout);
   double getAge();
   void reset();

};

