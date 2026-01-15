/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevoude <ldevoude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 09:49:15 by ldevoude          #+#    #+#             */
/*   Updated: 2026/01/15 10:51:31 by ldevoude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        Fixed( void );                        // constructor
        Fixed(Fixed const & src);             // cpy constructor
        Fixed &operator=(const Fixed &other); // cpy assignement operator overload
        ~Fixed( void );                       // destructor
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int _fixed_point_number;
        static const int _nbr_fractional_bits =  8;

};

#endif