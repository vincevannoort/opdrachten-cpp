#include "pin_in_and_decorator.hpp"

/// @brief
/// Constructor for pin_in_and_decorator
/// @param hwlib::pin_in & first_p, first pin to use
/// @param hwlib::pin_in & second_p, second pin to use
pin_in_and_decorator::pin_in_and_decorator(hwlib::pin_in & first_p, hwlib::pin_in & second_p):
first_p(first_p), second_p(second_p)
{}

/// @brief
/// Get function that returns only true if both of the pins return true aswell
/// @param hwlib::buffering buf, buffer passed for the function
/// @return bool, only return true if both of the pins return true aswell
bool pin_in_and_decorator::get(hwlib::buffering buf) {
	return (!first_p.get() && !second_p.get());
}
