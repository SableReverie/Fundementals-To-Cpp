// Exception Handling 
/*
Exception handling in C++ is a way to deal with runtime errors without crashing the program unexpectedly. 
It allows you to detect errors, report them, and recover gracefully.
*/

// ======================== try ============================
// A try block contains code that might cause an exception (error).
/*
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
*/
/*
Explanation
The code inside try is monitored.
If an exception occurs, execution stops at that point.
Control jumps to a matching catch block.

Think of try as:

"Watch this code because something might go wrong."
*/

// ============================= catch =================================
// A catch block handles exceptions thrown from a try block.
/*
#include <iostream>
using namespace std;

int main() {
    try {
        int num = 10;
        int den = 0;

        if (den == 0) {
            throw "Cannot divide by zero!";
        }

        cout << num / den << endl;
    }
    catch (const char* message) {
        cout << "Error: " << message << endl;
    }

    cout << "Program continues..." << endl;

    return 0;
}
*/
/*
Explanation:
    throw sends an exception.
    catch receives and handles it.
    The program does not crash.
*/

// ======================= throw =============================
// throw is used to generate an exception.
/*
#include <iostream>
using namespace std;

int main() {
    try {
        throw 404;
    }
    catch (int errorCode) {
        cout << "Error code: " << errorCode << endl;
    }
    // Result = Error code: 404
    return 0;
}
*/

/*
    throw can send:

    Integers
    Strings
    Objects
    Custom exception classes
*/

// Exception Hierarchy

/*
Hierarchy (simplified):

std::exception
│
├── std::runtime_error
├── std::logic_error
├── std::bad_alloc
├── std::out_of_range
└── std::invalid_argument
*/
// Example of Out of range
/*
#include <iostream>
#include <vector>
using namespace std;

int main() {
    try {
        vector<int> nums = {1, 2, 3};

        cout << nums.at(5);
    }
    catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
*/

/*
Output:
    Exception: vector::_M_range_check...

Explanation:
    at() checks bounds.
    Index 5 does not exist.
    out_of_range exception is thrown.
    e.what() returns an error message.
*/


/*
Why use exception?

Since many exceptions inherit from std::exception, one catch block can handle many error types.
*/

/*
Custom Exceptions

You can create your own exception class when built-in exceptions are not enough.
*/

// Simple Custom Exception 
/*
#include <iostream>
using namespace std;

class NegativeNumberException {};

int main() {
    try {
        int age = -5;

        if (age < 0) {
            throw NegativeNumberException();
        }

        cout << age << endl;
    }
    catch (NegativeNumberException) {
        cout << "Age cannot be negative!" << endl;
    }

    return 0;
}
*/
// Output = Age cannot be negative!

// Example 2: Custom Exception with Message
/*
#include <iostream>
#include <exception>
using namespace std;

class InvalidAgeException : public exception {
public:
    const char* what() const noexcept override {
        return "Age must be between 0 and 120";
    }
};

int main() {
    try {
        int age = -10;

        if (age < 0 || age > 120) {
            throw InvalidAgeException();
        }
    }
    catch (const InvalidAgeException& e) {
        cout << e.what() << endl;
    }

    return 0;
}


result: 
Age must be between 0 and 120

Explanation:
InvalidAgeException inherits from std::exception.
Overrides what().
Provides a custom error message.
*/

// ====================== Complete Example =====================
/*
#include <iostream>
#include <exception>
using namespace std;

class InsufficientBalanceException : public exception {
public:
    const char* what() const noexcept override {
        return "Insufficient account balance!";
    }
};

int main() {
    double balance = 1000;
    double withdraw = 1500;

    try {
        if (withdraw > balance) {
            throw InsufficientBalanceException();
        }

        balance -= withdraw;
        cout << "New balance: " << balance << endl;
    }
    catch (const InsufficientBalanceException& e) {
        cout << "Transaction Failed: "
             << e.what() << endl;
    }

    cout << "Thank you for using the bank system."
         << endl;

    return 0;
}
*/

/*
Easy Memory Trick

Think of exception handling like a football game:

try → Player attempts a play.
throw → Player throws the ball (error occurs).
catch → Another player catches the ball (handles the error).
exception hierarchy → Different kinds of balls/errors.
custom exception → Your own specially designed ball/error type.

Flow:

try
  ↓
throw
  ↓
catch

This is the core exception-handling mechanism used throughout C++.
*/