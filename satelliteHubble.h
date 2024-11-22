/***********************************************************************
 * Header File:
 *    Hubble
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Hubble derived class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include <cassert>
#include <vector>

class Position;
class Velocity;
class ogstream;

class TestHubble;

class Hubble : public Satellite
{
public:
   friend TestHubble;

   Hubble() : Satellite() { radius = 10.0; }
   Hubble(const Position& pos, const Velocity& vel) : Satellite(pos, vel) { radius = 10.0; }
   ~Hubble() { }

   void draw(ogstream& gout) override;
   void destroy(const std::vector<Satellite*>& satellites) override { assert(NOT_IMPLEMENTED); }
};

