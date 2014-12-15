#pragma once
#include <vector>

typedef unsigned char u8;

/**
 * @brief Struct to store the RGB values of a pixel.
 */
struct pixel{
public:
  u8 m_red;	///< R value
  u8 m_green;	///< G value
  u8 m_blue;	///< B value
  pixel( u8 p_red, u8 p_green, u8 p_blue )
    : m_red( p_red ), m_green( p_green ), m_blue( p_blue ) { }
};

#define SCALE( x, mx ) ( ( ( x ) < 0 ) ? 0 : ( ( int )( 256.0*( ( double )( x )/( double )( mx ) ) ) ) )

/**
 * @brief Struct to hold a bitmap.
 */
struct bitmap{
private:
  std::vector<std::vector<pixel>> m_pixels;	///< The raw data
public:
  size_t m_width;				///< The image width
  size_t m_height;				///< The image height
  bitmap( size_t p_width, size_t p_height );
  
  pixel& operator(  )( size_t p_x, size_t p_y );
  pixel operator(  )( size_t p_x, size_t p_y ) const;
  
  /**
   * @param p_path String containing the path to the file to write the file to
   * @return Non-zero if an error occured.
   */
  int writeToFile( const char* p_path ) const;
};

