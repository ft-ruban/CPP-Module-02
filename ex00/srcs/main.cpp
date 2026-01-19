/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:53:12 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/15 10:49:21 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1) create an instance of Fixed called a with constructor
// 2) use the cpy constructor to create b by copying a
// 3) create a new instance called c and use cpy assignement operator overload 
//      by using b
// 4) print content of a b and c in standard output.
// 5) end of program

#include <iostream>
#include "../includes/Fixed.hpp"

int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}
