/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:21:26 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/23 07:43:04 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

//constructor
Fixed::Fixed()
: _fixed_point_number (0)
{
    std::cout<<"Default constructor called"<<std::endl;
    return;
}

// constructor from int that convert an int into a fixed point value
// we move the bit 00000001 by the left so it give 2^8 (256) (1.0000.0000)
Fixed::Fixed(const int value)
{
    _fixed_point_number = value * (1 << nbr_fractional_bits);
    std::cout<<"Int constructor called"<<std::endl;
    return;
}

// constructor from float
// we round the float value then multiply it by bit 0000.0001 moved by the left (so 2^8 = 256 = 1.0000.0000)
Fixed::Fixed(const float float_value)
{
    _fixed_point_number = roundf(float_value * (1 << nbr_fractional_bits));
    std::cout<<"Float constructor called"<<std::endl;
    return;
}

//constructor from float
Fixed::Fixed(Fixed const & src){
    std::cout<<"Copy constructor called"<<std::endl;
    *this = src;
}

//copy assignement operator overload
Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixed_point_number = other.getRawBits();
    return *this;
}

//destructor
Fixed::~Fixed(){
    std::cout<<"Destructor called"<<std::endl;
    return;
}

// 1) return the private attribute _fixed_point_number
int Fixed::getRawBits( void ) const{
    return(_fixed_point_number);
}

// 1) set the private attribute with the sent parameter (raw)
void Fixed::setRawBits( int const raw ){
    _fixed_point_number = raw;
}

//convert into a float and to return the right value we just do the opposite method (divide and not multiply)
float Fixed::toFloat ( void ) const{
            float return_value = _fixed_point_number / (float) (1 << nbr_fractional_bits);
            return(return_value);
}

//convert into an integer  and to return the right value we just do the opposite method (divide and not multiply)
int Fixed::toInt ( void ) const{
            int return_value = _fixed_point_number / (1 << nbr_fractional_bits);
            return(return_value);
}

//overload of <<
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}