#pragma once
#include "position.h"
#include "velocity.h"
#include "uiDraw.h"
#include "physics.h"
#include <vector>
#define MASS 46.7
#define RADIUS 0.077445
#define AREA 0.018842
#define INITIAL_VELOCITY 827.0
#define TIME 1



using namespace std;
class Projectile
{
private:
   Position pt;
   Velocity velocity;
   vector<Position> tail;
   enum Status { ALIVE, HIT, READY };
   Status status;
   void updateTail();

public:
   Projectile() { reset(); };
   Projectile(Position pt) { this->pt = pt;  };
   void draw(ogstream& gout);

   bool isAlive() { return status == ALIVE; };
   bool isHit()   { return status == HIT; };
   bool isReady() { return status == READY; };

   Position getPT() { return pt; };
   void setPT(Position pt) { this->pt = pt; };
   void update(Acceleration accel);
   void reset();

   void hitTargert();
   void missTarget();
   void fired(Position newPT, const double& newAngle);

};

