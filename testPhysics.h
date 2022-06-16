#pragma once
#pragma once
/***********************************************************************
 * Header File:
 *    Test Physics Functions: Test the physics functions
 * Author:
 *    Star Balls & Ben Painter
 * Summary:
 *    All the unit tests for physics functions
 ************************************************************************/


#include <iostream>
#include <cassert>

using namespace std;

/*******************************
 * TEST Physics Functions
 * A class for the physics functions which contains those functions' unit tests
 ********************************/
class Test
{
public:
   void run()
   {
      
   }

private:
   // utility funciton because floating point numbers are approximations
   bool closeEnough(double value, double test, double tolerence) const
   {
      double difference = value - test;
      return (difference >= -tolerence) && (difference <= tolerence);
   }

};
