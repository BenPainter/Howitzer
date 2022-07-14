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
   Projectile() { reset(); };
   Projectile(const Position &pt) { this->pt = pt;  }
   void draw(ogstream& gout);

   bool isAlive() const { return status == ALIVE; }
   bool isHit()   const { return status == HIT; }
   bool isReady() const { return status == READY; }

   Position getPT() const { return pt; }
   void setPT(Position pt) { this->pt = pt; }
   void update(Acceleration accel);
   
   void reset();

   void hitTargert();
   void missTarget();
   void fired(Position newPT, const double& newAngle);

};

