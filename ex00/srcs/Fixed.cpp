/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:53:15 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/15 10:51:51 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"
#include <iostream>

// Constructor

Fixed::Fixed()
: _fixed_point_number (0)
{
    std::cout<<"Default constructor called"<<std::endl;
    return;
}

// cpy constructor

Fixed::Fixed(Fixed const & src){
    std::cout<<"Copy constructor called"<<std::endl;
    *this = src;
}

// cpy assignement operator overload

Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixed_point_number = other.getRawBits();
    return *this;
}

// destructor

Fixed::~Fixed(){
    std::cout<<"Destructor called"<<std::endl;
    return;
}

int Fixed::getRawBits( void ) const{
    std::cout<<"getRawBits member functon called"<<std::endl;
    return(_fixed_point_number);
}

void Fixed::setRawBits( int const raw ){
    std::cout<<"setRawBits member functon called"<<std::endl;
    _fixed_point_number = raw;
}

