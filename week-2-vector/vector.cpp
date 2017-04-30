#include <iostream>
#include "vector.hpp"

bool vector::operator==( const vector & rhs ) const {
	return (x == rhs.x) && (y == rhs.y);
}

vector vector::operator+( const vector & rhs ) const {
	 return vector(x+rhs.x, y+rhs.y);
}

vector & vector::operator+=( const vector & rhs ) {
	x = x + rhs.x;
	y = y + rhs.y;
	return *this;
}

vector vector::operator*( const int & lhs ) const {
	return vector(x*lhs, y*lhs);
}

vector operator*(const int lhs, const vector & rhs) {
    return vector(lhs*rhs.x, lhs*rhs.y);
}

vector & vector::operator*=( const int rhs ) {
	x = x * rhs;
	y = y * rhs;
	return *this;
}

std::ostream & operator<<( std::ostream & lhs, const vector & rhs ) {
	return lhs 
        << "(" 
        << rhs.x 
        << "," 
        << rhs.y
        << ")";
}