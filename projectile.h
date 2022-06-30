#pragma once
#include "position.h"
#include "velocity.h"
#include "uiDraw.h"
#include <vector>

using namespace std;
class Projectile
{
private:
   Position pt;
   Velocity v;
   vector<Position> tail;
   enum Status { ALIVE, HIT, MISS };
   Status status;
   void updateTail();

public:
   Projectile() { reset(); };
   Projectile(Position pt) { this->pt = pt;  };
   void draw(ogstream& gout);

   bool isAlive();
   bool isHit();
   bool isMiss();

   void setPT(Position pt);
   void update(Acceleration accel);
   void reset();

   void hitTargert();
   void missTarget();

};

