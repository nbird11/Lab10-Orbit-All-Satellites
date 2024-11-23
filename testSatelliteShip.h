/***********************************************************************
 * Header File:
 *    TEST SHIP
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for the ship
 ************************************************************************/
#pragma once

#include "satelliteShip.h"
#include "unitTest.h"

class TestShip : public UnitTest
{
public:
   void run()
   {
      move_thrust();
      move_no_thrust();

      report("Ship");
   }
private:
   /************************************
    * MOVE : THRUST
    *  Move the ship while thrusting
    ************************************/
   void move_thrust()
   {  // setup
      Ship s;
      s.isThrusting = true;
      s.pos.x = 500000000;
      s.pos.y = 500000000;
      s.velocity.dx = 0;
      s.velocity.dy = 0;
      s.direction.radians = 0;
      double dt = 48;

      // exercise
      s.move(dt);

      // verify
      // s_t = s_0 + v(t) + a(t * t)
      assertUnit(s.isThrusting == true);
      assertEqualsTolerance(s.pos.x,  499999998.7, .001);
      assertEqualsTolerance(s.pos.y,  500004606.7, .001);
      assertEqualsTolerance(s.velocity.dx, 0.0, .1);
      assertEqualsTolerance(s.velocity.dy, 96.0, .1);
      assertUnit(dt == 48);
      assertUnit(s.direction.radians == 0);
   }  // teardown

   void move_no_thrust()
   {  // setup
      Ship s;
      s.isThrusting = false;
      s.pos.x = 500000000;
      s.pos.y = 500000000;
      s.velocity.dx = 0;
      s.velocity.dy = 0;
      s.direction.radians = 0;
      double dt = 48;

      // exercise
      s.move(dt);

      // verify
      assertUnit(s.isThrusting == false);
      assertEqualsTolerance(s.pos.x, 499999998.7, .001);
      assertEqualsTolerance(s.pos.y, 499999998.7, .001);
      assertEqualsTolerance(s.velocity.dx, 0.0, .1);
      assertEqualsTolerance(s.velocity.dy, 0.0, .1);
      assertUnit(dt == 48);
      assertUnit(s.direction.radians == 0);
      
   }
};