// 
// Purpose

// This program demonstrates encapsulation by making the account balance a private member. Users can only access or modify the balance through public methods, protecting the data from unauthorized changes.
/*
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string accountOwner, double initialBalance) {
        owner = accountOwner;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    void displayBalance() {
        cout << "Owner: " << owner << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    BankAccount account("John", 1000);

    account.deposit(500);
    account.withdraw(300);
    account.displayBalance();

    return 0;
}
*/
/*
Sample Output
Deposited: $500
Withdrew: $300
Owner: John
Current Balance: $1200
*/


/*
#include <iostream>
#include <string>
using namespace std;

class MyClass {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myString;  // Attribute (string variable)
};

int main() {
  MyClass myObj;  // Create an object of MyClass

  // Access attributes and set values
  myObj.myNum = 15;
  myObj.myString = "Some text";

  // Print values
  cout << myObj.myNum << "\n"; 
  cout << myObj.myString; 
  return 0;
}
*/
/*
#include <iostream>
using namespace std;

class Cars {
    public:
    string brand;
    string model;
    int year1;
    int year2;
    int year3;
};

int main(){

    Cars carObj1;
    carObj1.brand = "BMW";
    carObj1.model = "X5";

    Cars carObj2;
    carObj2.brand = "Ford";
    carObj2.model = "Mustang";


    Cars carDate;
    carDate.year1 = 2024;
    carDate.year2 = 2025;
    carDate.year3 = 2026;

    cout << carObj1.brand << " " << carObj1.model << " " << carDate.year1 << "\n";
    cout << carObj2.brand << " " << carObj2.model << " " << carDate.year3 << "\n";
    cout << carObj1.brand << " " << carObj1.model << " " << carDate.year2 << "\n";
    return 0;
}
*/
/*
// CLASS METHODS
#include <iostream>
using namespace std;

class MyClass {         // The class
  public:               // Access specifier
    void myMethod();    // Method/function declaration
};

// Method/function definition outside the class
void MyClass::myMethod() {
  cout << "Hello World!";
}

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}
*/
/*
#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    // Constructor
    User(string user, string pass) {
        username = user;
        password = pass;
    }

    // Login function
    bool login(string user, string pass) {
        return (user == username && pass == password);
    }

    // Change password
    void changePassword(string newPassword) {
        password = newPassword;
    }

    // Display username
    void displayUser() {
        cout << "Welcome, " << username << "!" << endl;
    }
};

int main() {
    // Create a user
    User user1("admin", "12345");

    string inputUser, inputPass;

    cout << "===== LOGIN SYSTEM =====" << endl;
    cout << "Username: ";
    cin >> inputUser;

    cout << "Password: ";
    cin >> inputPass;

    if (user1.login(inputUser, inputPass)) {
        cout << "\nLogin Successful!" << endl;
        user1.displayUser();
    } else {
        cout << "\nInvalid Username or Password!" << endl;
    }

    return 0;
}
*/

/*
#include <iostream>
using namespace std;

class Employee {
  private:
    int salary;

  public:
    void setSalary(int s) {
      salary = s;
    }
    int getSalary() {
      return salary;
    }
};

int main() {
  Employee myObj;
  myObj.setSalary(50000);
  cout << myObj.getSalary();
  return 0;
}
*/
/*
#include <iostream>
using namespace std;

class Employee {
  private:
    int salary;

  public:
    Employee(int s) {
      salary = s;
    }

    // Declare friend function
    friend void displaySalary(Employee emp);
};

void displaySalary(Employee emp) {
  cout << "Salary: " << emp.salary;
}

int main() {
  Employee myEmp(50000);
  displaySalary(myEmp);
  return 0;
}
*/