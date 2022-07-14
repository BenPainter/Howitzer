#include "howitzer.h"

/*****************************************************
* INPUT
* 
******************************************************/
void Howitzer::input(const Interface& pUI)
{
   
   // move a large amount
      if (pUI.isRight() && angle <= 1.6)
         angle += 0.05;
      if (pUI.isLeft() && angle >= -1.6)
         angle -= 0.05;

      // move by a little
      if (pUI.isUp())
         angle += (angle >= 0 ? -0.003 : 0.003);
      if (pUI.isDown())
         angle += (angle >= 0 ? 0.003 : -0.003);

      // fire that gun
      if (pUI.isSpace())
      {
         fired = true;
      }
}

/*****************************************************
* ISFIRED
******************************************************/
bool Howitzer::isFired()
{
   return fired;
}

/*****************************************************
* GET PT
******************************************************/
Position Howitzer::getPT()
{
   return pt;
}


/*****************************************************
* Howitzer
******************************************************/
void Howitzer::setPT(const Position &newPT)
{
   pt = newPT;
}

/*****************************************************
* Howitzer
******************************************************/
double Howitzer::setAngle()
{
   return 0.0;
}

/*****************************************************
* Howitzer
******************************************************/
void Howitzer::draw(ogstream& gout)
{
   gout.drawHowitzer(pt, angle, age);
}

/*****************************************************
* Howitzer
******************************************************/
void Howitzer::reset()
{
   resetAge();
   angle = 0.0;
   fired = false;
   pt.setMetersX(200.0);
}
