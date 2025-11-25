// Pointers Practice
// Output: 4 6 10
#include <iostream>
using namespace std;

int main() {
    int* intArrayPtr;
    int* temp;
    intArrayPtr = new int[3];
    *intArrayPtr = 4;
    temp = intArrayPtr;
    
    for (int i = 1; i < 3; i++) {
        intArrayPtr++;
        *intArrayPtr = *(intArrayPtr - 1) + 2 * i;
    }
    intArrayPtr = temp;
    
    for (int i = 0; i < 3; i++) {
        cout << *intArrayPtr << " ";
        intArrayPtr++;
    }
    cout << endl;
    return 0;
}