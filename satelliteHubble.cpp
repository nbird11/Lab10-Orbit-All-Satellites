/***********************************************************************
 * Source File:
 *    Hubble
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Hubble derived class
 ************************************************************************/

#include "satelliteHubble.h"
#include "uiDraw.h"

/*********************************************
 * Hubble : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void Hubble::draw(ogstream& gout)
{
   gout.drawHubble(pos, direction.getDegrees());
}
