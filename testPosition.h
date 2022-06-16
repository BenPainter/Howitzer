/***********************************************************************
 * Header File:
 *    Test Position : Test the Position class
 * Author:
 *    Br. Helfrich
 * Summary:
 *    All the unit tests for Position
 ************************************************************************/


#pragma once

#include <iostream>
#include "position.h"
#include <cassert>

using namespace std;

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition
{
public:
   void run()
   {
      Position().setZoom(1000.0 /* 1km equals 1 pixel */);
      defaultConstructor();
      nonDefaultConstructor();
      copyConstructor();
      assignment();
 
      setPixels();
      setMeters();
      
      addPixels();
      addMeters();

      computeNewPosition_accel();
      computeNewPosition_bigTime();
      computeNewPosition_position();
      computeNewPosition_simple();
      computeNewPosition_time();
      computeNewPosition_velocity();
      computeNewPosition_zeros();
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

   void nonDefaultConstructor() const
   {  // setup
      // exercise
      Position pos(3000.0, 9000.0);
      // verify
      assert(pos.x == 3000.0);
      assert(pos.y == 9000.0);
   }  // teardown

   void copyConstructor() const
   {  // setup
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2(pos1);
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
   }  // teardown

   void assignment() const
   {  // setup
      Position pos1;
      pos1.x = 4000.0;
      pos1.y = 2000.0;
      // exercise
      Position pos2 = pos1;
      // verify
      assert(pos1.x == 4000.0);
      assert(pos1.y == 2000.0);
      assert(pos2.x == 4000.0);
      assert(pos2.y == 2000.0);
   }  // teardown
   
   void setMeters() const
   {  // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setMetersX(5000.0);
      pos.setMetersY(3000.0);
      // verify
      assert(pos.x == 5000.0);
      assert(pos.y == 3000.0);
   }  // teardown
 
   void setPixels() const
   {  // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      // exercise
      pos.setPixelsX(6.0);
      pos.setPixelsY(12.0);
      // verify
      assert(pos.x == 6000.0);
      assert(pos.y == 12000.0);
   }  // teardown
   
   void addMeters() const
   {  // setup
      Position pos;
      pos.x = 800.0;
      pos.y = 1600.0;
      // exercise
      pos.addMetersX(-400.0);
      pos.addMetersY(800.0);
      // verify
      assert(pos.x == 400.0);
      assert(pos.y == 2400.0);
   }  // teardown
   
   void addPixels() const
   {  // setup
      Position pos;
      pos.x = 2000.0;
      pos.y = 4000.0;
      // exercise
      pos.addPixelsX(2);
      pos.addPixelsY(3);
      // verify
      assert(pos.x == 4000.0);
      assert(pos.y == 7000.0);
   }  // teardown

   // Testing computeNewPosition with the following methods 

   void computeNewPosition_zeros() const
   {
      // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      double dx = 0.0;
      double dy = 0.0;
      double ddx = 0.0;
      double ddy = 0.0;
      double time = 0.0;
      // exercise
      pos.setMetersX(pos.computeNewPosition(pos.x, dx, ddx, time));
      pos.setMetersY(pos.computeNewPosition(pos.y, dy, ddy, time));
      // verify
      assert(pos.x == 0.0);
      assert(pos.y == 0.0);
   }  // teardown

   void computeNewPosition_time() const
   {
      // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      double dx = 0.0;
      double dy = 0.0;
      double ddx = 0.0;
      double ddy = 0.0;
      double time = 1.0;
      // exercise
      pos.setMetersX(pos.computeNewPosition(pos.x, dx, ddx, time));
      pos.setMetersY(pos.computeNewPosition(pos.y, dy, ddy, time));
      // verify
      assert(pos.x == 0.0);
      assert(pos.y == 0.0);
   }  // teardown

   void computeNewPosition_accel() const
   {
      // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      double dx = 0.0;
      double dy = 0.0;
      double ddx = 1.0;
      double ddy = 2.0;
      double time = 1.0;
      // exercise
      pos.setMetersX(pos.computeNewPosition(pos.x, dx, ddx, time));
      pos.setMetersY(pos.computeNewPosition(pos.y, dy, ddy, time));
      // verify
      assert(pos.x == 0.5);
      assert(pos.y == 1.0);
   }  // teardown

   void computeNewPosition_velocity() const
   {
      // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      double dx = 1.0;
      double dy = 2.0;
      double ddx = 0.0;
      double ddy = 0.0;
      double time = 1.0;
      // exercise
      pos.setMetersX(pos.computeNewPosition(pos.x, dx, ddx, time));
      pos.setMetersY(pos.computeNewPosition(pos.y, dy, ddy, time));
      // verify
      assert(pos.x == 1.0);
      assert(pos.y == 2.0);
   }  // teardown

   void computeNewPosition_position() const
   {
      // setup
      Position pos;
      pos.x = 1.0;
      pos.y = 2.0;
      double dx = 0.0;
      double dy = 0.0;
      double ddx = 0.0;
      double ddy = 0.0;
      double time = 1.0;
      // exercise
      pos.setMetersX(pos.computeNewPosition(pos.x, dx, ddx, time));
      pos.setMetersY(pos.computeNewPosition(pos.y, dy, ddy, time));
      // verify
      assert(pos.x == 1.0);
      assert(pos.y == 2.0);
   }  // teardown

   void computeNewPosition_simple() const
   {
      // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      double dx = 1.0;
      double dy = 2.0;
      double ddx = 1.0;
      double ddy = 2.0;
      double time = 1.0;
      // exercise
      pos.setMetersX(pos.computeNewPosition(pos.x, dx, ddx, time));
      pos.setMetersY(pos.computeNewPosition(pos.y, dy, ddy, time));
      // verify
      assert(pos.x == 1.5);
      assert(pos.y == 3.0);
   }  // teardown

   void computeNewPosition_bigTime() const
   {
      // setup
      Position pos;
      pos.x = 0.0;
      pos.y = 0.0;
      double dx = 1.0;
      double dy = 2.0;
      double ddx = 1.0;
      double ddy = 2.0;
      double time = 10.0;
      // exercise
      pos.setMetersX(pos.computeNewPosition(pos.x, dx, ddx, time));
      pos.setMetersY(pos.computeNewPosition(pos.y, dy, ddy, time));
      // verify
      assert(pos.x == 60.0);
      assert(pos.y == 120.0);
   }  // teardown

};
