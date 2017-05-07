#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <ostream>

class vector {
public:
   int x;
   int y; 
   
   vector( int x, int y ): 
      x( x ), y( y )
   {}
   
   vector( const vector & rhs ):
      x( rhs.x ),
      y( rhs.y )
   {}
   
   vector & operator+=( const vector & rhs ){
      x += rhs.x;
      y += rhs.y;
      return *this;
   }
   
   vector operator+( const vector & rhs ) const {
      vector temp = *this;
      temp += rhs;
      return temp;
   }
   
   vector & operator-=( const vector & rhs ){
      x -= rhs.x;
      y -= rhs.y;
      return *this;
   }
   
   vector operator-( const vector & rhs ) const {
      vector temp = *this;
      temp -= rhs;
      return temp;
   }
   
   vector & operator*=( int n ){
      x *= n;
      y *= n;
      return *this;
   }
   
   vector operator*( int n ) const {
      vector temp = *this;
      temp *= n;
      return temp;
   }
};

std::ostream & operator<<( std::ostream & lhs, const vector & pos );

#endif // VECTOR_HPP
