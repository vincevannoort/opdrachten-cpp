// template

#include <iostream>

#include "window.hpp"
#include "filled_rectangle.hpp"

int main(int argc, char **argv){
   window w( 400, 400, 1 );
   
   filled_rectangle filled_rectangle_1( w, 5, 5, 30, 40 );
   filled_rectangle_1.print();
   
   filled_rectangle filled_rectangle_2( w, 40, 40, 200, 200 );
   filled_rectangle_2.print();
   
   filled_rectangle filled_rectangle_3( w, 200, 300, 300, 400 );
   filled_rectangle_3.print();

   return 0;
}
