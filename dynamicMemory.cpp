// Dynamic Memory = Dynamic memory is memory that is allocated while the program is running (runtime), 
// instead of being allocated automatically when variables are declared.


/*
    Dynamic memory is stored in the Heap Memory and is managed manually using:

    new → allocate memory
    delete → free memory
    new[] → allocate an array
    delete[] → free an array

*/
// Stack Memory 
/*
Stack memory stores:

Local variables
Function parameters
Return addresses

Memory is automatically created and destroyed when functions start and end.
*/
/*
#include <iostream>
using std::cout, std::endl;

int main()
{
    int age = 20; // Stored in stack memory

    cout << "Age: " << age << endl;

    return 0;
}
*/

// Heap Memory 

// Heap memory is used when memory size is not known until runtime.

// The programmer manually controls it using new and delete.
/*
#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int; // Allocate memory in heap

    *ptr = 100;

    cout << "Value: " << *ptr << endl;

    delete ptr; // Free memory

    return 0;
}
*/
/*
    Memory Layout
    Stack              Heap
    -----              -----
    ptr ----------->   100

    ptr is on the stack.

    The actual integer (100) is stored on the heap.

*/
// ===================================== new ====================================
/*
    What is it?

    new allocates memory dynamically and returns its address.

    Syntax:

    dataType* pointer = new dataType;

*/
/*
#include <iostream>
using namespace std;

int main()
{
    int* number = new int;

    *number = 50;

    cout << *number << endl;

    delete number;

    return 0;
}
*/

// ================================== delete =====================================

// delete = delete releases memory allocated by new.
/*
#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int(25);

    cout << *ptr << endl;

    delete ptr;

    return 0;
}
*/
/*
    the memory remains allocated even after it is no longer needed.

    This causes a memory leak.
*/


//=============================== new[] ========================================

// new = Used to allocate an array dynamically.

/*
Syntax
dataType* pointer = new dataType[size];
*/
/*
#include <iostream>
using namespace std;

int main()
{
    int size = 5;

    int* numbers = new int[size];

    for(int i = 0; i < size; i++)
    {
        numbers[i] = (i + 1) * 10;
    }

    for(int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }

    delete[] numbers;

    return 0;
}
*/

// ============================== delete[] ======================================

// delete[] = Used to free memory allocated with new[].

#include <iostream>
using namespace std;

int main()
{
    int* arr = new int[3];

    arr[0] = 5;
    arr[1] = 10;
    arr[2] = 15;

    delete[] arr;

    return 0;
}