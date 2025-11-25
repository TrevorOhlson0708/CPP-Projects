// polymorphism demo

#include <iostream>
using namespace std;

class Base {
public:
    virtual void identify() {
        cout << "I am the Base class" << endl;
    }
    virtual ~Base() {}
};

class Child1 : public Base {
public:
    void identify() override {
        cout << "I am the Base class" << endl;
    }
};

class Child2 : public Base {
public:
    void identify() override {
        cout << "I am the Child2 class" << endl;
    }
};

int main() {
    Base* arr[3];
    arr[0] = new Base();
    arr[1] = new Child1();
    arr[2] = new Child2();

    cout << "Testing identify() on each object:\n\n";

    for (int i = 0; i < 3; i++) {
        arr[i]->identify();
    }

    for (int i = 0; i < 3; i++) {
        delete arr[i];
    }

    return 0;
}
