#pragma once
/***********************************************************************
 * Header File:
 *    Test Velocity : Test the Velocity class
 * Author:
 *    Star Balls & Ben Painter
 * Summary:
 *    All the unit tests for Velocity
 ************************************************************************/


#include <iostream>
#include "velocity.h"
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
      nonDefaultConstructor();

      getVelocity();
      setVelocity();

      computeVelocity_allZeros();
      computeVelocity_decmial();
      computeVelocity_standard();

      addVelocity_decimalTime();
      addVelocity_negativeAccel();
      addVelocity_noAcceleration();
      addVelocity_noTime();
      addVelocity_simpleTimeAndAccel();
      addVelocity_zero();
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
      Velocity vel;
      // verify
      assert(vel.dx == 0.0);
      assert(vel.dy == 0.0);
   }  // teardown

   void nonDefaultConstructor() const
   {
      // setup
      // exercise
      Velocity vel(1.0, 2.0);
      // verify
      assert(vel.dx == 1.0);
      assert(vel.dy == 2.0);
   }  // teardown
   
   void getVelocity() const
   {
      //setup
      Velocity vel;
      vel.dx = 5.0;
      vel.dy = 8.0;
      double dx;
      double dy;
      // exercise
      dx = vel.getDX();
      dy = vel.getDY();
      //verify
      assert(dx == 5.0);
      assert(dy == 8.0);
   } // teardown

   void setVelocity() const
   {
      //setup
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      // exercise
      vel.setDX(5.0);
      vel.setDY(8.0);
      //verify
      assert(vel.dx == 5.0);
      assert(vel.dy == 8.0);
   } // teardown

   // Testing computeVelocity with the following methods 
   void computeVelocity_allZeros() const
   {
      // setup
      Velocity vel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      double totalVelocity;
      // exercise
      totalVelocity = vel.computeVelocity();
      // verify
      assert(totalVelocity == 0.0);
   } // teardown

   void computeVelocity_standard() const
   {
      // setup
      Velocity vel;
      vel.dx = 3.0;
      vel.dy = 4.0;
      double totalVelocity;
      // exercise
      totalVelocity = vel.computeVelocity();
      // verify
      assert(totalVelocity == 5.0);
   } // teardown

   void computeVelocity_decmial() const
   {
      // setup
      Velocity vel;
      vel.dx = 27.4;
      vel.dy = -1.8;
      double totalVelocity;
      // exercise
      totalVelocity = vel.computeVelocity();
      // verify
      assert(closeEnough(27.4590604, totalVelocity, 0.001));
   } // teardown

   // Testing addVelocity with the following methods 
   void addVelocity_zero() const
   {
      // setup
      Velocity vel;
      Acceleration accel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      accel.setDDX(0.0);
      accel.setDDY(0.0);
      double time = 0.0;
      // exercise
      vel.addVelocity(accel, time);
      // verify
      assert(vel.dx == 0.0);
      assert(vel.dy == 0.0);
   }

   void addVelocity_noAcceleration() const
   {
      // setup
      Velocity vel;
      Acceleration accel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      accel.setDDX(0.0);
      accel.setDDY(0.0);
      double time = 1.0;
      // exercise
      vel.addVelocity(accel, time);
      // verify
      assert(vel.dx == 0.0);
      assert(vel.dy == 0.0);
   }

   void addVelocity_noTime() const
   {
      // setup
      Velocity vel;
      Acceleration accel;
      vel.dx = 0.0;
      vel.dy = 0.0;
      accel.setDDX(1.0);
      accel.setDDY(1.0);
      double time = 0.0;
      // exercise
      vel.addVelocity(accel, time);
      // verify
      assert(vel.dx == 0.0);
      assert(vel.dy == 0.0);
   }

   void addVelocity_simpleTimeAndAccel() const
   {
      // setup
      Velocity vel;
      Acceleration accel;
      vel.dx = 0.0;
      vel.dy = 1.0;
      accel.setDDX(1.0);
      accel.setDDY(1.0);
      double time = 1.0;
      // exercise
      vel.addVelocity(accel, time);
      // verify
      assert(vel.dx == 1.0);
      assert(vel.dy == 2.0);
   }

   void addVelocity_negativeAccel() const
   {
      // setup
      Velocity vel;
      Acceleration accel;
      vel.dx = 1.0;
      vel.dy = 1.0;
      accel.setDDX(1.0);
      accel.setDDY(-1.0);
      double time = 1.0;
      // exercise
      vel.addVelocity(accel, time);
      // verify
      assert(vel.dx == 2.0);
      assert(vel.dy == 0.0);
   }

   void addVelocity_decimalTime() const
   {
      // setup
      Velocity vel;
      Acceleration accel;
      vel.dx = 0.0;
      vel.dy = 1.0;
      accel.setDDX(1.0);
      accel.setDDY(1.0);
      double time =.5;
      // exercise
      vel.addVelocity(accel, time);
      // verify
      assert(vel.dx == 0.5);
      assert(vel.dy == 1.5);
   }

};
