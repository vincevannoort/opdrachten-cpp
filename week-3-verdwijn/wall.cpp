#include "wall.hpp"

wall::wall(window & w, const vector & start, const vector & end, const int & update_interval, const vector & bounce):
rectangle(w, start, end), filled(true), update_interval(update_interval), update_count(0)
{ set_bounce(bounce); }

void wall::draw() {
	for(int i = location.x; i < end.x; i++ ) {
		for( int j = location.y; j < end.y; j++) {
			w.draw(vector(i,j), filled);
		}
	}
	rectangle::draw();
}
void wall::update() {
	update_count++;
	if (update_count % update_interval == 0) {
		filled = !filled;
	}
}

void wall::set_bounce( const vector & given_bounce ){
   bounce = given_bounce;
}

vector wall::get_bounce(){
   return bounce;
}