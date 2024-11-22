/***********************************************************************
 * Header File:
 *    Dragon
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Dragon derived class
 ************************************************************************/
#pragma once
#include "satellite.h"
#include <cassert>
#include <vector>

class Position;
class Velocity;
class ogstream;

class TestCrewDragon;

/***************************************************
 * CrewDragon
 * The Starlink type derived from Satellite
 ***************************************************/
class CrewDragon : public Satellite
{
public:
   friend TestCrewDragon;

   CrewDragon() : Satellite() { radius = 7.0; }
   CrewDragon(const Position& pos, const Velocity& vel) : Satellite(pos, vel) { radius = 7.0; }
   ~CrewDragon() { }

   void draw(ogstream& gout) override;
   void destroy(const std::vector<Satellite*>& satellites) override { assert(NOT_IMPLEMENTED); }
};
