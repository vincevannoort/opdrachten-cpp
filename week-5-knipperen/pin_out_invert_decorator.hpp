#ifndef PIN_OUT_INVERT_DECORATOR_HPP
#define PIN_OUT_INVERT_DECORATOR_HPP
#include "hwlib.hpp"

/// @brief
/// Class decorator for inverting out pins (only set function changed)
class pin_out_invert_decorator : public hwlib::pin_out {
private:
   hwlib::pin_out & slave;
public:
   pin_out_invert_decorator( hwlib::pin_out & slav );
   void set( bool x, hwlib::buffering buf ) override;
};

#endif // PIN_OUT_INVERT_DECORATOR_HPP
