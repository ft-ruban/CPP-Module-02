#include <iostream>
#include "../includes/Fixed.hpp"

// int main(void){
//     std::cout<<"test"<<std::endl;
//     return(0);
// }

// #include <iostream>

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