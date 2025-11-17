// Trevor Ohlson
// Professor Fowler
// 11 / 16 / 2025
// EoM #4 

#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Task 1: Const Pointers done :)
void task1() {
	int a = 10;
	int b = 20;
	int* const constPtr = &a;
	const int* ptrToConst = &a;

	cout << "Task 1:\n";

	*constPtr = 15;
	cout << "constPtr points to a = " << *constPtr << endl;

	ptrToConst = &b;
	cout << "ptrToConst now points to b = " << *ptrToConst << endl;

	cout << endl;
}

// Task 2: Struct Pointer with Member Access done :)
struct Book {
	string title;
	int year;
};

void task2() {
	cout << "Task 2:\n";

	Book* b = new Book;
	b->title = "C++ Basics";
	b->year = 2025;

	cout << b->title << " (" << b->year << ")\n";

	delete b;
	cout << endl;
}

// Task 3: I couldn't get this one to work I dont know it. Not Done :(

// Task 4: Array of Objects Done :)
class Circle {
private:
	double radius;
public:
	Circle() : radius(0) {}
	Circle(double r) : radius(r) {}

	void setRadius(double r) {
		radius = r;
	}

	double area() const {
		return 3.14159 * radius * radius;
	}
};

void task4() {
	cout << "Task 4:\n";

	Circle arr[3];
	arr[0].setRadius(1.0);
	arr[1].setRadius(2.0);
	arr[2].setRadius(3.0);

	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << " area = " << arr[i].area() << endl;
	}

	cout << endl;
}

// Task 5 & 6: Operator + and Friend Function Done :)
class Point2D {
private:
	double x, y;

public:
	Point2D() : x(0), y(0) {}
	Point2D(double X, double Y) : x(X), y(Y) {}

	Point2D operator+(const Point2D& rhs) const {
		return Point2D(x + rhs.x, y + rhs.y);
	}

// Task 6: Friend print function
	friend void printPoint(const Point2D& p);
};

void printPoint(const Point2D& p) {
	cout << "(" << p.x << ", " << p.y << ")";
}

void task5_6() {
	cout << "Task 5 & 6:\n";

	Point2D a(1, 2);
	Point2D b(3, 5);

	Point2D c = a + b;

	cout << "a + b = ";
	printPoint(c);
	cout << endl << endl;
}

// The one and only main :)
int main() {
	task1();
	task2();
	task4();
	task5_6();

	return 0;
}