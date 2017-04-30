#include "filled_rectangle.hpp"
#include "window.hpp"

filled_rectangle::filled_rectangle( window & w, int start_x, int start_y, int end_x, int end_y ):
start_x(start_x), start_y(start_y), end_x(end_x), end_y(end_y), w(w)
{}

void filled_rectangle::print() {
	for (int i = start_x; i < end_x; ++i)
	{
		for (int j = start_y; j < end_y; ++j)
		 {
		 	w.draw(i,j);
		 } 
	}
}