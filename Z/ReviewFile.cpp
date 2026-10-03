// 'git push origin master'
/*
#include <iostream>
using std::cout, std::endl;

int main() {
    
    char charArray[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
    for (int i = 0; i < 12; i++) {
        cout << charArray[i];
    }
    cout << endl;

}
*/
/*
#include <iostream>
#include <string>
using std::cout, std::endl, std::string;
int main() {
    // Array of characters (must be null-terminated with '\0')
    char charArray[] = {'H', 'e', 'l', 'l', 'o', '\0'}; 
    
    // Pass it directly to the constructor
    string str(charArray); 
    
    cout << str; // Outputs: Hello
}
*/
/*
#include <iostream>
using std::cout, std::endl, std::string;
int main(){

    int myNum = 15;  // myNum is 15
    myNum = 10;  // Now myNum is 10
    cout << myNum;  // Outputs 10

    return 0;
}
    
*/
/*
#include <iostream>
using std::cout, std::endl;

int main() {

    int x = 10;
int y = 3;

    cout << (x + y) << "\n"; // 13
    cout << (x - y) << "\n"; // 7
    cout << (x * y) << "\n"; // 30
    cout << (x / y) << "\n"; // 3 (integer division)
    cout << (x % y) << "\n"; // 1

    int z = 5;
    ++z;
    cout << z << "\n"; // 6
    --z;
    cout << z << "\n"; // 5


    return 0;
}
*/
/*
#include <iostream>
using std::cout, std::endl, std::string;

int main(){

    string str1 = "Hello";
    string str2 = "World";

    string str3 = str1 + " " + str2; // Concatenation
    cout << str3; // Outputs: Hello World

    return 0;
}
*/
/*
#include <iostream>
using std::cout, std::endl, std::string;

int main(){
    string firstName = "John ";
    string lastName = "Doe";
    string fullName = firstName.append(lastName);
    cout << fullName;

 return 0;
}
*/

/*
// STRING LENGTH

#include <iostream>
using std::cout, std::endl, std::string;

int main(){
    
    string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "The length of the txt string is: " << txt.size();


    return 0;
}
*/
/*
#include <iostream>
#include <cmath>
using namespace std;
// Include the cmath library

int main () {
cout << sqrt(64);
cout << round(2.6);
cout << log(2);
return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {
  bool isCodingFun = true;
  bool isFishTasty = false;

  cout << boolalpha; // enable printing "true"/"false"

  cout << isCodingFun << "\n";   // Outputs true
  cout << isFishTasty << "\n";  // Outputs false
  return 0;
}
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
  int time = 20;
  string result = (time < 18) ? "Good day." : "Good evening.";
  cout << result;
  return 0;
}
*/

/*
#include <iostream>
#include <string>
using namespace std;

int main() {
  int time = 22;
  string message = (time < 12) ? "Good morning."
    : (time < 18) ? "Good afternoon."
    : "Good evening.";
  cout << message;
  return 0;
}
*/


/*
#include <iostream>
using namespace std;

int main(){

    string cars[5] = {"Volvo", "BMW", "Ford", "Mazda", "Toyota"};
    for (int i = 0; i < 5; i++) {
        cout << cars[i] << "\n";
    }
    return 0;
}
*/
/*
notes for vectors:
vector<int> v1 = {1, 2, 3}; // create a vector of integers with initial values
v1.push_back(4); // add an element to the end of the vector
v1.pop_back(); // remove the last element from the vector
v1.back(); // access the last element of the vector
v1.front(); // access the first element of the vector
v1.size(); // get the number of elements in the vector
v1.clear(); // remove all elements from the vector
v1.empty(); // check if the vector is empty
v1.insert(v1.begin() + 1, 5); // insert an element at a specific position
v1.erase(v1.begin() + 1); // remove an element at a specific position
v1.resize(10); // change the size of the vector
v1.reserve(20); // reserve space for a certain number of elements
v1.shrink_to_fit(); // reduce the capacity of the vector to fit its size
v1.swap(v2); // swap the contents of two vectors
v1.assign(5, 10); // assign new values to the vector
v1.emplace_back(6); // construct and add an element to the end of the vector
v1.emplace(v1.begin() + 1, 7); // construct and insert an element at a specific position
v1.at(2); // access an element at a specific position with bounds checking
v1.data(); // get a pointer to the underlying array of the vector
v1.capacity(); // get the number of elements that can be held in currently allocated storage
v1.shrink_to_fit(); // reduce the capacity of the vector to fit its size
v1.clear(); // remove all elements from the vector

// ITERATING THROUGH VECTORS
vector<int> v1 = {1, 2, 3, 4, 5};
for (int i = 0; i < v1.size(); i++) {
    cout << v1[i] << " ";
}
    for(auto itr = v1.begin(); itr != v1.end(); ++itr) {
        cout << *itr << " ";
    }
*/


/*
// GET THE SIZE OF AN ARRAY

int myNumbers[5] = {10, 20, 30, 40, 50};
cout << sizeof(myNumbers) / sizeof(myNumbers[0]);
cout << getArraySize(myNumbers) << endl;
*/

// Loop Through an Array with sizeof()
// instead of

// int myNumbers[5] = {10, 20, 30, 40, 50};
// for (int i = 0; i < sizeof(myNumbers) / sizeof(myNumbers[0]); i++) {
//     cout << myNumbers[i] << " ";
// }
// IT is better to write a function to get the size of an array, like this:
/*
int myNumbers[5] = {10, 20, 30, 40, 50};
for (int i = 0; i < sizeof(myNumbers) / sizeof(myNumbers[0]); i++) {
  cout << myNumbers[i] << "\n";
}
*/

// Multi-Dimensional Arrays

/*
#include <iostream>
using namespace std;
//      Column
//      0  1  2
//Row
//0     1  2  3
//1     4  5  6
//2     7  8  9

int main () {

    int numbers[3][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            cout << numbers[i][j] << " ";
        }
        cout << "\n";
    }

  return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main(){
    int rowSum = 0;
    int scores[3][4] = {
    {10, 20, 30, 40},
    {15, 25, 35, 45},
    {50, 60, 70, 80}
};
// calculate the sum of each row
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            rowSum += scores[i][j];
    }
    cout << "Sum of row " << i << ": " << rowSum << endl;
}
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main(){
    // Find the Largest Number and print the row and column
    int values[4][3] = {
    {8, 12, 5},
    {20, 3, 15},
    {7, 25, 10},
    {9, 18, 6}
};

    int largest = values[0][0];
    int largestRow = 0;
    int largestCol = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            if(values[i][j] > largest) {
                largest = values[i][j];
                largestRow = i;
                largestCol = j;
            }
        }
    }

    cout << "Largest number: " << largest << endl;
    cout << "Row: " << largestRow << ", Column: " << largestCol << endl;

    return 0;
}
*/
/*
// Count Even and Odd Numbers in a 2D Array
#include <iostream>
using namespace std;

int main(){

    int nums[3][5] = {
    {4, 7, 10, 13, 16},
    {1, 8, 5, 12, 19},
    {20, 21, 22, 23, 24}
};
    int evenCount = 0;
    int oddCount = 0;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            if(nums[i][j] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
    }

    cout << "Even numbers: " << evenCount << endl;
    cout << "Odd numbers: " << oddCount << endl;

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main()
{
    int matrix[4][4] = {
        {5, 8, 2, 1},
        {7, 9, 6, 4},
        {3, 10, 12, 11},
        {15, 14, 13, 16}
    };

    int target;
    bool found = false;

    cout << "Enter a number to search: ";
    cin >> target;

    // Loop through each row
    for (int row = 0; row < 4; row++)
    {
        // Loop through each column
        for (int col = 0; col < 4; col++)
        {
            if (matrix[row][col] == target)
            {
                cout << "Found at Row " << row
                     << ", Column " << col << endl;

                found = true;
            }
        }
    }

    if (!found)
    {
        cout << "Number not found." << endl;
    }

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {
  // We put "1" to indicate there is a ship.
  bool ships[4][4] = {
    { 0, 1, 1, 0 },
    { 0, 0, 0, 0 },
    { 0, 0, 1, 0 },
    { 0, 0, 1, 0 }
  };

  // Keep track of how many hits the player has and how many turns they have played in these variables
  int hits = 0;
  int numberOfTurns = 0;

  // Allow the player to keep going until they have hit all four ships
  while (hits < 4) {
    int row, column;

    cout << "Selecting coordinates\n";

    // Ask the player for a row
    cout << "Choose a row number between 0 and 3: ";
    cin >> row;

    // Ask the player for a column
    cout << "Choose a column number between 0 and 3: ";
    cin >> column;

    // Check if a ship exists in those coordinates
    if (ships[row][column]) {
      // If the player hit a ship, remove it by setting the value to zero.
      ships[row][column] = 0;

      // Increase the hit counter
      hits++;

      // Tell the player that they have hit a ship and how many ships are left
      cout << "Hit! " << (4-hits) << " left.\n\n";
    } else {
      // Tell the player that they missed
      cout << "Miss\n\n";
    }

    // Count how many turns the player has taken
    numberOfTurns++;
  }

  cout << "Victory!\n";
  cout << "You won in " << numberOfTurns << " turns";
  
  return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    // 1. Define the structure type (Note the semicolon at the end)
    struct MyStructureType {
        int myNum;
        string myString;
    };

    // 2. Create an instance variable of that type
    MyStructureType myStructure;

    myStructure.myNum = 1;
    myStructure.myString = "Hello World!";

    cout << myStructure.myNum << "\n";
    cout << myStructure.myString << "\n";

    return 0;
}
*/
/*
// NEW AND DELETE MEMORY MANAGEMENT

// The new keyword lets you manage memory yourself.
// HEAP memory is a pool of memory that is used for dynamic memory allocation.
#include <iostream>
using namespace std;

int main() {
  int* ptr = new int;
  *ptr = 35;
  cout << *ptr;

  // DON"T FORGET TO DELETE THE MEMORY WHEN YOU ARE DONE WITH IT
  delete ptr; // Free the memory
  return 0;
}
*/
/*
// Dynamic arrays are useful when you don't know the size of the array in advance 
// - like when the size depends on user input or other values that are not known at the start of the program.
#include <iostream>
#include <string>
using namespace std;

int main() {
  int numGuests;
  cout << "How many guests? ";
  cin >> numGuests;

  // Check for invalid input
  if (numGuests <= 0) {
    cout << "Number of guests must be at least 1.\n";
    return 0;
  }

  // Create memory space for x guests (an array of strings)
  string* guests = new string[numGuests];

  // Ignore the leftover newline character after reading numGuests
  cin.ignore();

  // Enter guest names
  for (int i = 0; i < numGuests; i++) {
    cout << "Enter name for guest " << (i + 1) << ": ";
    getline(cin, guests[i]); // Read the full name (including spaces)
  }

  // Show all guests
  cout << "\nGuests checked in:\n";
  for (int i = 0; i < numGuests; i++) {
    cout << guests[i] << "\n";
  }

  delete[] guests; // Clean up memory
  return 0;
}
*/
/*
#include <iostream>

int main (){

    int x = 5;
    int* ptr = &x;

    std::cout << "The value of x: " << x << '\n';
    std::cout << "The adress of x: " << &x << '\n';
    std::cout << "The value of the pointer: " << *ptr << '\n';
    std::cout << "The adress of the pointer: " << &ptr << '\n';
    return 0;
}
*/
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

/*
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30};
    int* ptr = arr;
    
    for (int i = 0; i < 3; i++) {
        cout << *ptr << endl;
        ptr++;
    }
    
    return 0;
}
    
*/


#include <iostream>
#include <expected>
#include <string>

std::expected<int, std::string> divide(int a, int b)
{
    if (b == 0)
        return std::unexpected(std::string("Division by zero"));

    return a / b;
}

int main()
{
    auto result = divide(10, 2);

    if (result.has_value())
        std::cout << "Result: " << result.value() << '\n';
    else
        std::cout << "Error: " << result.error() << '\n';

    return 0;
}