/*************************************************************
 * 1. Name:
 *      Nathan Bird, Jared Davey, Brock Hoskins
 * 2. Assignment Name:
 *      Lab 10: Orbit Simulator
 * 3. Assignment Description:
 *      Implement the code and unit tests for all Satellites.
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include "position.h"   // for POSITION
#include "satellite.h"
#include "satelliteGPS.h"
#include "satelliteDragon.h"
#include "satelliteHubble.h"
#include "satelliteShip.h"
#include "satelliteSputnik.h"
#include "satelliteStarlink.h"
#include "test.h"
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "uiInteract.h" // for INTERFACE
#include "velocity.h"
#include <vector>
using namespace std;

#define PI           3.14159265358979
#define ORBITAL_VEL  3100            // m/s DELETEME


/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
public:
   Demo(Position ptUpperRight) :
      ptUpperRight(ptUpperRight),
      timePerFrame(24.0 /*hoursPerDay*/ * 60.0 /*minutesPerHour*/ / 30.0 /*frameRate*/)
   {
      satellites.push_back(new Sputnik(Position(-36515095.13, 21082000.0), Velocity(2050.0, 2684.68)));

      satellites.push_back(new GPS(Position(0.0, 26560000.0), Velocity(-3880.0, 0.0)));
      satellites.push_back(new GPS(Position(0.0, -26560000.0), Velocity(3880.0, 0.0)));
      satellites.push_back(new GPS(Position(23001634.72, 13280000.0), Velocity(-1940.00, 3360.18)));
      satellites.push_back(new GPS(Position(23001634.72, -13280000.0), Velocity(1940.00, 3360.18)));
      satellites.push_back(new GPS(Position(-23001634.72, -13280000.0), Velocity(1940.00, -3360.18)));
      satellites.push_back(new GPS(Position(-23001634.72, 13280000.0), Velocity(-1940.00, -3360.18)));

      satellites.push_back(new Hubble(Position(0.0, 42164000.0), Velocity(-3100, 0.0)));

      satellites.push_back(new CrewDragon(Position(0.0, 8000000.0), Velocity(-7900.0, 0.0)));

      satellites.push_back(new Starlink(Position(0.0, -13020000.0), Velocity(5800.0, 0.0)));

      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

      angleEarth = 0.0;
      phaseStar = 0;
   }

   vector<Satellite*> satellites;
   Ship ship;
   Position ptStar;
   Position ptUpperRight;

   double timePerFrame;
   unsigned char phaseStar;
   double angleEarth;
};

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Demo* pDemo = (Demo*)p;

   //
   // perform all the game logic
   //

   // rotate the earth
   double rpf = -(2 * PI / 30.0 /*frameRate*/) * (pDemo->timePerFrame*30.0 / 86400 /*secondsPerDay*/);

   pDemo->angleEarth += rpf;
   pDemo->phaseStar++;

   // 
   // move
   //
   pDemo->ship.input(pUI, pDemo->timePerFrame);
   for (Satellite* sat : pDemo->satellites)
   {
      sat->move(pDemo->timePerFrame);
   }

   //
   // draw everything
   //
   ogstream gout;

   for (Satellite* sat : pDemo->satellites)
      sat->draw(gout);
   pDemo->ship.draw(gout);

   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);

   // draw the earth
   Position pt;
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PWSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

   testRunner();

   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
      "Demo",   /* name on the window */
      ptUpperRight);

   // Initialize the demo
   Demo demo(ptUpperRight);

   // set everything into action
   ui.run(callBack, &demo);


   return 0;
}
