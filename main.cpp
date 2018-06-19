#include <iostream>


int square(int);
void check(int &value);
void check(int &&value);
template <typename T>
void callCheck(T &&value);

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
    std::cout << "===========REFERENCES======================"<<std::endl;

    // lvalue references
    int &value4 = value1;
    //int &value5 = square(5);       error, cannot bind lvalue reference with rvalues
    const int &value5 = square(5);   //OK
    check(value4);
    check(++value4);

    // rvalue references
   // int &&value6 = value1;          error, cannot bind rvalue reference with lvalues
    int &&value6 = square(5);         //OK
    const int &&value7 = square(5);   //OK
    check(square(5));
    check(value6++);
    std::cout << "===========PERFECT FORWARDING======================"<<std::endl;
    auto &&value8 = square(5);          //OK
    auto &&value9 = value1;             //OK, rvalue ref will collapse since the auto resolved to an lvalue
    callCheck(value9);
    callCheck(square(5));

    return 0;
}

int square(int n)
{
    return n * n;
}
void check(int &value)
{
    std::cout<<" lvalue function called with: "<<value <<std::endl;
}
void check(int &&value)
{
    std::cout<<" rvalue function called with: "<<value <<std::endl;
}
template <typename T>
void callCheck(T &&value)
{
  //  check(value); This always calls lvalue due to reference collapsing
    check(std::forward<T>(value)); //calls the right version
}