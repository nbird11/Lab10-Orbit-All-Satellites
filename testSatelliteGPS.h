/***********************************************************************
 * Source File:
 *    TEST GPS
 * Author:
 *    Brock Hoskins, Jared Davey, Nathan Bird
 * Summary:
 *    Test cases to ensure the GPS functions completely as a derived
 *    class off of Satellite.
 **********************************************************************/
#pragma once

#include "unitTest.h"

class TestGPS : public UnitTest
{
public:
   void run()
   {
      report("GPS");
   }
};

