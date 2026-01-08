#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        Fixed();                                //Default Constructor
        Fixed(const int value);                 //Constructor from int
        Fixed( const float float_value);        //Constructor from float
        Fixed(Fixed const & src);               //copy constructor
        Fixed &operator=(const Fixed &other);   //copy assignement operator
        ~Fixed( void );                         //Destructor

        int getRawBits( void ) const;           //getter for _fixed_point_number
        void setRawBits( int const raw );       //setter for _fixed_point_number
        float toFloat ( void ) const;           //convert into a float
        int toInt ( void ) const;               //convert into integer

    private:
        int _fixed_point_number;
        static const int nbr_fractional_bits =  8; //8 bits = 256 decimal it is usefull for conversions between float and integers

};
std::ostream &operator<<(std::ostream &out, const Fixed &value); //overload of <<

#endif