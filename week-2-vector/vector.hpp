#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>

/// @brief
/// Vector class
/// @details
/// This is an class that implements vector values and their mathematical operators.
/// The x and y values are stored as (signed) integers.
class vector {
private:
   int x, y;
public:
   /// @brief
   /// Constructor for the vector class
   /// @details
   /// Constructor that initializes the x and y value of the vector created.
   /// If no paramaters are provided, the empty values are set to 0.
   /// @param int x, x value for vector, defaults to 0
   /// @param int y, y value for vector, defaults to 0
   /// @return vector
   vector(int x = 0, int y = 0): x(x), y(y) {}

   /// @brief
   /// Compare operator for two vectors
   /// @details
   /// Compares the given vectors for their x and y values.
   /// @param const vector &, automatically provided when writing "vector(3,2) == vector(3,2)"
   /// @return bool
   bool operator==( const vector & ) const;

   /// @brief
   /// Addition of two vectors
   /// @details
   /// Addition of the given vectors with their x and y values.
   /// @param const vector &, automatically provided when writing "vector(3,2) + vector(3,2)"
   /// @return vector
   vector operator+( const vector & ) const;

   /// @brief
   /// One side addition of two vectors
   /// @details
   /// Addition of the given vectors with their x and y values.
   /// @param const vector &, automatically provided when writing "variable(type vector) += vector(3,2)"
   /// @return vector
   vector & operator+=( const vector & );

   /// @brief
   /// Multiplication of vector with integer
   /// @details
   /// Multiplication of the given vector with an integer
   /// @param const int &, automatically provided when writing "vector(3,2) * 8"
   /// @return vector
   vector operator*( const int & ) const;

   /// @brief
   /// Multiplication of integer with vector
   /// @details
   /// Multiplication of the given an integer with vector
   /// @param const int &, automatically provided when writing "8 * vector(3,2)"
   /// @param const vector &, automatically provided when writing "8 * vector(3,2)"
   /// @return vector
   friend vector operator*( const int, const vector & );

   /// @brief
   /// One side multiplication of vector with integer
   /// @details
   /// Multiplication of the given vector with an integer
   /// @param const int &, automatically provided when writing "variable(type vector) *= 8"
   /// @param const vector &, automatically provided when writing "8 * vector(3,2)"
   /// @return vector
   vector & operator*=( const int rhs );

   /// @brief
   /// Output a vector properly to the cout
   /// @details
   /// Output a vector properly to the cout
   /// @param std::ostream & lhs, automatically provided when writing "cout << vector(3,2)"
   /// @param const vector & rhs, automatically provided when writing "cout << vector(3,2)"
   /// @return ostream
   friend std::ostream & operator<<( std::ostream & lhs, const vector & rhs );
};

#endif