/*
#include <iostream>
using std::endl, 
std::string;

int main(){
    int n = 10;
    for(int i = 1; i <= n; i++){
        std::cout << "  * " << " ";
    }
    return 0;
}
*/

#include <iostream>
#include <string> // Added to ensure standard string compatibility

using std::endl;
using std::string;
using std::cout;
using std::cin;

class Print {
private:
    string name;
public:
    void callName(string name) {
        this->name = name;
    }
    
    // Added a method to actually display the stored name
    void displayName() {
        cout << "Hello, " << name << "!" << endl;
    }
};

int main() {
    Print printer;                // Create an object of the Print class
    printer.callName("Alice");    // Pass a name string to the object
    printer.displayName();        // Output the result to the console