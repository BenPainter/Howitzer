#include "projectile.h"





/*****************************************
* Projectile
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
* Projectile
******************************************/
void Projectile::update(Acceleration accel)
{
   updateTail();
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


   pt.setMetersX(pt.computeNewPosition(pt.getMetersX(), velocity.getDX(), accel.getDDX(), TIME));
   pt.setMetersY(pt.computeNewPosition(pt.getMetersY(), velocity.getDY(), accel.getDDY(), TIME));
   velocity.updateVelocity(accel, TIME);

}
/*****************************************
* Projectile
******************************************/
void Projectile::updateTail()
{
   tail.push_front(pt);
   if (tail.size() > 5)
      tail.pop_back();
   
}


/*****************************************
* Projectile
******************************************/
void Projectile::reset()
{
   pt.setPixelsX(300.0);
   pt.setPixelsY(300.0);
   tail.clear();
   status = READY;
}

/*****************************************
* Projectile
******************************************/
void Projectile::hitTargert()
{
   status = HIT;
}

/*****************************************
* Projectile
******************************************/
void Projectile::missTarget()
{
   status = READY;
   pt.setPixelsY(550.0);
   tail.clear();

}

/*****************************************
* Projectile
******************************************/
void Projectile::fired(Position newPT, const double& newAngle)
{
   status = ALIVE;
   pt = newPT;
   velocity.setDX(horizontalComp(827.0, newAngle));
   velocity.setDY(verticalComp(827.0, newAngle));
}
