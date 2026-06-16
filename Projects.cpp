/*
// =================================== STUDENT GRADE SYSTEM ====================================
#include <iostream>
#include <iomanip>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string name;
    double subject1{};
    double subject2{};
    double subject3{};

    cout << "Enter your name: ";
    std::getline(cin, name);

    cout << "Enter score for Subject 1: ";
    cin >> subject1;

    cout << "Enter score for Subject 2: ";
    cin >> subject2;

    cout << "Enter score for Subject 3: ";
    cin >> subject3;

    // Input validation
    if (subject1 < 0 || subject1 > 100 ||
        subject2 < 0 || subject2 > 100 ||
        subject3 < 0 || subject3 > 100)
    {
        cout << "\nError: Scores must be between 0 and 100.\n";
        return 1;
    }

    double average = (subject1 + subject2 + subject3) / 3.0;

    char grade;

    if (average >= 90)
        grade = 'A';
    else if (average >= 80)
        grade = 'B';
    else if (average >= 70)
        grade = 'C';
    else if (average >= 60)
        grade = 'D';
    else
        grade = 'F';

    bool passed = average >= 60;

    cout << "\n=====================================\n";
    cout << "          STUDENT REPORT\n";
    cout << "=====================================\n";

    cout << "Name    : " << name << '\n';

    cout << std::fixed << std::setprecision(2);
    cout << "Average : " << average << '\n';

    cout << "Grade   : " << grade << '\n';

    cout << "Status  : "
         << (passed ? "Passed" : "Failed")
         << '\n';

    cout << "=====================================\n";

    return 0;
}
*/


