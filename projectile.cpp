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
bool Projectile::isAlive()
{
   return status == ALIVE;
}

/*****************************************
* Projectile
******************************************/
bool Projectile::isHit()
{
   return false;
}

/*****************************************
* Projectile
******************************************/
bool Projectile::isMiss()
{
   return false;
}

/*****************************************
* Projectile
******************************************/
void Projectile::setPT(Position pt)
{
}

/*****************************************
* Projectile
******************************************/
void Projectile::update(Acceleration accel, const double &newAngle)
{
   velocity.setDX(horizontalComp(827.0, newAngle));
   velocity.setDY(verticalComp(827.0, newAngle));

   pt.setMetersX(pt.computeNewPosition(pt.getMetersX(), velocity.getDX(), 1.0, 0.1));
   pt.setMetersY(pt.computeNewPosition(pt.getMetersY(), velocity.getDY(), 1.0, 0.1));
   velocity.updateVelocity(accel, 0.1);

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
}

/*****************************************
* Projectile
******************************************/
void Projectile::missTarget()
{
}

/*****************************************
* Projectile
******************************************/
void Projectile::fired(Position newPT)
{
   status = ALIVE;
   pt = newPT;
}
