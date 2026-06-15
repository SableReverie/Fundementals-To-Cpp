// ======================== Function Template ===========================

// One function, many types”

// A function template lets you write a function once and use it with different data types.
/*
#include <iostream>
using namespace std;

template<typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add(3, 5) << endl;        // int
    cout << add(2.5, 1.3) << endl;    // double
}
*/

// ================== Class Template =======================

// One class, many types

// A class template lets you create generic classes.
/*
#include <iostream>
using namespace std;

template<typename T>
class Box {
private:
    T value;

public:
    Box(T v) {
        value = v;
    }

    T getValue() {
        return value;
    }
};

int main() {
    Box<int> intBox(10);
    Box<string> strBox("Hello");

    cout << intBox.getValue() << endl;
    cout << strBox.getValue() << endl;
}
When you write:

    Box<int> intBox(10);

The compiler creates:

    class Box<int> {
        int value;
    };

    Same for string.
*/

// ================== Template Specialization ===========================

// Special behavior for specific type

// Sometimes, you want most types to behave the same but one type differently.
/*
#include <iostream>
using namespace std;

template<typename T>
class Printer {
public:
    void print(T value) {
        cout << "Generic: " << value << endl;
    }
};

// Special version for char
template<>
class Printer<char> {
public:
    void print(char value) {
        cout << "Character: " << value << endl;
    }
};

int main() {
    Printer<int> p1;
    p1.print(10);      // Uses generic version

    Printer<char> p2;
    p2.print('A');     // Uses specialized version
}

What happens?
    For int → generic version
    For char → special version

You override the template for a specific type.


*/

// ========================= Variadic Template ===========================

/*
Unlimited arguments (...)

A variadic template allows a function to take any number of arguments.
*/
/*
#include <iostream>
using namespace std;

void print() {
    cout << "End\n";
}

template<typename T, typename... Args>
void print(T first, Args... rest) {
    cout << first << " ";
    print(rest...);  // recursive call
}

int main() {
    print(1, 2.5, "Hello", 'A');
}

When you call:

print(1, 2.5, "Hello", 'A');

It becomes:

print(1, 2.5, "Hello", 'A')
print(2.5, "Hello", 'A')
print("Hello", 'A')
print('A')
print()

The ... means:

“There may be more arguments.”
*/

/*
Modern C++ (Better Way)

C++17 introduced fold expressions:

template<typename... Args>
void print(Args... args) {
    (cout << ... << args) << endl;
}
*/

/*
Templates work at compile time, not runtime.

That’s why they:

    Are very fast
    Generate code before program runs
    Can sometimes produce long compiler errors 
*/