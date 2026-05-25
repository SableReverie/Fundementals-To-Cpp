/*
// VECTOR ARRAY
#include <iostream> 
#include <vector> 
using namespace std; 
int main() { 
    vector<int> arr = {10, 20, 30, 40, 50}; 
    arr.push_back(100); 
    for(int x : arr){ 
        cout << x << " "; 
    } 
    return 0; 
}
*/
/*
#include <iostream>
#include <list>
using namespace std;
// LINKED LIST 
int main(){
    
     list<string> cars;
     cars = {"BMW", "Audi", "Mercedes"};

     cars.push_front("Volvo");
     cars.push_back("Ford");

     cars.pop_back();
     cars.pop_front();

     cout << "The first car is: " << cars.front() << '\n';
     cout << "The last car is: " << cars.back() << '\n';

     cout << "The list of all cars: " << cars.size() << '\n';
     
     cout << "The list of all cars: " << cars.empty() << '\n';
    return 0;
}
    */
    /*
    list<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    for (int i = 0; i < cars.size(); i++) {
    cout << cars[i] << "\n";
    */ /*
    list<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

    for (string car : cars) {
    cout << car << "\n";
    */


#include <iostream>
#include <stack>
using namespace std;

int main(){
  
    stack<string> cars;

    cars.push("Volvo");
    cars.push("BMW");

    cout << "The top car is: " << cars.top() << '\n';
    cout << "The size of the stack is: " << cars.size() << '\n';

    return 0;
}
