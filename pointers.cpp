// WHAT IS A POINTER?
// A pointer is a variable that stores the memory address of another variable.

/*
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main() {
    // EXAMPLE
    int age = 20;
    int* ptr = &age;

    
      age stores the value 20
      &age means "address of age"
      ptr stores that address
    

    // return 0;
}
*/

// Pointer Declaration  
// Syntax: dataType* pointerName;

// Examples:
// int* p1;
// double* p2;
// char* p3;

// Alternative style (also valid):
// int *p1;


// Getting the Address (& operator)
// The & operator returns the memory address of a variable.
/*
#include <iostream>
using std::endl, std::cout;

int main() {
    int num = 10;

    cout << num << endl;   // prints the value of num
    cout << &num << endl;  // prints the memory address of num

    return 0;
}
*/

// Dereferencing (* Operator) = Deferencing means accessing the value stored at an adress
/*
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num;

    cout << *ptr << endl;

    return 0;
}
*/
/*
Output: 10

Explanation:
ptr contains: 0x100
*ptr means:
Go to address 0x100 and get the value,
which is: 10

*/

// Changing Values Through Pointers 
/*
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    int* ptr = &num;

    *ptr = 50;

    cout << num << endl;

    return 0;
}
*/

/*
num = 10

ptr --> num

*ptr = 50

num = 50
*/

// COMPLETE EXAMPLE 
/*
#include <iostream>
using namespace std;

int main() {
    int number = 25;

    int* ptr = &number;

    *ptr = 100;

    cout << "Value of number: " << number << endl;
    cout << "Address of number: " << &number << endl;

    cout << "Pointer stores: " << ptr << endl;
    cout << "Value through pointer: " << *ptr << endl;

    return 0;
}
*/
/*
// NULL POINTER = A null pointer points to nothing 

#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr;

    if (ptr == nullptr) {
        cout << "Pointer is null" << endl;
    }

    return 0;
}
*/

// Pointer Arithmetic = Pointer can move through memory
/*
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30};

    int* ptr = arr;

    cout << *ptr << endl;

    ptr++;
    cout << *ptr << endl;

    ptr++;
    cout << *ptr << endl;

    return 0;
}
*/

// Void Pointer = A void pointer can store the adress of any type.
/*
#include <iostream>
using namespace std;

int main() {
    int a = 50;

    void* ptr = &a;

    cout << *(int*)ptr << endl;

    return 0;
}
*/
/*
Problem:

cout << *ptr;

=== Not allowed.

The compiler doesn't know the type.

You must cast it:

cout << *(int*)ptr;

Output:

100

Modern style:

cout << *(static_cast<int*>(ptr));
*/

// Double Pointers = A double pointer stores the adress of another pointer
/*
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    int* ptr = &a;
    int** dptr = &ptr;

    cout << a << endl;
    cout << *ptr << endl;
    cout << **dptr << endl;

    return 0;
}
*/

// Function Pointer = Pointers can store function adresses.
/*
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello!" << endl;
}

int main() {

    void (*funcPtr)() = greet;

    funcPtr();

    return 0;
}
*/
/*
Useful for:

Callbacks
Event systems
Game programming
Embedded systems
*/
// Swap Using Pointers 

#include <iostream>
using namespace std;

void swapValues(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;

    cout << "Before: " << x << " " << y << endl;

    swapValues(&x, &y);

    cout << "After: " << x << " " << y << endl;

    return 0;
}