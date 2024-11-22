/***********************************************************************
 * Header File:
 *    Ship
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The Ship controlled by the player
 ************************************************************************/
#pragma once
#include "satellite.h"
#include "uiInteract.h"
#include <cassert>
#include <vector>

class Position;
class Velocity;
class ogstream;

class TestShip;

/***************************************************
 * Ship
 * The Starlink type derived from Satellite
 ***************************************************/
class Ship : public Satellite
{
public:
   friend TestShip;

   Ship();
   ~Ship() { }

   void input(const Interface* pUI);
   void addThrust();
   //void move(double time) override;

   void draw(ogstream& gout) override;
   void destroy(const std::vector<Satellite*>& satellites) override { assert(NOT_IMPLEMENTED); }
private:
   bool isThrusting;
   double thrustDuration;
};

