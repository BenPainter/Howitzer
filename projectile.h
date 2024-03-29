#pragma once
#include "position.h"
#include "velocity.h"
#include "uiDraw.h"
#include "physics.h"
#include <list>
#define MASS 46.7
#define RADIUS 0.077445
#define AREA 0.018842
#define INITIAL_VELOCITY 827.0
#define TIME .5

using namespace std;
/********************************************************
* Projectile
* The class that stores all the details of a bullet.
*********************************************************/
class Projectile
{
private:
   Position pt;
   Velocity velocity;
   list<Position> tail;
   enum Status { ALIVE, HIT, READY };
   Status status;
   void updateTail();

public:
   // constructors
   Projectile()                   { reset();      }
   Projectile(const Position &pt) { this->pt = pt;}

   // getter and setter
   Position getPT()         const { return pt;     }
   void setPT(const Position &pt) { this->pt = pt; }

   // status
   bool isAlive() const { return status == ALIVE; }
   bool isHit()   const { return status == HIT;   }
   bool isReady() const { return status == READY; }

   // update status
   void hitTarget() { status = HIT; }
   void missTarget();
   void fired(const Position &newPT, const double& newAngle);
   
   // gameplay loop
   void draw(ogstream& gout);
   void update(Acceleration &accel);
   void reset();
};

