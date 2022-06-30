#pragma once


#include <iostream>
#include <cassert>
#include <math.h>  
#include "physics.h"

using namespace std;

/*******************************
 * TEST Physics Functions
 * A class for the physics functions which contains those functions' unit tests
 ********************************/
class TestPhysics
{

public:
   void run()
   {
      linearInter_zero();
      linearInter_simple();
      linearInter_negative();
      linearInter_byBeginValue();
      linearInter_byEndValue();
      linearInter_soundTest();

      verticalComp_zero();
      verticalComp_zeroAngle();
      verticalComp_noS();
      verticalComp_rightAngle();
      verticalComp_middleAngle();
      verticalComp_negativeAngle();

      horizontalComp_zero();
      horizontalComp_zeroAngle();
      horizontalComp_noS();
      horizontalComp_rightAngle();
      horizontalComp_middleAngle();
      horizontalComp_negativeAngle();

      dragForce_zero();
      dragForce_velocity();
      dragForce_coefficient();
      dragForce_airDensity();
      dragForce_area();
      dragForce_simple();
      dragForce_realTime();
   }

private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }


   // Testing linearInter with the following methods 
   void linearInter_simple() const
   {
      // setup
      double d = 2.0;
      double d0 = 1.0;
      double d1 = 3.0;
      double r0 = 1.0;
      double r1 = 3.0;
      double r;
      // exercise
      r = linearInter(d, d0, r0, d1, r1);
      // verify
      assert(r == 2.0);
   }// teardown

   void linearInter_zero() const
   {
      // setup
      double d = 0.0;
      double d0 = 0.0;
      double d1 = 0.0;
      double r0 = 0.0;
      double r1 = 0.0;
      double r;
      // exercise
      r = linearInter(d, d0, r0, d1, r1);
      // verify
      assert(r == r0);

   }// teardown

   void linearInter_negative() const
   {
      // setup
      double d = -2.0;
      double d0 = -1.0;
      double d1 = -3.0;
      double r0 = -1.0;
      double r1 = -3.0;
      double r;
      // exercise
      r = linearInter(d, d0, r0, d1, r1);
      // verify
      assert(r == -2.0);
   }// teardown

   void linearInter_byEndValue() const
   {
      // setup
      double d = 2.8;
      double d0 = 1.0;
      double d1 = 3.0;
      double r0 = 1.0;
      double r1 = 3.0;
      double r;
      // exercise
      r = linearInter(d, d0, r0, d1, r1);
      // verify
      assert(r == 2.8);
   }// teardown

   void linearInter_byBeginValue() const
   {
      // setup
      double d = 1.2;
      double d0 = 1.0;
      double d1 = 3.0;
      double r0 = 1.0;
      double r1 = 3.0;
      double r;
      // exercise
      r = linearInter(d, d0, r0, d1, r1);
      // verify
      assert(r == 1.2);
   }// teardown

   void linearInter_soundTest() const
   {
      // setup
      double d = 500.0;
      double d0 = 0.0;
      double d1 = 1000.0;
      double r0 = 340.0;
      double r1 = 336.0;
      double r;
      // exercise
      r = linearInter(d, d0, r0, d1, r1);
      // verify
      assert(r == 338.0);
   }// teardown


   // Testing verticalComp with the following methods 
   void verticalComp_zero() const
   {
      // setup
      double s = 0.0;
      double angle = 0.0;
      double ddy;
      // exercise
      ddy = verticalComp(s, angle);
      // verify
      assert(ddy == 0);
   } // teardown

   void verticalComp_noS() const
   {
      // setup
      double s = 0.0;
      double angle = 90.0;
      double ddy;
      // exercise
      ddy = verticalComp(s, angle);
      // verify
      assert(ddy == 0);
   } // teardown

   void verticalComp_zeroAngle() const
   {
      // setup
      double s = 1.0;
      double angle = 0.0;
      double ddy;
      // exercise
      ddy = verticalComp(s, angle);
      // verify
      assert(ddy == 1);
   } // teardown

   void verticalComp_rightAngle() const
   {
      // setup
      double s = 1.0;
      double angle = 1.5708;                                        // 90 degrees = 1.5708 radians
      double ddy;
      // exercise
      ddy = verticalComp(s, angle);
      // verify  
      assert(closeEnough(0, ddy, 0.001));
   } // teardown                                 

   void verticalComp_middleAngle() const
   {
      // setup
      double s = 1.0;
      double angle = 0.785398;                                     // 45 degrees = 0.785398 radians
      double ddy;
      // exercise
      ddy = verticalComp(s, angle);
      // verify
      assert(closeEnough(0.707106, ddy, 0.001));
   } // teardown

   void verticalComp_negativeAngle() const
   {
      // setup
      double s = 1.0;
      double angle = -0.785398;                                   // -45 degrees = -0.785398 radians
      double ddy;
      // exercise
      ddy = verticalComp(s, angle);
      // verify
      assert(closeEnough(0.707106, ddy, 0.001));
   } // teardown

   // Testing horizontalComp with the following methods 
   void horizontalComp_zero() const
   {
      // setup
      double s = 0.0;
      double angle = 0.0;
      double ddx;
      // exercise
      ddx = horizontalComp(s, angle);
      // verify
      assert(ddx == 0);
   } // teardown

   void horizontalComp_noS() const
   {
      // setup
      double s = 0.0;
      double angle = 90.0;
      double ddx;
      // exercise
      ddx = horizontalComp(s, angle);
      // verify
      assert(ddx == 0);
   } // teardown

   void horizontalComp_zeroAngle() const
   {
      // setup
      double s = 1.0;
      double angle = 0.0;
      double ddx;
      // exercise
      ddx = horizontalComp(s, angle);
      // verify
      assert(ddx == 0);
   } // teardown

   void horizontalComp_rightAngle() const
   {
      // setup
      double s = 1.0;
      double angle = 1.5708;                                    // 90 degrees = 1.5708 radians
      double ddx;
      // exercise
      ddx = horizontalComp(s, angle);
      // verify
      assert(closeEnough(1, ddx, 0.001));
   } // teardown

   void horizontalComp_middleAngle() const
   {
      // setup
      double s = 1.0;
      double angle = 0.785398;                                   // 45 degrees = 0.785398 radians
      double ddx;
      // exercise
      ddx = horizontalComp(s, angle);
      // verify
      assert(closeEnough(0.70710667, ddx, 0.001));
   } // teardown

   void horizontalComp_negativeAngle() const
   {
      // setup
      double s = 1.0;
      double angle = -0.785398;                                    // -45 degrees = -0.785398 radians
      double ddx;
      // exercise
      ddx = horizontalComp(s, angle);
      // verify
      assert(closeEnough(-0.707106, ddx, 0.001));
   } // teardown

   // Testing dragForce with the following methods 
   void dragForce_zero() const
   {
      // setup
      double c = 0.0;
      double p = 0.0;
      double v = 0.0;
      double a = 0.0;
      double drag;
      // exercise
      drag = dragForce(c, p, v, a);
      // verify
      assert(drag == 0);
   }  // teardown

   void dragForce_coefficient() const
   {
      // setup
      double c = 2.0;
      double p = 1.0;
      double v = 1.0;
      double a = 1.0;
      double drag;
      // exercise
      drag = dragForce(c, p, v, a);
      // verify
      assert(drag == 1);
   }  // teardown

   void dragForce_airDensity() const
   {
      // setup
      double c = 1.0;
      double p = 2.0;
      double v = 1.0;
      double a = 1.0;
      double drag;
      // exercise
      drag = dragForce(c, p, v, a);
      // verify
      assert(drag == 1);
   }  // teardown

   void dragForce_velocity() const
   {
      // setup
      double c = 1.0;
      double p = 1.0;
      double v = 2.0;
      double a = 1.0;
      double drag;
      // exercise
      drag = dragForce(c, p, v, a);
      // verify
      assert(drag == 2);
   }  // teardown

   void dragForce_area() const
   {
      // setup
      double c = 1.0;
      double p = 1.0;
      double v = 1.0;
      double a = 2.0;
      double drag;
      // exercise
      drag = dragForce(c, p, v, a);
      // verify
      assert(drag == 1);
   }  // teardown

   void dragForce_simple() const
   {
      // setup
      double c = 1.0;
      double p = 2.0;
      double v = 3.0;
      double a = 4.0;
      double drag;
      // exercise
      drag = dragForce(c, p, v, a);
      // verify
      assert(drag == 36);
   }  // teardown

   void dragForce_realTime() const // using data from the tables
   {
      // setup
      double c = 0.25953958;
      double p = 1.225;
      double v = 827.0;
      double a = 0.01884;
      double drag;
      // exercise
      drag = dragForce(c, p, v, a);
      // verify
      assert(closeEnough(2048.33793, drag, 0.001));
   }  // teardown
};