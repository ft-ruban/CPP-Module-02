#include "../includes/Fixed.hpp"
#include <iostream>

Fixed::Fixed(){
    std::cout<<"Default constructor called"<<std::endl;
    Fixed::fixed_point_number = 0;
    return;
}

Fixed::~Fixed(){
    std::cout<<"Destructor called"<<std::endl;
    return;
}

Fixed::Fixed(Fixed const & src){
    std::cout<<"Copy constructor called"<<std::endl;
    this->fixed_point_number = src.fixed_point_number;
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->fixed_point_number = other.fixed_point_number;
    return *this;
}
