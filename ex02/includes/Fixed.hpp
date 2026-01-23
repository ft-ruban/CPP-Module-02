/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:50:56 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/23 07:43:43 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

        //overload for comparison operators
        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;
        //overload for arithmetic operators
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;
        //overload for increment/decrement operators
        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);
    

        static Fixed& min(Fixed &one, Fixed &two);
        static const Fixed& min(const Fixed &one, const Fixed &two);
        static Fixed& max(Fixed &one, Fixed &two);
        static const Fixed& max(const Fixed &one, const Fixed &two);
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