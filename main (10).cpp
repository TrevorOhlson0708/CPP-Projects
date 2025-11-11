#include <iostream>
#include <string>

int* make_int(int value) {
    int* p = new int(value);
    return p;
}

void swap_values(int* a, int* b) {   
    if (!a || !b) return;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

class Rectangle {
    int width;
    int height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    int area() const { return width * height; }
};

struct Student {
    std::string name;
    int age;
};

int main() {
    // Task #1 Declare an integer variable and assign it a value.
    // Declare a pointer to an integer and initialize it to the variable's address.
    // Display the variable’s value using both direct access and pointer dereferencing
    int number = 42;
    int* pNumber = &number;
    std::cout << "[Task 1]\n";
    std::cout << "Direct value: " << number << "\n";
    std::cout << "Via pointer dereference: " << *pNumber << "\n\n";
    
    // Create an array of five integers.
    // Use a pointer to traverse and display the array values using pointer arithmetic.
    std::cout << "[Task 2]\n";
    int arr[5] = {10, 20, 30, 40, 50};
    int* p = arr;
    std::cout << "Array via pointer arithmetic: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << *(p + i) << (i < 4 ? " " : "\n\n");
    }

    // Write a function that dynamically allocates memory for an integer.
    //Assign it a value and return the pointer.
    // Call this function in main() and display the allocated value.
    // Deallocate the memory after use.
    std::cout << "[Task 3]\n";
    int* heapInt = make_int(777);
    std::cout << "Dynamically allocated int value: " << *heapInt << "\n";
    delete heapInt;
    heapInt = nullptr;
    std::cout << "(deallocated)\n\n";

    // Write a function that takes two integer pointers as arguments and swaps their values.
    // Call this function from main() and display the swapped values.
    std::cout << "[Task 4]\n";
    int a = 5, b = 9;
    std::cout << "Before swap: a=" << a << " b=" << b << "\n";
    swap_values(&a, &b);
    std::cout << "After  swap: a=" << a << " b=" << b << "\n\n";

    // Define a structure called Student with:
    // A string for name.
    // An int for age.
    // Dynamically allocate memory for a Student object.
    // Assign values and display them.
    // Deallocate the memory
    std::cout << "[Task 5]\n";
    Student* s = new Student{"Ada Lovelace", 36};
    std::cout << "Student -> name: " << s->name << ", age: " << s->age << "\n";
    delete s;
    s = nullptr;
    std::cout << "(deallocated)\n\n";

    // Define a class called Rectangle with:
    // Private width and height members.
    // A constructor that initializes both values.
    // A member function that calculates and returns the area.
    // Create a pointer to a Rectangle object and allocate memory dynamically.
    // Call the member function to display the area.
    // Deallocate the memory.
    std::cout << "[Task 6]\n";
    Rectangle* r = new Rectangle(3, 4);
    std::cout << "Rectangle area: " << r->area() << "\n";
    delete r;
    r = nullptr;
    std::cout << "(deallocated)\n\n";

    return 0;
}