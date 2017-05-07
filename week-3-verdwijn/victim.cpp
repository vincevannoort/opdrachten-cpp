#include "victim.hpp"
#include <stdio.h>

victim::victim( window & w, const vector & start, const vector & end ):
rectangle( w, start, end )
{}

void victim::interact( drawable & other ){
   if( this != & other){
      if( overlaps( other )){
         printf("TOUCHED!");
		 other.adjust_based_on_touch();
      }
   }
}

