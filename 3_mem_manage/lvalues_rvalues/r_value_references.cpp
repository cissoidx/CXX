#include <iostream>

void myFunction(int &val)
{
    std::cout << "val = " << val << std::endl;
}

int main()
{
    int j = 42;
    myFunction(j);

    //candidate function not viable: expects an l-value for 1st argument
    myFunction(42);

    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    int k = 23; 
    myFunction(j+k);

    return 0; 
}