/*
#include <iostream>

int main(){

    // Type Conversion = conversion a value of one data type to another data type
    // implicit conversion (automatic type conversion) = conversion of a smaller data type to a larger data type
    // explicit conversion (manual type conversion) = conversion of a larger data type to a smaller

    #include <iostream>

    // ==========================================
    // 1. IMPLICIT CONVERSION (Automatic)
    // ==========================================
    int num_int = 25;
    
    // The compiler automatically converts the integer 25 into a double (25.0)
    // because a double variable is expecting a floating-point value.
    double num_double = num_int; 
    
    std::cout << "Implicit Conversion (int to double): " << num_double << "\n";


    // ==========================================
    // 2. EXPLICIT CONVERSION (Manual Type Casting)
    // ==========================================
    double pi = 3.14159;
    
    // We use 'static_cast<int>' to manually force the compiler to convert 
    // the double to an integer. This intentionally truncates the decimals (.14159).
    int truncated_pi = static_cast<int>(pi); 
    
    std::cout << "Explicit Conversion (double to int): " << truncated_pi << "\n";
    
    return 0;
}
*/

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class User {
private:
    string name;
    int id;

public:
    // Constructor
    User(string userName, int userId) {
        name = userName;
        id = userId;
    }

    // Getters
    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    // Display user information
    void displayUser() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

// Find a user by ID
int findUser(const vector<User>& users, int id) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == id) {
            return i;
        }
    }

    return -1;
}

// Get a valid integer from the user
int getValidId() {
    int id;

    while (true) {
        cout << "Enter your ID: ";

        if (cin >> id && id > 0) {
            return id;
        }

        cout << "Invalid ID. Please enter a positive number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Get a non-empty name
string getValidName() {
    string name;

    while (true) {
        cout << "Enter your name: ";
        cin >> ws;
        getline(cin, name);

        if (!name.empty()) {
            return name;
        }

        cout << "Name cannot be empty. Please try again.\n";
    }
}

int main() {
    // Sample users
    vector<User> users = {
        User("John Doe", 1001),
        User("Jane Smith", 1002),
        User("Alex Johnson", 1003)
    };

    int choice;

    while (true) {
        cout << "\n====================================\n";
        cout << "       USER LOGIN SYSTEM\n";
        cout << "====================================\n";
        cout << "1. Login\n";
        cout << "2. View Users\n";
        cout << "3. Register New User\n";
        cout << "4. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";

        cin >> choice;

        // Check if menu input is valid
        if (cin.fail()) {
            cout << "Invalid choice. Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch (choice) {

        case 1: {
            cout << "\n---------- LOGIN ----------\n";

            int id = getValidId();

            int userIndex = findUser(users, id);

            if (userIndex != -1) {
                cout << "\nLogin successful!\n";
                cout << "Welcome, " << users[userIndex].getName() << "!\n";

                cout << "\nYour account information:\n";
                users[userIndex].displayUser();
            }
            else {
                cout << "\nLogin failed.\n";
                cout << "No user was found with ID " << id << ".\n";
            }

            break;
        }

        case 2: {
            cout << "\n---------- USER LIST ----------\n";

            if (users.empty()) {
                cout << "No users registered.\n";
            }
            else {
                for (const User& user : users) {
                    user.displayUser();
                    cout << "----------------------\n";
                }
            }

            break;
        }

        case 3: {
            cout << "\n---------- REGISTER ----------\n";

            string name = getValidName();
            int id = getValidId();

            if (findUser(users, id) != -1) {
                cout << "\nRegistration failed.\n";
                cout << "That ID is already registered.\n";
            }
            else {
                users.push_back(User(name, id));

                cout << "\nRegistration successful!\n";
                cout << "Welcome, " << name << "!\n";
            }

            break;
        }

        case 4:
            cout << "\nThank you for using the User Login System!\n";
            cout << "Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice. Please choose 1-4.\n";
        }
    }

    return 0;
}
