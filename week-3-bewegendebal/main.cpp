#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"

int main(){
   const int window_w = 200;
   const int window_h = 200;
   const int wall_w = 4;
   window w( vector( window_w, window_h ), 2 );
   wall top( w, vector(   0,  0 ), vector( window_w-1, wall_w ), 5 );
   wall right( w, vector( window_w-wall_w-1,  0 ), vector( window_w-1, window_h ), 7 );
   wall bottom( w, vector(   0, window_h-wall_w-1 ), vector( window_w-1, window_h-1 ), 2 );
   wall left( w, vector(   0,  0 ), vector( wall_w, window_h ), 10 );
   ball b( w, vector( 50, 20 ), 9, vector( 1, 1 ));
   
   drawable * objects[] = { &b, &top, &left, &right, &bottom };

   for(;;){
      // Unnecessary clear of whole window
      // w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 0 );
      for( auto & p : objects ){
		  // Only undraw the necessary instead of the whole screen
		  p->undraw();
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

