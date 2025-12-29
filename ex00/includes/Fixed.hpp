#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        Fixed( void );
        Fixed(Fixed const & src);
        Fixed &operator=(const Fixed &other);
        ~Fixed( void );
        int getRawBits( void ) const{
            std::cout<<"getRawBits member functon called"<<std::endl;
            return(fixed_point_number);
        }
        void setRawBits( int const raw ){
            std::cout<<"setRawBits member functon called"<<std::endl;
            fixed_point_number = raw;
        }
    private:
        int fixed_point_number;
        static const int nbr_fractional_bits =  8;

};

#endif