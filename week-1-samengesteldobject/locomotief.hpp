#ifndef LOCOMOTIEF_HPP
#define LOCOMOTIEF_HPP

#include "window.hpp"
#include "circle.hpp"
#include "line.hpp"
#include "filled_rectangle.hpp"

class locomotief
{
private:
	int start_x, start_y, size, cabins;
	filled_rectangle body, cabin, chimney;
	circle small_wheel_one, small_wheel_two, big_wheel;
	window & w;
public:
	locomotief(window & w, int start_x, int start_y, int size, int cabins);
	void print();
};

#endif // LOCOMOTIEF_HPP
