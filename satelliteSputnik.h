/***********************************************************************
 * Header File:
 *    Sputnik
 * Author:
 *    Nathan Bird, Jared Davey, Brock Hoskins
 * Summary:
 *    The unbroken Sputnik derived class
 ************************************************************************/

#pragma once
#include "satellite.h"
#include <cassert>
#include <vector>

class Position;
class Velocity;
class ogstream;

/***************************************************
 * Sputnik
 * The Sputnik type derived from Satellite
 ***************************************************/
class Sputnik : public Satellite
{
public:
   Sputnik() : Satellite() { radius = 4.0; }
   Sputnik(const Position& pos, const Velocity& vel) : Satellite(pos, vel) { radius = 4.0; }
   ~Sputnik() { }

   void draw(ogstream& gout) override;
   void destroy(const std::vector<Satellite*>& satellites) override {
      assert(NOT_IMPLEMENTED);
   }
};

