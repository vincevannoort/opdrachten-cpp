#include "hwlib.hpp"
#include "pin_out_all_decorator.hpp"

/// @brief
/// Constructor for setting all pins at once
/// @param hwlib::pin_out & p0
/// @param hwlib::pin_out & p1
/// @param hwlib::pin_out & p2
/// @param hwlib::pin_out & p3
/// @param hwlib::pin_out & p4
/// @param hwlib::pin_out & p5
/// @param hwlib::pin_out & p6
/// @param hwlib::pin_out & p7
pin_out_all_decorator::pin_out_all_decorator(
  hwlib::pin_out & p0, hwlib::pin_out & p1, 
  hwlib::pin_out & p2, hwlib::pin_out & p3, 
  hwlib::pin_out & p4, hwlib::pin_out & p5, 
  hwlib::pin_out & p6, hwlib::pin_out & p7):
  list{ &p0, &p1, &p2, &p3, &p4, &p5, &p6, &p7 }
{}

/// @brief
/// Set function that implements the function for setting all pins at once using a for loop
/// @param bool v, bool used for setting
/// @param hwlib::buffering buf, buffer used by hwlib
void pin_out_all_decorator::set( bool v, hwlib::buffering buf){
  for( auto p : list ){
	  p->set( v );
  }
}

