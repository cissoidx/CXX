#include <iostream>

int main()
{
    // create lambdas
    int id = 0; // Define an integer variable

    //auto f0 = []() { std::cout << "ID = " << id << std::endl; }; // Error: 'id' cannot be accessed

    id++;
    auto f1 = [id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by value

    id++;
    auto f2 = [&id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by reference

    //auto f3 = [id]() { std::cout << "ID = " << ++id << std::endl; }; // Error, 'id' may not be modified

    auto f4 = [id]() mutable { std::cout << "ID = " << ++id << std::endl; }; // OK, 'id' may be modified

    auto f5 = [&id]() mutable { std::cout << "ID = " << ++id << std::endl; };
    // execute lambdas
    f1();
    f2();
    f4();
    std::cout << "ID in main after incremented in mutable lambda(captured by value): " << id << std::endl;
    f5();
    std::cout << "ID in main after incremented in mutable lambda(captured by reference): " << id << std::endl;
    return 0;
}