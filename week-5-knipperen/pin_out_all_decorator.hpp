#ifndef PIN_OUT_ALL_DECORATOR_HPP
#define PIN_OUT_ALL_DECORATOR_HPP
#include "hwlib.hpp"

/// @brief
/// Class decorator for setting all pins at once
class pin_out_all_decorator : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 8 ];     
   
public:
   pin_out_all_decorator( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy,
      hwlib::pin_out & p4 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p5 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p6 = hwlib::pin_out_dummy,
	  hwlib::pin_out & p7 = hwlib::pin_out_dummy
   );
   
   void set( bool v, hwlib::buffering buf );
};

#endif // PIN_OUT_ALL_DECORATOR_HPP
