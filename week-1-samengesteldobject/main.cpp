// template

#include <iostream>

#include "window.hpp"
#include "locomotief.hpp"

int main(int argc, char **argv){
   window w( 1800, 400, 1 );
   locomotief loco(w, 0, 0, 400, false);
   loco.print();
   return 0;
}
