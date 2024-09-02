#include <iostream>
#include <memory>

class MyClass
{
public:
    ~MyClass() { std::cout << "Destructor of MyClass called" << std::endl; }
};

int main()
{
    std::shared_ptr<MyClass> shared(new MyClass);
    std::cout << "shared pointer count = " << shared.use_count() << std::endl;
    // std::shared_ptr<MyClass> shared2 = shared;
    // std::cout << "shared pointer count = " << shared.use_count() << std::endl;
    // // if shared2 is defined, the reset will not trigger destructor
    shared.reset(new MyClass);
    std::cout << "shared pointer count = " << shared.use_count() << std::endl;

    return 0;
}