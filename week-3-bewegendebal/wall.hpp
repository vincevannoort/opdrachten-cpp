#ifndef WALL_HPP
#define WALL_HPP

#include "rectangle.hpp"

class wall: public rectangle {
private:
	bool filled;
	int update_interval, update_count;
public:
	wall(window & w, const vector & start, const vector & end, const int & update_interval);
	void draw();
	void update();
};

#endif // WALL_HPP
