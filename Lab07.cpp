/*************************************************************
 * 1. Name:
 *      Ben Painter, Star Balls
 * 2. Assignment Name:
 *      Lab 08: M777 Howitzer
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      The most difficult parts for us were trying to figure 
 *      where the howitzer position was being randomized and 
 *      then getting the Howitzer class to be responsible for
 *      its positon. We had a hard time making sure the howitzer
 *      was on the ground.
 * 5. How long did it take for you to complete the assignment?
 *      We are estimating it took us about 10 hours between last
 *      weeks assignment of getting it to just work and this week
 *      cleaning up the code and working on the encapsulation 
 *      metrics we learned this semester. 
 *****************************************************************/

#include <cassert>      // for ASSERT
#include <cstdlib>      // for srand
#include <ctime>        // for time for srand
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "ground.h"     // for GROUND
#include "position.h"   // for POSITION
#include "test.h"       // for TEST
#include "physics.h"    // for PHYSICS
#include "howitzer.h"   // for HOWITZER
#include "projectile.h" // for PROJECTILE

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
      ground(ptUpperRight)
   {
      ground.reset(howitzer.getPT());
   }
   Ground ground;                 // the ground
   Position  projectilePath[20];  // path of the projectile
   Position  ptUpperRight;        // size of the screen
   Howitzer howitzer;             // the howitzer
   Projectile projectile;         // the bullet
};

void resetGame(void* p)
{
   Game* pGame = (Game*)p;

   pGame->howitzer.reset();
   pGame->ground.reset(pGame->howitzer.getPT());
   pGame->projectile.reset();

}


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
   Acceleration accel;
   
   //
   // accept input
   //
   double distanceFromTarget = computeDistance(pGame->projectile.getPT(), pGame->ground.getTarget());

   if (!pGame->howitzer.isFired() && !pGame->projectile.isAlive())
      pGame->howitzer.input(*pUI);
   else if (!pGame->projectile.isAlive())
   {
      pGame->projectile.fired(pGame->howitzer.getPT(), pGame->howitzer.getAngle());
      pGame->howitzer.loadHowitzer();
   }
   
   if (pUI->isR())
   {
      resetGame(pGame);
   }

   //
   // perform all the game logic
   //

   // checking if above ground
   if (pGame->projectile.getPT().getMetersY() - 
      pGame->ground.getElevationMeters(pGame->projectile.getPT()) < 0.0)
   {
      pGame->projectile.missTarget();
      pGame->howitzer.resetAge();
   }

   // checking if off screen
   if (pGame->projectile.getPT().getPixelsX() < 0.0 
      || pGame->projectile.getPT().getPixelsX() > 700.0)
   {
      pGame->projectile.missTarget();
      pGame->howitzer.resetAge();
   }

   // checking for hit target
   if ( distanceFromTarget <= 400.0)
   {
      pGame->projectile.hitTarget();
      resetGame(pGame);
   }

   // move the projectile across the screen
   if (pGame->projectile.isAlive())
   {
      pGame->projectile.update(accel);
      pGame->howitzer.updateAge();
   }

   //
   // draw everything
   //

   ogstream gout(Position(10.0, pGame->ptUpperRight.getPixelsY() - 20.0));

   // draw the ground first
   pGame->ground.draw(gout);

   // draw the howitzer
   pGame->howitzer.draw(gout);

   // draw the projectile
   pGame->projectile.draw(gout);

   // draw some text on the screen
   gout.setf(ios::fixed | ios::showpoint);
   gout.precision(1);
   gout << "Time since the bullet was fired: "
      << pGame->howitzer.getAge() << "s\n"; 
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

   srand(time(0));
   // Initialize the game
   Game game(ptUpperRight);

   // set everything into action
    ui.run(callBack, &game);


   return 0;
}
