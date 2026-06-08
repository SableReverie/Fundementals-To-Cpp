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
/*
    Important Rule

    Always match:

    new      -> delete
    new[]    -> delete[]

    Correct:

    int* arr = new int[5];

    delete[] arr;

    Wrong:

    int* arr = new int[5];

    delete arr; // WRONG

    This causes undefined behavior.
*/

// =============================== Memory Leaks ===================================

// A memory leak happens when dynamically allocated memory is never released. The program loses access to the memory, but the memory remains occupied.
/*
#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int(100);

    // Forgot delete

    return 0;
}
*/
/*
    Heap
    ----
    100

    After the program loses the pointer, the memory cannot be reused.
*/

/*
    Another Memory Leak Example
    
    int* ptr = new int(10);

    ptr = new int(20);
  ====================================
    What happened?
    
    First allocated memory (10)
        ↑
    No pointer points to it anymore

    The first memory block is lost forever.
 =====================================
    Correct:

    int* ptr = new int(10);

    delete ptr;

    ptr = new int(20);

    delete ptr;
 ======================================
*/

// =========================== Dangling Pointers ==================================
// A dangling pointer points to memory that has already been freed.

/*
#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int(50);

    delete ptr;

    cout << *ptr; // Dangerous

    return 0;
}
*/

/*
    ptr ---> Memory already deleted

    Accessing it may:

    Crash the program
    Show garbage values
    Cause unpredictable behavior
*/



// SAFER 
/*
#include <iostream>
using namespace std;

int main()
{
    int* ptr = new int(50);

    delete ptr;

    ptr = nullptr;

    return 0;
}
*/
/*
    Stack = Automatic memory management

    Heap = Manual memory management
*/