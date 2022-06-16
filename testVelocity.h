#pragma once
/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Star Balls & Ben Painter
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/


#pragma once

#include <iostream>
//#include "velocity.h"
#include <cassert>

using namespace std;

/*******************************
 * TEST Velocity
 * A friend class for Velocity which contains the Velocity unit tests
 ********************************/
class TestVelocity
{
public:
   void run()
   {
      defaultConstructor();
   }

private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

   void defaultConstructor() const
   {  // setup
      // exercise
      Position pos;
      // verify
      assert(pos.x == 0.0);
      assert(pos.y == 0.0);
   }  // teardown


};
