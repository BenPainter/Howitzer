/*************************************************************
 * 1. Name:
 *      The Key
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "test.h"
#include "physics.h"

using namespace std;



/*************************************************************************
 * Game
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Game
{
public:
   Game(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      ground(ptUpperRight),
      time(0.0),
      angle(0.0)
   {
      ptHowitzer.setPixelsX(Position(ptUpperRight).getPixelsX() / 2.0);
      ground.reset(ptHowitzer);
      for (int i = 0; i < 20; i++)
      {
         projectilePath[i].setPixelsX((double)i * 2.0);
         projectilePath[i].setPixelsY(ptUpperRight.getPixelsY() / 1.5);
      }
   }

   Ground ground;                 // the ground
   Position  projectilePath[20];  // path of the projectile
   Position  ptHowitzer;          // location of the howitzer
   Position  ptUpperRight;        // size of the screen
   double angle;                  // angle of the howitzer 
   double time;                   // amount of time since the last firing
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Game* pGame = (Game*)p;

   //
   // accept input
   //

   // move a large amount
   if (pUI->isRight())
      pGame->angle += 0.05;
   if (pUI->isLeft())
      pGame->angle -= 0.05;

   // move by a little
   if (pUI->isUp())
      pGame->angle += (pGame->angle >= 0 ? -0.003 : 0.003);
   if (pUI->isDown())
      pGame->angle += (pGame->angle >= 0 ? 0.003 : -0.003);

   // fire that gun
   if (pUI->isSpace())
      pGame->time = 0.0;

   //
   // perform all the game logic
   //

   // advance time by half a second.
   pGame->time += 0.5;

   // move the projectile across the screen
   for (int i = 0; i < 20; i++)
   {
      double x = pGame->projectilePath[i].getPixelsX();
      x -= 1.0;
      if (x < 0)
         x = pGame->ptUpperRight.getPixelsX();
      pGame->projectilePath[i].setPixelsX(x);
   }

   //
   // draw everything
   //

   ogstream gout(Position(10.0, pGame->ptUpperRight.getPixelsY() - 20.0));

   // draw the ground first
   pGame->ground.draw(gout);

   // draw the howitzer
   gout.drawHowitzer(pGame->ptHowitzer, pGame->angle, pGame->time);

   // draw the projectile
   for (int i = 0; i < 20; i++)
      gout.drawProjectile(pGame->projectilePath[i], 0.5 * (double)i);

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
      << pGame->time << "s\n";
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setPixelsX(700.0);
   ptUpperRight.setPixelsY(500.0);
   Position().setZoom(40.0 /* 42 meters equals 1 pixel */);
   Interface ui(0, NULL,
      "Game",   /* name on the window */
      ptUpperRight);

   // Initialize the game
   Game game(ptUpperRight);

   // set everything into action
    ui.run(callBack, &game);


   return 0;
}
