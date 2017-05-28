#include "hwlib.hpp"

/// OPDRACHT IS NIET HELEMAAL DUIDELIJK VOOR MIJ, VRAAG HET KOMENDE WEEK IN DE LES, HIERONDER EEN ANDERE IMPLEMENTATIE..

int main( void ){	
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;

   // set led pins
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
   
   auto ds   = hwlib::target::pin_out( hwlib::target::pins::d8 );
   auto shcp = hwlib::target::pin_out( hwlib::target::pins::d9 );
   auto stcp = hwlib::target::pin_out( hwlib::target::pins::d10 );
   auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( stcp, ds, hwlib::pin_in_dummy );
   auto hc595 = hwlib::hc595( spi, shcp );

   auto leds = hwlib::port_out_from_pins( 
      led0, 
      led1, 
      led2,
	  led3,
	  hc595.p1, 
      hc595.p2, 
      hc595.p3,
	  hc595.p4
   );
   while (1) {
	   leds.set(0x0f);
	   hwlib::wait_ms(1000);
	   leds.set(0xf0);
	   hwlib::wait_ms(1000);
   }
}