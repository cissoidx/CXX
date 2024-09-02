#include <iostream>
#include <memory>
#include <string>

class MyClass
{
private:
    std::string _text;
    int _myint;

public:
    MyClass() {}
    MyClass(std::string text) { _text = text; }
    ~MyClass() { std::cout << _text << " destroyed" << std::endl; }
    void setText(std::string text) { _text = text; }
    std::string getText(){return _text;}
    void setNum(int i){_myint = i;}
    int getNum(){return _myint;}
};

int main()
{
    // create unique pointer to proprietary class
    std::unique_ptr<MyClass> myClass1(new MyClass());
    std::unique_ptr<MyClass> myClass2(new MyClass("String_2"));

    // call member function using ->
    myClass1->setText("String_1");
    myClass2->setNum(3);

    // use the dereference operator * 
    *myClass1 = *myClass2;

    // use the .get() function to retrieve a raw pointer to the object
    std::cout << "Objects have stack addresses " << myClass1.get() << " and " << myClass2.get() << std::endl;
    std::cout << "number-of-1 " << myClass1->getNum() << " and-2 " << myClass2->getNum() << std::endl;
    std::cout << "text-of-1 " << myClass1->getText() << " and-2 " << myClass2->getText() << std::endl;

    return 0;
}