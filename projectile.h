#pragma once
#include "position.h"
#include "velocity.h"
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

};

