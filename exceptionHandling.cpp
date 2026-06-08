// Exception Handling 
/*
Exception handling in C++ is a way to deal with runtime errors without crashing the program unexpectedly. 
It allows you to detect errors, report them, and recover gracefully.
*/

// ======================== try ============================
// A try block contains code that might cause an exception (error).

#include <iostream>
using namespace std;

int main() {
    try {
        cout << "Inside try block" << endl;

        int num = 10;
        int den = 0;

        if (den == 0) {
            throw "Cannot divide by zero!";
        }

        cout << num / den << endl;
    }
    catch (const char* msg) {
        cout << "Caught exception: " << msg << endl;
    }

    return 0;
}