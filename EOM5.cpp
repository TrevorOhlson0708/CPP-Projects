// Trevor Ohlson
// EOM 5
// Proffesor Fowler
// 12 / 11 / 25

#include <iostream>
#include <cmath>
using namespace std;

// Task 1
class Adder {
    int value;
public:
    Adder(int v) : value(v) {}

    int operator()(int x) const {
        return value + x;
    }
};

// Task 2: Static Members
class IDGenerator {
    static int counter;
    int id;
public:
    IDGenerator() {
        id = ++counter;
    }
    int getID() const { return id; }

    static int getObjectCount() { return counter; }
};

int IDGenerator::counter = 0;


// Task 3
class Distance {
    int feet, inches;
public:
    Distance(int totalInches) {
        feet = totalInches / 12;
        inches = totalInches % 12;
    }

    Distance(int f, int i) : feet(f), inches(i) {}

    operator int() const {
        return feet * 12 + inches;
    }

    void display() const {
        cout << feet << " ft " << inches << " in\n";
    }
};

// Task 4

class Engine {
public:
    Engine()  { cout << "Engine constructed\n"; }
    ~Engine() { cout << "Engine destroyed\n"; }
};

class Driver {
    string name;
public:
    Driver(string n) : name(n) {}
    string getName() const { return name; }
};

class CarCompAgg {
    Engine engine;
    Driver* driver;
public:
    CarCompAgg(Driver* d) : driver(d) {
        cout << "Car constructed with driver: " << d->getName() << "\n";
    }
    ~CarCompAgg() {
        cout << "Car destroyed. Engine will be destroyed automatically.\n";
        cout << "(Driver not destroyed because Car does NOT own it.)\n";
    }
};

int main() {

    cout << "\n Task 1 \n";
    Adder add5(5);
    cout << "Result: " << add5(10) << "\n";

    int num = 10;
    auto lambda = [&]() { num += 5; };
    lambda();
    cout << "Modified num: " << num << "\n";

    cout << "\n Task 2 \n";
    IDGenerator a, b, c;
    cout << "DENNIS ID: " << a.getID() << "\n";
    cout << "ANKIT ID: " << b.getID() << "\n";
    cout << "FOWLER ID: " << c.getID() << "\n";
    cout << "Total objects created: " << IDGenerator::getObjectCount() << "\n";

    cout << "\n Task 3 \n";
    Distance d1(50);
    cout << "Total inches (50): ";
    d1.display();

    int totalInches = d1;
    cout << "Back 2 Inches: " << totalInches << "\n";

    cout << "\n Task 4 \n";
    Driver* john = new Driver("John Pork");
    {
        CarCompAgg myCar(john);
    } 

    return 0;
}
