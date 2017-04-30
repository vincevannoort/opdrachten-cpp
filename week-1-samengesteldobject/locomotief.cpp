#include "locomotief.hpp"
#include "circle.hpp"
#include "window.hpp"
#include <stdio.h>

locomotief::locomotief(window & w, int start_x, int start_y, int size, int cabins):
	start_x(start_x), start_y(start_y), size(size), cabins(cabins),
	body(w, start_x, size*.3, size, size*.7), cabin(w, start_x+size*.55, 0, size*.9, size*.7), chimney(w, start_x+size*.2, size*.1, size*.3, size*.5),
	small_wheel_one(w, start_x+size*.1, size*.725, size*.1), small_wheel_two(w, start_x+size*.35, size*.725, size*.1), big_wheel(w, (start_x+size*.75)-1, size*.575, size*.25),
	w(w)
	{}
	
void locomotief::add_cabin(window & w, int start_x, int start_y, int size) {
	filled_rectangle wagon_item(w, start_x, start_y, start_x+size, start_y+size), link(w, start_x - size, start_y + size*.7, start_x+size, start_y + size*.8);
	circle wheel_one(w, start_x + size*0.2, start_y+size, size*.1), wheel_two(w, start_x + size*0.8, start_y+size, size*.1);
	wagon_item.print();
	link.print();
	wheel_one.print();
	wheel_two.print();
	printf ("printed");
}

void locomotief::print() {
	body.print();
	cabin.print();
	chimney.print();
	small_wheel_one.print();
	small_wheel_two.print();
	big_wheel.print();
	for (int i = 0; i < cabins; i++) {
		add_cabin(w, start_x+size+size*0.5 + size*i, start_y, size*0.7);
		printf ("wagon: %d, x: %d \n", i, start_x);
	}
}

