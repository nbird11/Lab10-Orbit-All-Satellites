/***********************************************************************
 * Source File:
 *    Ship
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Ship controlled by the player
 ************************************************************************/

#include "acceleration.h"
#include "satellite.h"
#include "satelliteShip.h"
#include "uiDraw.h"
#include "uiInteract.h"
#include "velocity.h"
#include <cmath>

/*****************************************************
 * Ship : CONSTRUCTOR
 *  Constructs the ship in top left corner of screen
 *****************************************************/
Ship::Ship() : Satellite()
{
   radius = 10.0;
   pos.setPixelsX(-450.0);
   pos.setPixelsY(450.0);
   velocity = Velocity(0.0, -2000.0);
   isThrusting = false;
}

/*****************************************************
 * Ship : INPUT
 *  Changes orientation of the ship from keyboard input
 *****************************************************/
void Ship::input(const Interface* pUI, double time)
{
   if (pUI->isRight())
   {
      direction.add(0.1);
   }
   if (pUI->isLeft())
   {
      direction.add(-0.1);
   }
   isThrusting = pUI->isDown();
   move(time);
}

void Ship::move(double time)
{
   double thrust = 2.0;  // m/s^2
   double gravity = getGravity();
   double directionGravity = directionOfPull();

   double ddx, ddy;
   ddx = gravity * sin(directionGravity);
   ddy = gravity * cos(directionGravity);

   if (isThrusting)
   {
      ddx += thrust * sin(direction.getRadians());
      ddy += thrust * cos(direction.getRadians());
   }
   Acceleration accel(ddx, ddy);

   velocity.add(accel, time / 2.0);
   pos.add(velocity, accel, time);
   velocity.add(accel, time / 2.0);
}

/*********************************************
 * Ship : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void Ship::draw(ogstream& gout)
{
   gout.drawShip(pos, direction.getRadians(), isThrusting);
}
