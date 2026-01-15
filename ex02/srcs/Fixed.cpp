#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
: _fixed_point_number (0)
{
    //std::cout<<"Default constructor called"<<std::endl;
    return;
}

Fixed::Fixed(const int value)
{
    _fixed_point_number = value * (1 << nbr_fractional_bits);
    //std::cout<<"Int constructor called"<<std::endl;
    return;
}

Fixed::Fixed(const float float_value)
{
    _fixed_point_number = roundf(float_value * (1 << nbr_fractional_bits));
    //std::cout<<"Float constructor called"<<std::endl;
    return;
}

Fixed::Fixed(Fixed const & src){
    //std::cout<<"Copy constructor called"<<std::endl;
    *this = src;
}

Fixed &Fixed::operator=(const Fixed &other){
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixed_point_number = other.getRawBits();
    return *this;
}

bool Fixed::operator>(const Fixed &other) const{
    return this->_fixed_point_number > other._fixed_point_number;
}

bool Fixed::operator<(const Fixed &other) const{
    return this->_fixed_point_number < other._fixed_point_number;
}

bool Fixed::operator>=(const Fixed &other) const{
    return this->_fixed_point_number >= other._fixed_point_number;
}
bool Fixed::operator<=(const Fixed &other) const{
    return this->_fixed_point_number <= other._fixed_point_number;
}

bool Fixed::operator==(const Fixed &other) const{
    return this->_fixed_point_number == other._fixed_point_number;
}

bool Fixed::operator!=(const Fixed &other) const{
    return this->_fixed_point_number != other._fixed_point_number;
}

Fixed Fixed::operator+(const Fixed &other) const{
    Fixed result;
    result.setRawBits(this->_fixed_point_number + other._fixed_point_number);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const{
    Fixed result;
    result.setRawBits(this->_fixed_point_number - other._fixed_point_number);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const{
    Fixed result;
    long tmp = (long)this->_fixed_point_number * other._fixed_point_number;
    result.setRawBits(tmp >> nbr_fractional_bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const{
    Fixed result;
    long tmp = ((long)this->_fixed_point_number << nbr_fractional_bits);
    result.setRawBits(tmp / other._fixed_point_number);
    return result;
}

Fixed &Fixed::operator++(void){
    this->_fixed_point_number += 1;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed tmp(*this);
    ++this->_fixed_point_number;
    return tmp;
}

Fixed &Fixed::operator--(void){
    this->_fixed_point_number -= 1;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed tmp(*this);
    --this->_fixed_point_number;
    return tmp;
}

Fixed::~Fixed(){
    //std::cout<<"Destructor called"<<std::endl;
    return;
}

Fixed& Fixed::min(Fixed &one, Fixed &two){
    if (one < two)
        return (one);
    else
        return(two);
}

const Fixed& Fixed::min(const Fixed &one, const Fixed &two){
    if (one < two)
        return (one);
    else
        return(two);
}

Fixed& Fixed::max(Fixed &one, Fixed &two){
    if (one > two)
        return (one);
    else
        return(two);
}

const Fixed& Fixed::max(const Fixed &one, const Fixed &two){
    if (one > two)
        return (one);
    else
        return(two);
}

int Fixed::getRawBits( void ) const{
            return(_fixed_point_number);
}

void Fixed::setRawBits( int const raw ){
            _fixed_point_number = raw;
}

float Fixed::toFloat ( void ) const{
            float return_value = _fixed_point_number / (float) (1 << nbr_fractional_bits);
            return(return_value);
}

int Fixed::toInt ( void ) const{
            int return_value = _fixed_point_number / (1 << nbr_fractional_bits);
            return(return_value);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    out << value.toFloat();
    return out;
}
