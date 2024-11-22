/***********************************************************************
 * Header File:
 *    Starlink
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The starlink satellite which inherits from the base Satellite
 ************************************************************************/

#pragma once
#include "satellite.h"
#include <cassert>
#include <vector>

class Position;
class Velocity;
class ogstream;

class TestStarlink;

/***************************************************
 * Starlink
 * The Starlink type derived from Satellite
 ***************************************************/
class Starlink : public Satellite
{
public:
   friend TestStarlink;

   Starlink() : Satellite() { radius = 6.0; }
   Starlink(const Position& pos, const Velocity& vel) : Satellite(pos, vel) { radius = 6.0; }
   ~Starlink() { }

   void draw(ogstream& gout) override;
   void destroy(const std::vector<Satellite*>& satellites) override { assert(NOT_IMPLEMENTED); }
};

