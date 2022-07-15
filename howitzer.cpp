#include "howitzer.h"

/*****************************************************
* Howitzer INPUT
* Handles user input.
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
      fired = true;
}

/*****************************************************
* Howitzer DRAW
* Draws the howitzer.
******************************************************/
void Howitzer::draw(ogstream& gout)
{
   gout.drawHowitzer(pt, angle, age);
}

/*****************************************************
* Howitzer RESET
* Resets all the attributes for the howitzer.
******************************************************/
void Howitzer::reset()
{
   pt.setPixelsX((rand() % 700));
   pt.setPixelsY(0.0);
   resetAge();
   angle = 0.0;
   fired = false;
}