// CONTROL FLOWS

// =================== if statement ============================
/*
#include <iostream>

int main(){

    int short num1 = 0;

    std::cout << "Enter A number: " << std::endl;
    std::cin >> num1;

    if(num1 > 0){
        std::cout << "The number is positive!";
    } else if (num1 < 0){
        std::cout << "The number is negative!"; 
    } else {
        std::cout << "The number is Zero!";
    }

    return 0;
}*/
/*
#include <iostream>

int main(){
    int age;
    bool isAdult = true;
    bool isMinor = false;

    std::cout << "Enter your age: " << std::endl;
    std::cin >> age;
    
    if(age >= 18){
        std::cout << "You are a Adult";
    } else if (age > 0 && age <= 17){
        std::cout << "You are a Minor";
    } else {
        std::cout << "You are not born!";
    }
    return 0;
}
*/
// DIVISIBLE NUMBERS
/*
#include <iostream>

using namespace std;

int main() {
    int numerator, denominator;

    // Get user input
    cout << "Enter a Number (Numerator): ";
    cin >> numerator;
    cout << "Enter another Number (Denominator): ";
    cin >> denominator;

    // Check divisibility
    if (numerator % denominator == 0) {
        cout << numerator << " is divisible by " << denominator << endl;
    } else {
        cout << numerator << " is not divisible by " << denominator << endl;
    }

    return 0;
}   
*/
// =================== if-else statement ============================
/*
#include <iostream>

int main(){
    int short num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if(num % 2 == 0){
        std::cout << "The number " << num << " is Even!";
    } else {
        std::cout << "The number " << num << " is Odd!";
    } 
    return 0;
}
*/
/*
#include <iostream>
#include <limits>
#include <string>

int main() {
    std::string student;
    int age;
    float score;

    std::cout << "Enter your name: ";
    std::getline(std::cin, student);

    // Safe age input
    while (true) {
        std::cout << "Enter your age: ";

        if (std::cin >> age) {
            break;
        }

        std::cout << "Invalid input. Please enter a valid integer.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Safe score input
    while (true) {
        std::cout << "Enter your exam score: ";

        if (std::cin >> score) {
            break;
        }

        std::cout << "Invalid input. Please enter a valid number.\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nYour name is " << student << '\n';
    std::cout << "Your age is " << age << '\n';

    if (score >= 75) {
        std::cout << "You passed the exam!\n";
    } else {
        std::cout << "You failed the exam!\n";
    }

    return 0;
}
*/

// =================== nested if ============================
/*
#include <iostream>
#include <string>

int main() {
    int age;
    std::string name;
    char citizenResponse;
    bool isCitizen;

    std::cout << "Hi! What is your name? ";
    std::getline(std::cin, name);

    std::cout << "What is your age? ";
    std::cin >> age;

    std::cout << "Are you a citizen? (Y/N): ";
    std::cin >> citizenResponse;

    isCitizen = (citizenResponse == 'Y' || citizenResponse == 'y');

    if (age >= 18 && isCitizen) {
        std::cout << "Hello, " << name
                  << "! You are eligible to vote.\n";
    }
    else if (age < 18) {
        std::cout << "Hello, " << name
                  << "! You are not eligible to vote because you are under 18.\n";
    }
    else {
        std::cout << "Hello, " << name
                  << "! You are not eligible to vote because you are not a citizen.\n";
    }

    return 0;
}
*/
/*
#include <iostream>

int main(){

    int age;
    bool isCitizen;
    char choice;
    std::string name;

    std::cout << "What is your name? ";
    std::getline(std::cin, name);

    std::cout << "What is your age? ";
    std::cin >> age;

    std::cout << "Are you a citizen? ";
    std::cin >> choice;
    isCitizen = (choice == 'Y' || choice== 'y'); 
    if(age >= 18){
        if(isCitizen){
            std::cout << "You are eligible to vote!" << std::endl;
        } else if(age < 18){ 
            std::cout << "You are a minor!" << std::endl;
        } else {
            std::cout << "You are not a citizen!" << std::endl;
        }
    }
    return 0;
}
*/
/*
#include <iostream>
using std::cout, std::endl, std::string;
int main(){
    string NameOfTheStudent;
    short int score = 0;
    char choice;
    cout << "Hello What is your name? " << '\n';
    std::getline(std::cin, NameOfTheStudent);

    cout << "Did you have the proof yesterday?(90): ";
    std::cin >> choice;

    choice = (choice == 'Y' || choice == 'y'); 
    
    cout << "What score did you get? ";
    std::cin >> score;
    if(choice){
        if(score >= 90){
            cout << "Excellent Student!";
        } else if (score <= 90){
            cout << "Good Student!";
        } else {
            cout << "Good!";
        }
    }
    return 0;
}
*/
// ATM 
/*
#include <iostream>

int main() {
    // Simulated account data
    const int CORRECT_PIN = 1234;
    double accountBalance = 5000.00;

    // User input variables
    int enteredPin;
    double withdrawalAmount;

    // Step 1: Prompt for PIN
    std::cout << "Enter your 4-digit PIN: ";
    std::cin >> enteredPin;

    // Step 2: Check if PIN is correct
    if (enteredPin == CORRECT_PIN) {
        // Step 3: Prompt for withdrawal amount
        std::cout << "PIN accepted. Current Balance: $" << accountBalance << "\n";
        std::cout << "Enter the amount to withdraw: ";
        std::cin >> withdrawalAmount;

        // Step 4: Check if balance is sufficient
        if (withdrawalAmount <= accountBalance) {
            // Update and display success
            accountBalance = accountBalance - withdrawalAmount;
            std::cout << "Withdrawal successful!\n";
            std::cout << "Please take your cash.\n";
            std::cout << "Remaining Balance: $" << accountBalance << "\n";
        } 
        else {
            // Error for insufficient funds
            std::cout << "Transaction denied: Insufficient funds.\n";
        }
    } 
    else {
        // Error for incorrect PIN
        std::cout << "Transaction denied: Incorrect PIN.\n";
    }

    return 0;
}
*/
/*
#include <iostream>
using std::endl, std::cout, std::cin;
int main(){

    int day;

    cout << "Enter The day of the week: ";
    cin >> day;

    switch(day){
        case 1: {
            cout << "It's Monday!";
            break;
        }
        case 2: {
            cout << "It's Tuesday!";
            break;
        }
        case 3: {
            cout << "It's Wednesday!";
            break;
        }
        case 4: {
            cout << "It's Thursday!";
            break;
        }
        case 5: {
            cout << "It's Friday!";
            break;
        }
        default:
        cout << "Invalid Input!";
    }
    return 0;
}
*/
/*
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int choice;
    int quantity;
    double totalAmount = 0.0;
    
    // Set output format for currency
    cout << fixed << setprecision(2);

    do {
        // Display Main Menu
        cout << "\n====== RESTAURANT MENU ======" << endl;
        cout << "1. Burger - $5.99" << endl;
        cout << "2. Pizza - $9.99" << endl;
        cout << "3. Fries - $2.49" << endl;
        cout << "4. Exit" << endl;
        cout << "=============================" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter quantity for Burger: ";
                cin >> quantity;
                totalAmount += (5.99 * quantity);
                cout << quantity << " Burger(s) added to your cart." << endl;
                break;
            case 2:
                cout << "Enter quantity for Pizza: ";
                cin >> quantity;
                totalAmount += (9.99 * quantity);
                cout << quantity << " Pizza(s) added to your cart." << endl;
                break;
            case 3:
                cout << "Enter quantity for Fries: ";
                cin >> quantity;
                totalAmount += (2.49 * quantity);
                cout << quantity << " order(s) of Fries added to your cart." << endl;
                break;
            case 4:
                cout << "\nExiting system..." << endl;
                cout << "Total Bill: $" << totalAmount << endl;
                cout << "Thank you for dining with us!" << endl;
                break;
            default:
                cout << "Invalid choice! Please select a valid option (1-4)." << endl;
        }
    } while(choice != 4);

    return 0;
}
*/
/*
#include <iostream>

using std::endl, std::cout, std::cin;

int main(){

    
    for(int i = 1; i <= 10; i++){
        cout << i << '\n';
    }

    return 0;
}
*/
/*
#include <iostream>

using std::endl, std::cout, std::cin;

int main(){

    for(int i = 10; i >= 0; i--){
        cout << i << '\n';
    }

    return 0;
}
*/
/*
#include <iostream>
using std::cout, std::endl, std::cin;
int main(){
    int num = 5;
    for(int i = 1; i <= 10; ++i){
        cout << num << " x " << i << " = " << (num * i) << '\n'; 
    }

    return 0;
}
*/
/*
#include <iostream>

int main() {
    int n = 0;
    int sum = 0;
    // Take input from the user
    std::cout << "Enter a number: ";
    std::cin >> n;

    // Loop from 1 to n and add each number to sum
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }

    // Output the final result
    std::cout << sum << std::endl;

    return 0;
}
*/
/*
#include <iostream>

int main(){
    int num = 1;
    while(num <= 10){
        std::cout << num << std::endl;
        num++;
    }
    return 0;
}
*/
/*
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main() {

    const string User = "Prince";
    const int Password = 123;

    string inputUser;
    int inputPassword;

    bool LoggedIn = false;

    while (!LoggedIn) {

        cout << "Enter your username: ";
        getline(cin, inputUser);

        cout << "Enter your password: ";
        cin >> inputPassword;

        // Clear leftover newline character
        cin.ignore();

        if (inputUser == User && inputPassword == Password) {
            cout << "\nAccess Granted! Welcome back, " << User << "." << endl;
            LoggedIn = true;
        } else {
            cout << "\nInvalid username or password. Please try again.\n" << endl;
        }
    }

    return 0;
}
*/
/*
#include <iostream>
using namespace std;

int main() {
    int num = 1234;
    int reversedNum = 0;
    int remainder;

    // Loop continues until all digits are extracted
    while (num != 0) {
        remainder = num % 10;                  // Extract the last digit
        reversedNum = reversedNum * 10 + remainder; // Shift existing digits and add new one
        num /= 10;                             // Remove the last digit from the original number
    }

    cout << "Output: " << reversedNum << endl;

    return 0;
}
*/
// ============================= DO-WHILE LOOP ===============================
/*
#include <iostream>

int main(){
    int choice;
    
    do{
        std::cout << "1. BuyFood? " << '\n';
        std::cout << "2. Exit? " << '\n';
        std::cin >> choice;
        switch(choice){
            case 1: {
                std::cout << "Pizza: " << '\n';
                break;
            }
            case 2: {
                std::cout << "Thankyou for shopping!" << '\n';
                break;
            }
            default: {
                std::cout << "Invalid Choice!" << '\n';
                break;
            }
        }
    } while(choice != 2);

    return 0;
}
*/

/*
#include <iostream>
using std::cout, std::cin, std::endl;
int main(){
    int num;
    do{
        cout << "Enter a positive number: ";
        cin >> num;
        if(num > 0){
            cout << "The number is positive!" << '\n';
        } else {
            cout << "The number is negative!";
        } 
    } while(num < 0);   
    return 0;
}
*/

/*
#include <iostream>
#include <limits>
using std::cout, std::cin;
int main(){
    
    int CorrectGuess = 10;
    int guess;
    do{
        cout << "GUESS THE NUMBER!" << '\n';
        cout << "Enter your guess: ";
        cin >> guess;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if(guess > CorrectGuess){
            cout << "The number is too high!" << '\n';
        } else if (guess < CorrectGuess){
            cout << "The number is too low!" << '\n';
        } else {
            cout << "Correct! You guessed the number!" << '\n';
        } 
    } while (guess != CorrectGuess);
    return 0;
}
*/
// ============================================ BREAK ==============================
/*
#include <iostream>

int main(){

    for(int i = 1; i <= 100; i++){
        std::cout << i << '\n';
        if(i == 50){
            break;
        } 
    }
    return 0;
}
*/

#include <iostream>

int main(){
    
    int array[] = {10, 20, 30, 40};
    int target;
    bool found = false;

    std::cout << "Enter a number to search: " << '\n';
    std::cin >> target;

    for(int i = 0; i < 5; i++){
        if(array[i] == target){
            std::cout << "Found at the index " << i << '\n';
            found = true;
            break;
        }
    }
    if(!found){
        std::cout << "Number not found!";
    }
    return 0;
}















/*
//while statement

 #include <iostream>
   using namespace std;

int main() {
        int count = 1;

        while (count <= 5) {
        cout << "Iteration " << count;

        if (count % 2 == 0) {
            cout << " - Even";
        } else {
            cout << " - Odd";
        }

        cout << endl; 
        count++;       
    }

    return 0;
}
*/