#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "window.hpp"
#include "vector.hpp"
#include "drawable.hpp"

class circle : public drawable {
protected:
   int radius;
   bool is_black;
public:
   circle( window & w, const vector & midpoint, int radius ):
      drawable( w, midpoint - vector( radius, radius ), vector( radius, radius ) * 2 ),
      radius( radius )
   {}
   void draw() override;
   void undraw() override;
};

#endif // CIRCLE_HPP
