#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    
    MyMovableClass(const MyMovableClass &source) // 2 : copy constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    
    MyMovableClass &operator=(const MyMovableClass &source) // 3 : copy assignment operator
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;
        delete[] _data;
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }

    MyMovableClass(MyMovableClass &&source) // 4 : move constructor
    {
        std::cout << "MOVING (c’tor) instance " << &source << " to instance " << this << std::endl;
        _data = source._data;
        _size = source._size;
        source._data = nullptr;
        source._size = 0;
    }

    MyMovableClass &operator=(MyMovableClass &&source) // 5 : move assignment operator
    {
        std::cout << "MOVING (assign) instance " << &source << " to instance " << this << std::endl;
        if (this == &source)
            return *this;

        delete[] _data;

        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }
};


void useObject(MyMovableClass obj)
{
    std::cout << "using object " << &obj << std::endl;
}


// compile using the option to simplify
// -fno-elide-constructors -std=c++11
int main()
{
    // // test 1
    // MyMovableClass obj1(100), obj2(200); // constructor
    // MyMovableClass obj3(obj1); // copy constructor
    // MyMovableClass obj4 = obj1; // copy constructor
    // obj4 = obj2; // copy assignment operator

    // // test 2
    // MyMovableClass obj1(100); // constructor
    // obj1 = MyMovableClass(200); // move assignment operator
    // MyMovableClass obj2 = MyMovableClass(300); // move constructor

    // test 3
    MyMovableClass obj1(100); // constructor
    useObject(obj1);
    MyMovableClass obj2 = MyMovableClass(200);
    // by passing an object to std::move we can force the compiler to use move semantics,
    // either in the form of move constructor or the move assignment operator
    useObject(std::move(obj2));

    return 0;
}
