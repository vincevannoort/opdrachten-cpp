#ifndef PIN_IN_AND_DECORATOR_HPP
#define PIN_IN_AND_DECORATOR_HPP

#include "hwlib.hpp"

/// @brief
/// Decorated class for two pin and their and operator
class pin_in_and_decorator: public hwlib::pin_in {
protected:
	hwlib::pin_in & first_p, & second_p;
public:
	pin_in_and_decorator(hwlib::pin_in & first_p, hwlib::pin_in & second_p);
	bool get(hwlib::buffering buf = hwlib::buffering::unbuffered);
};

#endif // PIN_IN_AND_DECORATOR_HPP
