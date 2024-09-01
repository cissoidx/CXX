#include <iostream>

int main()
{
    int i = 1; 
    int &j = i; 
    ++i;
    ++j;

    std::cout << "i = " << i << ", j = " << j << std::endl;
    std::cout << &i << std::endl;
    std::cout << &j << std::endl;
    return 0;
}