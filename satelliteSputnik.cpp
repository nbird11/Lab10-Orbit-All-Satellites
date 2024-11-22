/***********************************************************************
 * Source File:
 *    Sputnik
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Sputnik derived class
 ************************************************************************/

#include "satelliteSputnik.h"
#include "uiDraw.h"

/*********************************************
 * Sputnik : DRAW
 *  use the passed ogstream to draw itself
 *********************************************/
void Sputnik::draw(ogstream& gout)
{
   gout.drawSputnik(pos, direction.getDegrees());
}
