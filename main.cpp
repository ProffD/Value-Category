#include <iostream>


int square(int);


int main() {

    int value1 = 11;          // OK, value1 is lvalue,15 is rvalue
    int value2 = square(4);   // OK,  value2 is lvalue,square(4) is rvalue
    int *lptr1 = &value1;      //OK, lvalues are addressable
    int *lptr3 = &value2;      //OK
    int *lptr2 = &++value2;    //OK, ++value2 is lvalue
    // rvalues are not addressable i.e
    // int *lptr3 = &value1++;    error
    //int *rptr = &10;            error
    //int *rptr = &squre(5);      error

    std::cout << "value1: "<< value1 << std::endl;
    std::cout << "value2: "<< value2 << std::endl;
    std::cout << "&value1: "<< lptr1 <<", its value is: "<< *lptr1<< std::endl;
    std::cout << "&value2: "<< lptr3 <<", its value is: "<< *lptr3<< std::endl;
    std::cout << "&++value2: "<< lptr2 << ", its value is: "<< *lptr2<<std::endl;
    return 0;
}

int square(int n)
{
    return n * n;
}
