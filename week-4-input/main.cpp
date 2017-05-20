#include "hwlib.hpp"

/// @brief
/// Function for increasing or decreasing the amount of leds that light up
/// @details
/// Function for increasing or decreasing the amount of leds that light up based on button presses. Amount of leds can not be decreased below 1 or increased above the amount of leds.
/// @param port_out & leds, couple of pins in convenient port out pack
/// @param pin_in & button_plus, pin used for the plus button
/// @param pin_in & button_minus, pin used for the minus button
void increase_or_decrease_leds_with_buttons( hwlib::port_out & leds, hwlib::pin_in & button_plus, hwlib::pin_in & button_minus){
	auto pattern = 0x01;
	while(1) {
	   leds.set(pattern);
	   hwlib::wait_ms( 100 );

	   // restrict the bounds of the amount of leds
	   if (!button_plus.get()) {
		   pattern = ((pattern << 1) | pattern) & 0x0f;
	   } else if (!button_minus.get()) {
		   pattern = ((pattern >> 1) & pattern) | 0x01;
	   }
	}
}

/// @brief
/// Main function for running the increase_or_decrease_leds_with_buttons function that sets up the right pins
int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   // set led pins
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );

   // set button pins
   auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3 );
   auto button_plus = hwlib::target::pin_in( hwlib::target::pins::d3 );
   auto button_minus = hwlib::target::pin_in( hwlib::target::pins::d2 );
   
   increase_or_decrease_leds_with_buttons(leds, button_plus, button_minus);
}