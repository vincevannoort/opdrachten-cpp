#ifndef VICTIM_HPP
#define VICTIM_HPP

#include "window.hpp"
#include "rectangle.hpp"
#include "vector.hpp"

class victim : public rectangle {
public:
	victim( window & w, const vector & start, const vector & end );
	void interact( drawable & other ) override;
	void adjust_based_on_touch();
};

#endif // VICTIM_HPP
