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

Ship::Ship() : Satellite()
{
   radius = 10.0;
   pos.setPixelsX(-450.0);
   pos.setPixelsY(450.0);
   velocity = Velocity(0.0, -2000.0);
   isThrusting = false;
}

void Ship::input(const Interface* pUI)
{
   if (pUI->isRight())
   {
      direction.add(0.005);
   }
   if (pUI->isLeft())
   {
      direction.add(-0.005);
   }
   isThrusting = pUI->isDown();
   if (isThrusting)
   {
      addThrust();
   }
}

void Ship::addThrust()
{
   Acceleration a(direction, 2.0);

   velocity.add(a, thrustDuration / 2.0);
   pos.add(velocity, a, thrustDuration);
   velocity.add(a, thrustDuration / 2.0);
}

//void Ship::move(double time)
//{
//
//}

/*********************************************
 * Ship : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void Ship::draw(ogstream& gout)
{
   gout.drawShip(pos, direction.getDegrees(), isThrusting);
}
