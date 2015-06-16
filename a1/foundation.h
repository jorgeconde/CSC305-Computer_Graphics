#ifndef foundation_h
#define foundation_h

#define EPSILON 0.00001
#define SEP << " " <<
#define NL  << "\n"

using namespace std;

// I can't seem to make the -LANG:bool=ON switch work so :

//---------------------------------------------------------------------------
// if C++ type `bool' is not defined with compiler being used ...

#ifdef NOBOOL
typedef int bool;

#define true  1
#define false 0
#endif


//---------------------------------------------------------------------------

#include <stddef.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <time.h>

class Vec2d
{
public:
    double x, y;
    Vec2d() { x = y = 0; }
    Vec2d(double x_in, double y_in) { x = x_in; y = y_in;}
    Vec2d(const Vec2d & rhs) { x = rhs.x; y = rhs.y; }
    //TODO: Overload +=

  };

//TODO: Overload *



#endif

