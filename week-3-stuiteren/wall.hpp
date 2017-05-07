#ifndef WALL_HPP
#define WALL_HPP

#include "rectangle.hpp"

class wall: public rectangle {
private:
	bool filled;
	int update_interval, update_count;
public:
	wall(window & w, const vector & start, const vector & end, const int & update_interval, const vector & bounce);
	void draw();
	void update();
	void set_bounce( const vector & given_bounce ) override;
	vector get_bounce() override;
};

#endif // WALL_HPP
