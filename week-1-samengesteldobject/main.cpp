// template

#include <iostream>

#include "window.hpp"
#include "locomotief.hpp"

int main(int argc, char **argv){
   window w( 400, 400, 1 );
   locomotief loco(w, 0, 0, 200, 5);
   loco.print();
   return 0;
}
