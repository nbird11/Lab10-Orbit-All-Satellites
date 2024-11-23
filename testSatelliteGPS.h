/***********************************************************************
 * Header File:
 *    TEST GPS
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Tests for the GPS
 ************************************************************************/
#pragma once

#include "unitTest.h"
#include "satelliteGPS.h"

class TestGPS : public UnitTest
{
public:
   void run()
   {
      report("GPS");
   }
};