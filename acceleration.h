/***********************************************************************
 * Header File:
 *    ACCELERATION
 * Author:
 *    Nathan Bird, Brock Hoskins, Jared Davey
 * Summary:
 *    Everything we need to know about acceleration
 ************************************************************************/


#pragma once

class Angle;

class TestAcceleration;
class TestVelocity;
class TestPosition;
class TestLander;

/*********************************************
 * Acceleration
 * Let's get moving
 *********************************************/
class Acceleration
{
   friend TestPosition;
   friend TestVelocity;
   friend TestAcceleration;
   friend TestLander;

public:
   // constructors
   Acceleration() : ddx(0.0), ddy(0.0) { }
   Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy) { }
   Acceleration(const Angle& a, double magnitude) : Acceleration() { set(a, magnitude); }

   // getters
   double getDDX()   const { return ddx; }
   double getDDY()   const { return ddy; }

   // setters                        
   void setDDX(double ddx) { this->ddx = ddx; }
   void setDDY(double ddy) { this->ddy = ddy; }
   void set(const Angle& a, double magnitude);
   void addDDX(double ddx) { this->ddx += ddx; }
   void addDDY(double ddy) { this->ddy += ddy; }
   void add(const Acceleration& rhs);

private:
   double ddx;     // horizontal acceleration
   double ddy;     // vertical acceleration
};