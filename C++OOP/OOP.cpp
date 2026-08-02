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