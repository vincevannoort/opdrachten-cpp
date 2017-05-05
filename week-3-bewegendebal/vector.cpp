#include "vector.hpp"

std::ostream & operator<<( std::ostream & lhs, const vector & pos ){
   lhs << "(" << pos.x << "," << pos.y << ")";
   return lhs;
}