// example:
// declaration of a window class

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "windows.h"
#include "vector.hpp"

class window {
   vector size;
   int scale;
   
   // needed to use the OS window
   HDC hdc;
   
public:
   window( const vector & size, int scale );
   void draw( const vector & pixel, const bool & black = true);
   void clear();
};

void wait_ms( int n );

#endif // WINDOW_HPP
