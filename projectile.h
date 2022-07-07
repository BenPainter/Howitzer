#pragma once
#include "position.h"
#include "velocity.h"
#include "uiDraw.h"
#include "physics.h"
#include <vector>
#define MASS = 46.7;
#define RADIUS = 0.077445;
#define AREA = 0.018842;
#define INITIAL_VELOCITY = 827.0;


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

   bool isAlive();
   bool isHit();
   bool isMiss();

   void setPT(Position pt);
   void update(Acceleration accel, const double &newAngle);
   void reset();

   void hitTargert();
   void missTarget();
   void fired(Position newPT);

};

