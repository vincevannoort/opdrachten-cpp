#include "hwlib.hpp"
#include "pin_out_invert_decorator.hpp"
#include "pin_out_all_decorator.hpp"

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   // set led pins
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   
   auto led0_invert = pin_out_invert_decorator(led0);
   auto led1_invert = pin_out_invert_decorator(led1);
   auto led2_invert = pin_out_invert_decorator(led2);
   auto led3_invert = pin_out_invert_decorator(led3);
   
   auto ds   = hwlib::target::pin_out( hwlib::target::pins::d8 );
   auto shcp = hwlib::target::pin_out( hwlib::target::pins::d9 );
   auto stcp = hwlib::target::pin_out( hwlib::target::pins::d10 );
   auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( stcp, ds, hwlib::pin_in_dummy );
   auto hc595 = hwlib::hc595( spi, shcp );

   auto leds = pin_out_all_decorator( 
		led0_invert, led1_invert, led2_invert, led3_invert,
		hc595.p1, hc595.p2, hc595.p3, hc595.p4 
   );
		
   hwlib::blink( leds, 200 ); 
}