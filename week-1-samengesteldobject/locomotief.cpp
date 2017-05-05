#include "locomotief.hpp"
#include "circle.hpp"
#include "window.hpp"
#include <stdio.h>

locomotief::locomotief(window & w, int start_x, int start_y, int size, bool extra_cabin):
	start_x(start_x), start_y(start_y), size(size), extra_cabin(extra_cabin),
	body(w, start_x, size*.3, size, size*.7), cabin(w, start_x+size*.55, 0, size*.9, size*.7), chimney(w, start_x+size*.2, size*.1, size*.3, size*.5),
	small_wheel_one(w, start_x+size*.1, size*.725, size*.1), small_wheel_two(w, start_x+size*.35, size*.725, size*.1), big_wheel(w, (start_x+size*.75)-1, size*.575, size*.25),
	
	wagon_item(w, start_x+size+50, size*.3, size+size+50, size*.7), link(w, start_x+50, size*.5, size+50, size*.55),
	wheel_one(w, start_x+size+50+size*.2, size*.725, size*.1), wheel_two(w, start_x+size+50+size*.8, size*.725, size*.1),
	
	w(w)
{}

void locomotief::print() {
	body.print();
	cabin.print();
	chimney.print();
	small_wheel_one.print();
	small_wheel_two.print();
	big_wheel.print();
	if (extra_cabin) {
		wagon_item.print();
		link.print();
		wheel_one.print();
		wheel_two.print();
	}
}

