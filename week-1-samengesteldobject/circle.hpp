// example:
// declaration of a circle class that stores its window

#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "window.hpp"

class circle {
private:
   int mid_x;
   int mid_y; 
   int radius;
   window & w;
public:
   circle( window & w, int mid_x, int mid_y, int radius ):
      mid_x( mid_x ),
      mid_y( mid_y ),
      radius( radius ),
      w( w )
   {}
   void print();
};

#endif // CIRCLE_HPP
