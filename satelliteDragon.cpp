/***********************************************************************
 * Source File:
 *    Dragon
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Dragon derived class
 ************************************************************************/

#include "satelliteDragon.h"
#include "uiDraw.h"

/*********************************************
 * CrewDragon : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void CrewDragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(pos, direction.getDegrees());
}
