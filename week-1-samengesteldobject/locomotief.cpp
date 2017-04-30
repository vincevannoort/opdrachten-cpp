#include "locomotief.hpp"
#include "circle.hpp"
#include "window.hpp"
#include <stdio.h>

locomotief::locomotief(window & w, int start_x, int start_y, int size, int cabins):
	start_x(start_x), start_y(start_y), size(size), cabins(cabins),
	body(w, start_x, size*.3, size, size*.7), cabin(w, start_x+size*.55, 0, size*.9, size*.7), chimney(w, start_x+size*.2, size*.1, size*.3, size*.5),
	small_wheel_one(w, start_x+size*.1, size*.725, size*.1), small_wheel_two(w, start_x+size*.35, size*.725, size*.1), big_wheel(w, (start_x+size*.75)+1, size*.575, size*.25),
	w(w)
	{}

void locomotief::print() {
	for (int i = 0; i < cabins; i++) {
		body.print();
		cabin.print();
		chimney.print();
		small_wheel_one.print();
		small_wheel_two.print();
		big_wheel.print();
		printf ("wagon: %d, x: %d \n", i, start_x);
	}
}

