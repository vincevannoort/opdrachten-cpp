#include <iostream> 
#include "hwlib.hpp"
#include "pin_in_and_decorator.hpp"

using namespace std;

/// @brief
/// Main function that tests the pin_in_and_decorator
int main( void ){	
   auto input1 = hwlib::target::pin_in( hwlib::target::pins::d3 );
   auto input2 = hwlib::target::pin_in( hwlib::target::pins::d2 );
   pin_in_and_decorator test_pins(input1, input2);
   
   cout << "Testing the pin_in_and_decorator" << test_pins.get();
}