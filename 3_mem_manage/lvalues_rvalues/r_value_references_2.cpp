#include <iostream>

int main()
{
    int i = 1; 
    int j = 2; 
    // The sum i+j is created as an rvalue, 
    // which holds the result of the addition 
    // before being copied into the memory location of k
    int k = i + j; 
    // The expression int &&l creates an rvalue reference, 
    // to which the address of the temporary object is assigned, 
    // that holds the result of the addition
    int &&l = i + j; 

    std::cout << "k = " << k << ", l = " << l << std::endl;

    return 0; 
}