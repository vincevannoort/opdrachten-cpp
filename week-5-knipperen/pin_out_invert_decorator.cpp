#include "hwlib.hpp"
#include "pin_out_invert_decorator.hpp"

/// @brief
/// Constructor for invert decorator
/// @param hwlib::pin_out & slave, slave pin used to set the inverted value
pin_out_invert_decorator::pin_out_invert_decorator( hwlib::pin_out & slave ): 
	slave( slave ){}

/// @brief
/// Set function that implements the invert function
/// @param bool x, bool used for inverting
/// @param hwlib::buffering buf, buffer used by hwlib
void pin_out_invert_decorator::set( bool x, hwlib::buffering buf ) {
	slave.set( ! x );
}  