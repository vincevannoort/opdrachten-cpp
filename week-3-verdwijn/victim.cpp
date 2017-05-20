#include "victim.hpp"
#include <stdio.h>

victim::victim( window & w, const vector & start, const vector & end ):
rectangle( w, start, end )
{}

void victim::adjust_based_on_touch() {
//	int sx = start.x;
//	int sy = start.y;
//	int ex = end.x; 
//	int ey = end.y;
//	int mx = (start.x + end.x) / 2;
//	int my = (start.y + end.y) / 2;
//	start = vector(60,60);
//	end = vector(60,60);
}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         printf("TOUCHED!");
		 adjust_based_on_touch();
      }
   }
}