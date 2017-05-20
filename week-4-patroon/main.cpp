#include "hwlib.hpp"

/// @brief
/// Function for making leds behave like kitts car lights
/// @details
/// Function for making a row of leds behave like kitts car, with a default of 160ms between switching lights.
/// @param port_out & leds, couple of pins in convenient port out pack
/// @param int ms, defaults to 160
void kitt( hwlib::port_out & leds, int ms = 160 ){
   for(;;){
      for( unsigned int i = 0; i < leds.number_of_pins() - 1; ++i ){
         leds.set( 0x03 << i );      
         hwlib::wait_ms( ms );
		 leds.set( 0x00 << i );
      }
      for( unsigned int i = leds.number_of_pins() - 3; i > 0; --i ){
         leds.set( 0x03 << i );      
         hwlib::wait_ms( ms );
      }
   }
}

/// @brief
/// Main function for running the kitt function that makes a row of leds behave like kitts car lights
int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   // set led pins
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );

   auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3 );
   ::kitt( leds );
}