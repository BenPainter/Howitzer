#include "projectile.h"



/*****************************************
* Projectile
******************************************/
void Projectile::updateTail()
{
}

/*****************************************
* Projectile
******************************************/
void Projectile::draw(ogstream& gout)
{
   gout.drawProjectile(pt, 0.0);
}

/*****************************************
* Projectile
******************************************/
void Projectile::update(Acceleration accel)
{
   double angle = velocity.computeAngle();
   double totalVelocity = velocity.computeVelocity();
   double p = tableLookUp(vectorFromID(1), vectorFromID(2), pt.getMetersY());
   double vSound = tableLookUp(vectorFromID(1), vectorFromID(3), pt.getMetersY());
   double vMach = totalVelocity / vSound;
   double c = tableLookUp(vectorFromID(5), vectorFromID(6), vMach);
   double force = dragForce(c, p, totalVelocity, AREA);
   double acc = (force / MASS);
   accel.setDDX(horizontalComp(-acc, angle));
   accel.setDDY(-tableLookUp(vectorFromID(1), vectorFromID(4), pt.getMetersY()) + verticalComp(-acc, angle));


   pt.setMetersX(pt.computeNewPosition(pt.getMetersX(), velocity.getDX(), accel.getDDX(), TIME));
   pt.setMetersY(pt.computeNewPosition(pt.getMetersY(), velocity.getDY(), accel.getDDY(), TIME));
   velocity.updateVelocity(accel, TIME);

}

/*****************************************
* Projectile
******************************************/
void Projectile::reset()
{
   pt.setPixelsX(300.0);
   pt.setPixelsY(300.0);
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
