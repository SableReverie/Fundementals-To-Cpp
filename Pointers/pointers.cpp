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
/*
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
*/

// Reference vs Pointer Comparison 
/*
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    int* ptr = &a;
    int& ref = a;

    *ptr = 20;   // using pointer
    ref = 30;    // using reference

    cout << a << endl;

    return 0;
}
*/

// Pointer Safety Example
/*
#include <iostream>
using namespace std;

int main() {
    int* ptr = nullptr;

    if (ptr != nullptr) {
        cout << *ptr << endl;
    } else {
        cout << "Safe: pointer is null" << endl;
    }

    return 0;
}
*/

/*
=========================================================
6. REFERENCES IN C++
=========================================================

1. REFERENCE VARIABLES
---------------------------------------------------------
A reference is an alias (another name) for an existing variable.

Syntax: 
    int x = 10;
    int &ref = x;

Example:
    int x = 10;
    int &ref = x;

    ref = 20; // x also becomes 20

Notes:
- Must be initialized when declared.
- Cannot be null.
- Cannot refer to another variable later.
- Shares the same memory location as the original variable.

---------------------------------------------------------

2. PASS BY REFERENCE
---------------------------------------------------------
Allows a function to modify the original variable.

Pass by Value:
    void increment(int x) {
        x++;
    }

    int num = 5;
    increment(num);

Result:
    num is still 5 because x is a copy.

Pass by Reference:
    void increment(int &x) {
        x++;
    }

    int num = 5;
    increment(num);

Result:
    num becomes 6 because x refers to num.

Benefits:
- Can modify original data.
- Avoids unnecessary copying.
- More efficient for large objects.

Example:
    void swapNumbers(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }

---------------------------------------------------------

3. CONST REFERENCES
---------------------------------------------------------
A const reference allows access to a variable
without allowing modifications.

Syntax:
    const int &ref = x;

Example:
    int x = 100;
    const int &ref = x;

    // ref = 200; // ERROR

Why use const references?
- Prevent accidental modification.
- Avoid copying large objects.
- Improve performance.

Function Example:
    void printString(const string &str) {
        cout << str;
    }

Advantages:
- No copy is made.
- Original data is protected.

Can bind to temporary values:
    const int &ref = 50; // Valid

Normal reference:
    int &ref = 50; // ERROR

---------------------------------------------------------

4. REFERENCE VS POINTER
---------------------------------------------------------

Reference:
    int x = 10;
    int &ref = x;

Pointer:
    int x = 10;
    int *ptr = &x;

Comparison:

Reference:
✔ Must be initialized
✔ Cannot be null
✔ Cannot be reassigned
✔ No dereferencing required
✔ Safer and easier to use

Pointer:
✔ Can be null (nullptr)
✔ Can be reassigned
✔ Requires dereferencing (*ptr)
✔ Stores memory addresses
✔ More flexible

Reference Example:
    int a = 10;
    int &ref = a;

Pointer Example:
    int a = 10;
    int *ptr = &a;

---------------------------------------------------------

REFERENCE REASSIGNMENT
---------------------------------------------------------

int a = 10;
int b = 20;

int &ref = a;

ref = b;

Result:
    a becomes 20
    ref still refers to a

References cannot change what they refer to.

---------------------------------------------------------

POINTER REASSIGNMENT
---------------------------------------------------------

int a = 10;
int b = 20;

int *ptr = &a;
ptr = &b;

Result:
    ptr now points to b

Pointers can change targets.

---------------------------------------------------------

WHEN TO USE EACH
---------------------------------------------------------

Use Reference:
    void updateScore(int &score);

Use Const Reference:
    void display(const string &name);

Use Pointer:
    void printValue(int *ptr);

Choose:
- &      -> modify caller's variable
- const& -> read-only, efficient
- *      -> nullable or address manipulation

=========================================================
QUICK SUMMARY
=========================================================

Reference Variable:
    int x = 10;
    int &ref = x;

Pass By Reference:
    void change(int &x) {
        x = 100;
    }

Const Reference:
    void show(const string &s) {
        cout << s;
    }

Reference vs Pointer:
    int &ref = x;   // alias
    int *ptr = &x;  // address

References:
- Simpler
- Safer
- Cannot be null

Pointers:
- Flexible
- Can be null
- Can be reassigned

=========================================================
*/




// =================================  POINTERS  ================================== 
/*
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr = &a; // Pointer to integer

    cout << "Value of a: " << a << endl; // Output the value of a
    cout << "Address of a: " << &a << endl; // Output the address of a
    cout << "Value of ptr (address of a): " << ptr << endl; // Output the value of ptr (address of a)
    cout << "Value pointed to by ptr: " << *ptr << endl; // Output the value pointed to by ptr

    *ptr = 20; // Change the value of a using the pointer
    cout << "New value of a after changing through pointer: " << a << endl; // Output the new value of a

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main(){

    int x = 10; // Creating a variable x and assigning it a value of 10
    cout << "Value of x: " << x << endl; // Output the value of x
    int *ptr = &x; // Creating a pointer ptr and assigning it the address of x
    cout << "Address of x: " << &x << endl; // Output the address
    // print the size of the pointer
    cout << "Size of pointer: " << sizeof(ptr) << " bytes" << endl; // Output the size of the pointer
    cout << "Value of ptr (address of x): " << ptr << endl; // Output the value of ptr (address of x)

    return 0;
}
*/

// Create a pointer that stores the address of x
/*
#include <iostream>
using namespace std;
int main(){

    int x = 10; // Creating a variable x and assigning it a value of 10
    int *ptr = &x; // Creating a pointer ptr and assigning it the address of x
    // Print value, address, value inside pointer, and address of pointer
    cout << "Value of x: " << x << endl; // Output the value of x
    cout << "Address of x: " << &x << endl; // Output the address
    cout << "Value of ptr (address of x): " << ptr << endl; // Output the value of ptr (address of x)
    cout << "Value pointed to by ptr: " << *ptr << endl; // Output the value pointed to by ptr

    return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main(){

    int x = 10; // Creating a variable x and assigning it a value of 10
    int *ptr = &x; // Creating a pointer ptr and assigning it the address of x
   
    *ptr = 20;
    cout << "New value of x after changing through pointer: " << x << endl; // Output the new value of x
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main(){

    int x = 10;
    int *ptr = &x; // Creating a pointer ptr and assigning it the address of x

    cout << "Value of x: " << x << endl; // Output the value of x
    cout << "Address of x: " << &x << endl; // Output the address
    cout << "Value inside pointer (address of x): " << ptr << endl; // Output the value of ptr (address of x)
    cout << "Value pointed to by pointer: " << *ptr << endl; // Output the value pointed to by ptr
// Questions:

//  Why is ptr different from &ptr?
//  What does ptr actually contain?

    return 0;
}
*/
/*
#include <iostream>
using namespace std;
// That doubles the number using a pointer
    void doubleValue(int *ptr) {
        *ptr *= 2; // Dereference the pointer and double the value
    }

int main(){

    int num = 10; // Create an integer variable num and assign it a value of 10
    cout << "Original value of num: " << num << endl; // Output the original
    doubleValue(&num); // Call the function and pass the address of num
    cout << "Value of num after doubling: " << num << endl; // Output the

    return 0;
}
*/


/*
#include <iostream>
using namespace std;
// Swaps the two number using pointers
/*
Example

Before:
5 8

After:
8 5

void swapNumbers(int *a, int *b) {
    int temp = *a; // Store the value pointed to by a in temp
    *a = *b; // Assign the value pointed to by b to the location pointed to by a
    *b = temp; // Assign the value stored in temp to the location pointed to by b
    }

int main(){

    int x = 5, y = 8; // Create two integer variables x and y
    cout << "Before swapping: " << x << " " << y << endl; //
    swapNumbers(&x, &y); // Call the function and pass the addresses of x and y
    cout << "After swapping: " << x << " " << y << endl; // Output the values after swapping

    return 0;
}

*/

/*
#include <iostream>
using namespace std;
// Make a function that any integer returns to 0
void reset(int *ptr) {
    *ptr = 0; // Dereference the pointer and set the value to 0
}
int main(){

    int x = 10;
    cout << "Original value of x: " << x << endl; // Output the original value of x
    reset(&x); // Call the function and pass the address of x
    cout << "Value of x after reset: " << x << endl; // Output the value of x after reset

    return 0;
}
*/
/*
// =================== Pointer Arithmetic ==========================

#include <iostream>
using namespace std;

int main(){

    int numbers[5] = {10, 20, 30, 40, 50}; // Create an array of integers

    // print without using numbers[i]

    cout << "Array elements using pointer arithmetic: " << endl;
    for(int i = 0; i < 5; i++) {
        cout << *(numbers + i) << " "; // Access the elements using pointer arithmetic
    }

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main(){
    
    int numbers[5] = {10, 20, 30, 40, 50}; // Create an array of integers
    int *p = numbers; // Pointer to the first element of the array
    // move through the array using pointer arithmetic "p++"

    cout << "Array elements using pointer arithmetic: " << endl;
    for(int i = 0; i < 5; i++) {
        cout << *p << " "; // Output the value pointed to by p
        p++; // Move the pointer to the next element
    }  

    return 0;
}
*/



// =================== Dynamic Memory Allocation ==========================

// Allocate one integer dynamically.
/*

#include <iostream>

int main() {
    // Allocate one integer dynamically on the heap
    int* ptr = new int;

    // Store the value 50 in the allocated memory
    *ptr = 50;

    // Print the value
    std::cout << "Dynamically allocated value: " << *ptr << std::endl;

    // Delete the dynamically allocated memory to prevent leaks
    delete ptr;

    return 0;
}
*/

/*
#include <iostream>

int main() {
    int count;
    
    // Ask the user how many numbers
    std::cout << "How many numbers? ";
    std::cin >> count;

    // Allocate memory dynamically
    int* numbers = new int[count];

    // Read all numbers
    for (int i = 0; i < count; ++i) {
        std::cout << "Enter number " << (i + 1) << ": ";
        std::cin >> *(numbers + i); // Using pointer notation
    }

    // Print them
    std::cout << "You entered: ";
    for (int i = 0; i < count; ++i) {
        std::cout << *(numbers + i) << " "; // Using pointer notation
    }
    std::cout << std::endl;

    // Free the memory
    delete[] numbers;

    return 0;
} 
*/

/*
#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "How many numbers? ";
    cin >> size;

    // 1. Allocate memory dynamically
    int* arr = new int[size];

    // 2. Read all numbers
    for (int i = 0; i < size; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> arr[i];
    }

    // 3. Modify every number by multiplying by 2 using pointer arithmetic
    // Start pointer at the base of the array
    int* ptr = arr;
    for (int i = 0; i < size; i++) {
        // Dereference the current pointer, multiply by 2, and store back
        *ptr = *ptr * 2;
        // Move pointer to the next integer in memory
        ptr++; 
    }

    // 4. Print them
    cout << "Modified array: ";
    ptr = arr; // Reset pointer to start for printing
    for (int i = 0; i < size; i++) {
        cout << *ptr << " ";
        ptr++;
    }
    cout << endl;

    // 5. Free the memory
    delete[] arr;

    return 0;
}   
*/
/*
// ======================== Double Pointers =================================

// A double pointer is simply a pointer that points to another pointer.
#include <iostream>
using namespace std;

int main(){
    int x = 10;
    int *ptr = &x;
    int **ptr = &ptr;
    return 0;

    Variable      Address      Value
----------------------------------------
x             1000         10
ptr           2000         1000
dptr          3000         2000

}
*/
/*
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* ptr = &x;
    int** dptr = &ptr;

    cout << "x = " << x << endl;
    cout << "ptr = " << ptr << endl;
    cout << "dptr = " << dptr << endl;

    cout << "*ptr = " << *ptr << endl;
    cout << "*dptr = " << *dptr << endl;
    cout << "**dptr = " << **dptr << endl;

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;
    int** pp = &p;

    cout << "x    = " << x << endl;
    cout << "*p   = " << *p << endl;
    cout << "**pp = " << **pp << endl;

    return 0;
}
*/

// Find the largest Number (Pointers Only)
/*
#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 45, 7, 89, 34};
    int size = sizeof(arr) / sizeof(arr[0]);

    int* p = arr;
    int largest = *p;

    while (p < arr + size) {
        if (*p > largest)
            largest = *p;
        p++;
    }

    cout << "Largest = " << largest << endl;

    return 0;
}
*/

// ============= Reverse an Array Using Two Pointers ==================
/*
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int* left = arr;
    int* right = arr + size - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }

    cout << "Reversed array: ";

    int* p = arr;
    while (p < arr + size) {
        cout << *p << " ";
        p++;
    }

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int myStrlen(const char* str) {
    const char* p = str;

    while (*p != '\0')
        p++;

    return p - str;
}

int main() {
    char str[] = "Hello";

    cout << myStrlen(str);

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

void myStrcpy(char* dest, const char* src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0';
}

int main() {
    char source[] = "Hello";
    char destination[100];

    myStrcpy(destination, source);

    cout << destination;

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int myStrcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int main() {
    char str1[] = "Apple";
    char str2[] = "Apple";
    char str3[] = "Banana";

    cout << myStrcmp(str1, str2) << endl;
    cout << myStrcmp(str1, str3) << endl;

    return 0;
}
*/


#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void inputGrades(double* grades, int size);
void displayGrades(double* grades, int size);
double calculateAverage(double* grades, int size);
double findHighest(double* grades, int size);
double findLowest(double* grades, int size);
void updateGrade(double* grades, int size);

int main()
{
    int numStudents;

    cout << "=====================================\n";
    cout << "      STUDENT RECORD MANAGER\n";
    cout << "=====================================\n";

    cout << "Enter number of students: ";
    cin >> numStudents;

    while (numStudents <= 0)
    {
        cout << "Invalid input. Enter a positive number: ";
        cin >> numStudents;
    }

    // Dynamically allocate memory
    double* grades = new double[numStudents];

    // Input grades
    inputGrades(grades, numStudents);

    // Display grades
    cout << "\nCurrent Student Grades\n";
    displayGrades(grades, numStudents);

    // Statistics
    cout << fixed << setprecision(2);
    cout << "\nAverage Grade : " << calculateAverage(grades, numStudents);
    cout << "\nHighest Grade : " << findHighest(grades, numStudents);
    cout << "\nLowest Grade  : " << findLowest(grades, numStudents);

    // Update grade
    char choice;
    cout << "\n\nDo you want to update a grade? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        updateGrade(grades, numStudents);

        cout << "\nUpdated Grades\n";
        displayGrades(grades, numStudents);

        cout << "\nAverage Grade : " << calculateAverage(grades, numStudents);
        cout << "\nHighest Grade : " << findHighest(grades, numStudents);
        cout << "\nLowest Grade  : " << findLowest(grades, numStudents);
    }

    // Free allocated memory
    delete[] grades;
    grades = nullptr;

    cout << "\n\nMemory successfully released.";
    cout << "\nProgram finished.\n";

    return 0;
}

//--------------------------------------------------

void inputGrades(double* grades, int size)
{
    cout << "\nEnter student grades:\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> *(grades + i);   // Pointer arithmetic
    }
}

//--------------------------------------------------

void displayGrades(double* grades, int size)
{
    cout << "---------------------------\n";

    for (int i = 0; i < size; i++)
    {
        cout << "Student " << i + 1
             << " Grade: " << *(grades + i) << endl;
    }
}

//--------------------------------------------------

double calculateAverage(double* grades, int size)
{
    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += *(grades + i);
    }

    return sum / size;
}

//--------------------------------------------------

double findHighest(double* grades, int size)
{
    double highest = *grades;

    for (int i = 1; i < size; i++)
    {
        if (*(grades + i) > highest)
        {
            highest = *(grades + i);
        }
    }

    return highest;
}

//--------------------------------------------------

double findLowest(double* grades, int size)
{
    double lowest = *grades;

    for (int i = 1; i < size; i++)
    {
        if (*(grades + i) < lowest)
        {
            lowest = *(grades + i);
        }
    }

    return lowest;
}

//--------------------------------------------------

void updateGrade(double* grades, int size)
{
    int studentNumber;

    cout << "\nEnter student number to update (1-" << size << "): ";
    cin >> studentNumber;

    while (studentNumber < 1 || studentNumber > size)
    {
        cout << "Invalid student number. Try again: ";
        cin >> studentNumber;
    }

    cout << "Current Grade: " << *(grades + (studentNumber - 1)) << endl;

    cout << "Enter new grade: ";
    cin >> *(grades + (studentNumber - 1));

    cout << "Grade updated successfully!\n";
}