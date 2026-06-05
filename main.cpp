// THIS FILE WILL CONTAIN AN C++ PRACTICES

//#include <iostream>

//int main(){
    // WE USE STD::STRING TO STORE TEXTUAL DATA AND STD::COUT TO OUTPUT TO THE CONSOLE 
    /*
    PRIMITIVE DATA TYPES:
    - int: Used to store whole numbers (e.g., 42, -7).
    - double: Used to store floating-point numbers (e.g., 3.14, -0.001).
    - char: Used to store a single character (e.g., 'A', 'z').
    - bool: Used to store boolean values (true or false).
    - void: Represents the absence of a value, often used for functions that do not return anything.
    STANDARD LIBRARY DATA TYPES:
    - std::string: Used to store and manipulate sequences of characters (e.g., "Hello, World!").
    - std::vector: A dynamic array that can resize itself automatically when elements are added.
    - std::map: A collection of key-value pairs, where each key is unique and maps to a value.
    - std::set: A collection of unique elements, where each element can only appear once...
    */

// }


/*
#include <iostream>

void calSpeed(float distance, float time) {
    if (time > 0) {
        float speed = distance / time;
        std::cout << "Speed: " << speed << " units per time" << std::endl;
    } else {
        std::cout << "Time must be greater than zero to calculate speed." << std::endl;
    }
}
int main() {
   
    float distance, time;

    std::cout << "Enter distance: ";
    std::cin >> distance;

    std::cout << "Enter time: ";
    std::cin >> time;

    calSpeed(distance, time);
   
    return 0;
}
*/
/*
#include <iostream>

int main(){
  
    float math, science, filipino, history, pe, totalAverage;
    std::cout << "Enter your Math grade: ";
    std::cin >> math;
    std::cout << "Enter your Science grade: ";
    std::cin >> science;
    std::cout << "Enter your Filipino grade: ";
    std::cin >> filipino;
    std::cout << "Enter your History grade: ";
    std::cin >> history;
    std::cout << "Enter your PE grade: ";
    std::cin >> pe;
    totalAverage = (math + science + filipino + history + pe) / 5;
    if(totalAverage >= 90 && totalAverage <= 100){
        std::cout << "Your average grade is: " << totalAverage << " and your equivalent grade is: A" << std::endl;
    } else if(totalAverage >= 80 && totalAverage < 90){
        std::cout << "Your average grade is: " << totalAverage << " and your equivalent grade is: B" << std::endl;
    } else if(totalAverage >= 70 && totalAverage < 80){
        std::cout << "Your average grade is: " << totalAverage << " and your equivalent grade is: C" << std::endl;
    } else if(totalAverage >= 60 && totalAverage < 70){
        std::cout << "Your average grade is: " << totalAverage << " and your equivalent grade is: D" << std::endl;
    } else if(totalAverage >= 0 && totalAverage < 60){
        std::cout << "Your average grade is: " << totalAverage << " and your equivalent grade is: F" << std::endl;
    } else {
        std::cout << "Invalid input. Please enter grades between 0 and 100." << std::endl;
    }

    return 0;
}
*/
/*
#include <iostream>

int main(){

    float temperature, convertedTemperature;
    char unit;

    std::cout << "Enter temperature: ";
    std::cin >> temperature;
    std::cout << "Enter unit (C for Celsius, F for Fahrenheit): ";
    std::cin >> unit;
    if (unit == 'C' || unit == 'c') {
        convertedTemperature = (temperature * 9 / 5) + 32;
        std::cout << temperature << " degrees Celsius is equal to " << convertedTemperature << " degrees Fahrenheit." << std::endl;
    } else if (unit == 'F' || unit == 'f') {
        convertedTemperature = (temperature - 32) * 5 / 9;
        std::cout << temperature << " degrees Fahrenheit is equal to " << convertedTemperature << " degrees Celsius." << std::endl;
    } else {
        std::cout << "Invalid unit. Please enter 'C' for Celsius or 'F' for Fahrenheit." << std::endl;
    }
    std::cout << "Thank you for using the temperature converter!" << std::endl;

    return 0;
}
*/
/*
#include <iostream>

int main(){

    int num, sum, count;
    count = 0;
    std::cout << "Enter a initial sum: " << std::endl;
    while(count < 6){
        std::cout << "Enter a number: ";
        std::cin >> num;
        sum += num;
        count++;
    }
    std::cout << "The sum is: " << sum << std::endl;
    return 0;   
}
*/
/*
#include <iostream>

int main() {
    int num;
    int sumEven = 0;
    int sumOdd = 0;

    std::cout << "Enter integers (enter 0 to stop):" << std::endl;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> num;

        if (num == 0) {
            break;
        }
        else if (num % 2 == 0) {
            sumEven += num;
        }
        else {8
            sumOdd += num;
        }
    }

    std::cout << "The sum of even numbers is: " << sumEven << std::endl;
    std::cout << "The sum of odd numbers is: " << sumOdd << std::endl;

    return 0;
}
*/
/*
#include <iostream>

int main() {
    int numTerms, prev, curr, next, i;

    std::cout << "Enter the number of terms in the Fibonacci sequence: ";
    std::cin >> numTerms;

    prev = 0;
    curr = 1;

    std::cout << "Fibonacci Sequence up to " << numTerms << " terms:" << std::endl;

    for (i = 1; i <= numTerms; i++) {
        std::cout << prev << " ";

        next = prev + curr;
        prev = curr;
        curr = next;
    }

    std::cout << std::endl;

    return 0;
}
*/
/*
#include <iostream>

int larger(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    int num;
    int min, max;

    std::cout << "Enter 10 numbers: " << std::endl;
    std::cin >> num;

    max = num;
    min = num;

    for (int i = 1; i < 10; i++) {
        std::cin >> num;

        max = larger(max, num);

        if (num < min) {
            min = num;
        }
    }

    std::cout << "Largest number: " << max << std::endl;
    std::cout << "Smallest number: " << min << std::endl;

    return 0;
}
*/
/*
#include <iostream>

int findSmallestIndex(int arr[], int size){
    if(size <= 0){
        std::cout << "Array is empty" << std::endl;
        return -1;
    }
    
    int smallestIndex = 0;
    for(int i = 1; i < size; ++i){
        if(arr[i] < arr[smallestIndex]){
            smallestIndex = i;
        }
    }
    return smallestIndex;
}
int findLargestIndex(int arr[], int size){
    if(size <= 0){
        std::cout << "Array is empty" << std::endl;
        return -1;
    }
    int largestIndex = 0;
    for(int i = 1; i < size; ++i){
        if(arr[i] > arr[largestIndex]){
            largestIndex = i;
        }
    }
    return largestIndex;
}

int main(){

 int size;

 std::cout << "Enter the number of elements: " << std::endl;
 std::cin >> size;

 if(size <= 0){
    std::cout << "Invalid size" << std::endl;
    return 0;
 }
 int arr[size]; // create array of user defined size

 std::cout << "Enter " << size << " elements" << std::endl;
 for(int i = 0; i < size; ++i){
    std::cout << "Element " << i + 1 << ": " << std::endl;
    std::cin >> arr[i];
 }
  int smallestIndex = findSmallestIndex(arr, size);
  int LargestIndex = findLargestIndex(arr, size);

  std::cout << "Index of the smallest element: " << smallestIndex << std::endl;
  std::cout << "Index of the largest element: " << LargestIndex << std::endl;

  std::cout << "Smallest element " << arr[smallestIndex] << std::endl;
  std::cout << "Largest element " << arr[LargestIndex] << std:: endl;

}
*/
/*
#include <iostream>

int main(){


    int const MAX_SIZE = 100;
    char inputString[MAX_SIZE];

    std::cout << "Enter a String: " << std::endl;
    std::cin.getline(inputString, MAX_SIZE);
    std::cout << "Uppercase letters in the string: " << std::endl;

    for(int i = 0; inputString[i] != '\0'; ++i){
        if(inputString[i] >= 'A' && inputString[i] <= 'Z'){
            std::cout << inputString[i];
        }
    }
    if(inputString[0] == '\0'){
        std::cout << "No uppercase letters found";
    }
    return 0;
}
*/
/*
#include <iostream>

const int ROWS = 10;
const int SEATS_PER_ROW = 6;

void displaySeats(bool seats[ROWS][SEATS_PER_ROW]) {
    std::cout << "\nCurrent Seating Arrangement:\n";

    for (int i = 0; i < ROWS; i++) {
        std::cout << "Row " << (i + 1) << ": ";

        for (int j = 0; j < SEATS_PER_ROW; j++) {
            if (seats[i][j])
                std::cout << "X ";
            else
                std::cout << "O ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void reserveSeat(bool seats[ROWS][SEATS_PER_ROW], int row, int seat) {
    if (row >= 1 && row <= ROWS &&
        seat >= 1 && seat <= SEATS_PER_ROW) {

        if (!seats[row - 1][seat - 1]) {
            seats[row - 1][seat - 1] = true;
            std::cout << "Seat at Row " << row
                      << ", Seat " << seat
                      << " reserved.\n";
        } else {
            std::cout << "Seat at Row " << row
                      << ", Seat " << seat
                      << " is already occupied.\n";
        }

    } else {
        std::cout << "Invalid row or seat number.\n";
    }
}

void cancelSeat(bool seats[ROWS][SEATS_PER_ROW], int row, int seat) {
    if (row >= 1 && row <= ROWS &&
        seat >= 1 && seat <= SEATS_PER_ROW) {

        if (seats[row - 1][seat - 1]) {
            seats[row - 1][seat - 1] = false;
            std::cout << "Seat at Row " << row
                      << ", Seat " << seat
                      << " cancelled.\n";
        } else {
            std::cout << "No reservation found for seat at Row "
                      << row << ", Seat " << seat << ".\n";
        }

    } else {
        std::cout << "Invalid row or seat number.\n";
    }
}

int main() {
    bool seats[ROWS][SEATS_PER_ROW] = {};

    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Seats\n";
        std::cout << "2. Reserve a Seat\n";
        std::cout << "3. Cancel Seat Reservation\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        switch (choice) {
        case 1:
            displaySeats(seats);
            break;

        case 2: {
            int row, seat;

            std::cout << "Enter row number (1-" << ROWS << "): ";
            std::cin >> row;

            std::cout << "Enter seat number (1-" << SEATS_PER_ROW << "): ";
            std::cin >> seat;

            reserveSeat(seats, row, seat);
            break;
        }

        case 3: {
            int row, seat;

            std::cout << "Enter row number (1-" << ROWS << "): ";
            std::cin >> row;

            std::cout << "Enter seat number (1-" << SEATS_PER_ROW << "): ";
            std::cin >> seat;

            cancelSeat(seats, row, seat);
            break;
        }

        case 4:
            std::cout << "Exiting program.\n";
            break;

        default:
            std::cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
*/
/*
#include <iostream>
int add(int a, int b){
    return a + b;
}
int main(){
    
    std::cout << add(5, 2) << std::endl;
    return 0;
}
*/

/*
// IMPLICIT TYPE CONVERSION (AUTOMATIC)
#include <iostream>
using namespace std;

int main() {
    int num = 10;
    double result = num;   // int converted to double automatically

    cout << "num = " << num << endl;
    cout << "result = " << result << endl;

    return 0;
}
*/
/*
// EXPLICIT TYPE CONVERSION (Type Casting)
#include <iostream>
using namespace std;

int main() {
    double price = 19.99;

    int wholeNumber = (int)price;

    cout << "Original value: " << price << endl;
    cout << "Converted value: " << wholeNumber << endl;

    return 0;
}
*/


/*
// static_cast 
#include <iostream>
using namespace std;

int main() {
    double score = 95.75;

    int roundedScore = static_cast<int>(score);

    cout << "Score: " << score << endl;
    cout << "Converted Score: " << roundedScore << endl;

    return 0;
}
*/

/*
// dynamic_cast
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* animal = new Dog();

    Dog* dog = dynamic_cast<Dog*>(animal);

    if (dog) {
        dog->bark();
    } else {
        cout << "Conversion failed" << endl;
    }

    delete animal;
    return 0;
}
*/
/*
// failed dynamic_cast
#include <iostream>
using namespace std;

class Animal {
public:
    virtual ~Animal() {}
};

class Dog : public Animal {
};

class Cat : public Animal {
};

int main() {
    Animal* animal = new Cat();

    Dog* dog = dynamic_cast<Dog*>(animal);

    if (dog == nullptr) {
        cout << "Not a Dog!" << endl;
    }

    delete animal;
}
*/ // const_cast = Const correction , reinterpret_cast = Low-level systems work only (not safe).
/*
// Memory Adresses
#include <iostream>

int main(){

    // memory adress = a location in memory where data is stored
    // a memory adress can be accessed with & (adress-of operator)

    std::string name = "Prince";
    int age = 21;
    bool student = true;

    std::cout << &name << std::endl;
    std::cout << &age << std::endl;
    std::cout << &student << std::endl;

    return 0;
}
*/
/*
#include <iostream>

using std::cout, std::cin;
using std::endl;

int main() {
    long int num1, num2, sum, difference, product;
    float quotient;
    int choice;

    cout << "Enter Number: ";
    cin >> num1;

    cout << "Enter Another Number: ";
    cin >> num2;

    cout << "\nChoose an operation:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            sum = num1 + num2;
            cout << "The sum of " << num1 << " and "
                 << num2 << " is " << sum << endl;
            break;

        case 2:
            difference = num1 - num2;
            cout << "The difference of " << num1 << " and "
                 << num2 << " is " << difference << endl;
            break;

        case 3:
            product = num1 * num2;
            cout << "The product of " << num1 << " and "
                 << num2 << " is " << product << endl;
            break;

        case 4:
            if (num2 != 0) {
                quotient = static_cast<float>(num1) / num2;
                cout << "The quotient of " << num1 << " and "
                     << num2 << " is " << quotient << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;

        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
*/
