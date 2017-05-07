#include "ball.hpp"
#include <iostream>
#include <stdio.h>

void ball::update(){
   location += speed;
}

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

void ball::interact( drawable & other ) {
   if( this != & other){
      if( overlaps( other )){
         speed.x *= other.get_bounce().x;
         speed.y *= other.get_bounce().y;
      }
   }
}

void ball::adjust_based_on_touch() {
	radius *= 0.7;
	size *= 0.7; // with overloaded *= operator for vector from week 2.
}