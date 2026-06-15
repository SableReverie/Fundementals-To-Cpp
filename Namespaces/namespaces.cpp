// ========================== Namespace ========================================

// A namespace is a container that groups related variables, functions, classes, and other identifiers.

// It prevents naming conflicts when different parts of a program (or different libraries) use the same name.

#include <iostream>

namespace Math {
    int value = 10;

    void display() {
        std::cout << "Inside Math namespace" << std::endl;
    }
}

int main() {
    std::cout << Math::value << std::endl;
    Math::display();
    
    return 0;
}
// output: 
    // 10
    // Inside Math namespace

/*
Why Namespaces Are Useful

    Without namespaces:

    int value = 5;

    Another library might also have:

    int value = 10;

This causes ambiguity.

    With namespaces:

    namespace A {
    int value = 5;
    }

    namespace B {
    int value = 10;
    }

    Now both can exist safely.

    std::cout << A::value << std::endl;
    std::cout << B::value << std::endl;

    Output:

    5
    10
*/

//Scope Resolution Operator (::)

//The scope resolution operator (::) is used to access members belonging to a specific namespace, class, or global scope.

//Syntax
//namespace_name::member_name

/*
Concept	Purpose	Example
Namespace	                    Groups related identifiers and avoids name conflicts	        namespace Math { ... }
Scope Resolution Operator (::)	Accesses members of a namespace or class	                    Math::value
Using Keyword	                Allows direct access without typing namespace name repeatedly	using namespace std;
*/
