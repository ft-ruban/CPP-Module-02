/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:21:19 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/23 07:42:47 by ldevoude         ###   ########.fr       */
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