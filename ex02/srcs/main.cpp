/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:38:11 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/23 10:00:58 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout<<"TEST 42"<<std::endl;

std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

std::cout<<" END TEST 42"<<std::endl;

a = 10;
Fixed c(20);
Fixed d(10);
std::cout<<"TEST COMPARISONS"<<std::endl;

std::cout<<(a < c)<<std::endl;
std::cout<<(a > c)<<std::endl;
std::cout<<(a == d)<<std::endl;
std::cout<<(a != d)<<std::endl;
std::cout<<(a <= c)<<std::endl;
std::cout<<(c >= a)<<std::endl;

std::cout<<"END TEST COMPARISONS"<<std::endl;

c = 2;

std::cout<<"TEST ARITHMETIC"<<std::endl;

std::cout<<a + c<<std::endl;
std::cout<<a - c<<std::endl;
std::cout<<a * c<<std::endl;
std::cout<<a / c<<std::endl;

std::cout<<"END TEST ARITHMETIC"<<std::endl;

std::cout<<"TEST INCREMENT/DECREMENT"<<std::endl;

std::cout<<a<<std::endl;
a++;
std::cout<<a<<std::endl;
std::cout<<a++<<std::endl;
std::cout<<a<<std::endl;
std::cout<<++a<<std::endl;
std::cout<<a<<std::endl;
std::cout<<a--<<std::endl;
std::cout<<a<<std::endl;
std::cout<<--a<<std::endl;
std::cout<<a<<std::endl;
std::cout<<--a<<std::endl;

std::cout<<"ENDTEST INCREMENT/DECREMENT"<<std::endl;


std::cout<<"TEST MIN/MAX"<<std::endl;

a = 10;
c = 20;

Fixed &e = Fixed::min(a, c);
std::cout<<e<<std::endl;
const Fixed &f = Fixed::min(a, c);
std::cout<<f<<std::endl;
const Fixed &g = Fixed::max(a, c);
std::cout<<g<<std::endl;
Fixed &h = Fixed::max(a, c);
std::cout<<h<<std::endl;

std::cout<<"ENDTEST MIN/MAX"<<std::endl;


Fixed x(5.05f);
Fixed y(2);
std::cout<<x*y<<std::endl;

return 0;
}
