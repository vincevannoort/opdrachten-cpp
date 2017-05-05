#include "drawable.hpp"

drawable::drawable( window & w, const vector & location, const vector & size ):
   w( w ),
   location( location ),
   size( size )
{}   

bool within( int x, int a, int b ){
   return ( x >= a ) && ( x <= b );
}

bool drawable::overlaps( const drawable & other ){
   
   bool x_overlap = within( 
      location.x, 
      other.location.x, 
      other.location.x + other.size.x
   ) || within( 
      other.location.x, 
      location.x, 
      location.x + size.x
   );
     
   bool y_overlap = within( 
      location.y, 
      other.location.y, 
      other.location.y + other.size.y
   ) || within( 
      other.location.y, 
      location.y, 
      location.y + size.y
   );
   
   return x_overlap && y_overlap;
}

std::ostream & drawable::print( std::ostream & out ) const {
   return out << location << location + size;
}

std::ostream & operator<<( std::ostream & lhs, const drawable & rhs ){
   return rhs.print( lhs );
}

