#include "projectile.h"

/*****************************************
* Projectile DRAW
* Draws the Projectile and its tail
******************************************/
void Projectile::draw(ogstream& gout) 
{
   list<Position>::iterator it;
   double count = 0;
   for (it = tail.begin(); it != tail.end(); it++, count++)
   {
      gout.drawProjectile(*(it), count);
   }
}

/*****************************************
* Projectile UPDATE
* Performs all the math needed to move
* the projectile.
******************************************/
void Projectile::update(Acceleration accel)
{
   // update tail
   updateTail();

   // perform physics
   double angle = velocity.computeAngle();
   double totalVelocity = velocity.computeVelocity();
   double p = tableLookUp(vectorFromID(ALTITUDE), vectorFromID(DENSITY), pt.getMetersY());
   double vSound = tableLookUp(vectorFromID(ALTITUDE), vectorFromID(SOUND), pt.getMetersY());
   double vMach = totalVelocity / vSound;
   double c = tableLookUp(vectorFromID(MACH), vectorFromID(DRAG), vMach);
   double force = dragForce(c, p, totalVelocity, AREA);
   double acc = (force / MASS);
   accel.setDDX(horizontalComp(-acc, angle));
   accel.setDDY(-tableLookUp(vectorFromID(ALTITUDE), vectorFromID(GRAVITY), pt.getMetersY()) + verticalComp(-acc, angle));

   // update position and velocity
   pt.setMetersX(pt.computeNewPosition(pt.getMetersX(), velocity.getDX(), accel.getDDX(), TIME));
   pt.setMetersY(pt.computeNewPosition(pt.getMetersY(), velocity.getDY(), accel.getDDY(), TIME));
   velocity.updateVelocity(accel, TIME);
}

/*****************************************
* Projectile UPDATE TAIL
* Refreshes the projectile's tail to most 
* recent points
******************************************/
void Projectile::updateTail()
{
   tail.push_front(pt);
   if (tail.size() > 5)
      tail.pop_back();
}

/*****************************************
* Projectile RESET
* Resets the attributes for next attempt.
******************************************/
void Projectile::reset()
{
   pt.setPixelsX(300.0);
   pt.setPixelsY(550.0);
   tail.clear();
   status = READY;
}

/*****************************************
* Projectile MISS TARGET
* Updates the attributes of the projectile 
* to reflect the bullet hitting the ground.
******************************************/
void Projectile::missTarget()
{
   status = READY;
   pt.setPixelsY(550.0);
   tail.clear();
}

/*****************************************
* Projectile FIRED
* Updates the attributes of the projectile 
* to reflect the bullet being fired.
******************************************/
void Projectile::fired(Position newPT, const double& newAngle)
{
   status = ALIVE;
   pt = newPT;
   velocity.setDX(horizontalComp(827.0, newAngle));
   velocity.setDY(verticalComp(827.0, newAngle));
}
