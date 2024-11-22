/***********************************************************************
 * Source File:
 *    Starlink
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Starlink satellite which inherits from the base Satellite
 ************************************************************************/

#include "satelliteStarlink.h"
#include "uiDraw.h"

/*********************************************
 * Starlink : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void Starlink::draw(ogstream& gout)
{
   gout.drawStarlink(pos, direction.getDegrees());
}
