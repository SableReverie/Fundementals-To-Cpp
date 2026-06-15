// STRUCTS = A structure (struct) is a user-defined data type that allows you to group different types of data under one name.

/*
    Think of a struct as a way to describe an object with multiple properties.

    For example, a student has:

    Name
    Age
    Grade

    Instead of creating separate variables for each student, we can group them into one structure.
*/

/*
Syntax
struct StructureName
{
    dataType member1;
    dataType member2;
};
*/
/*
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
};

int main()
{
    Student s1, s2;

    s1.name = "John";
    s1.age = 20;

    s2.name = "Mary";
    s2.age = 21;

    cout << s1.name << endl;
    cout << s2.name << endl;

    return 0;
}
*/

// ========================== Nested Struct =====================================
//A nested struct is a structure inside another structure. This is useful when one object contains another object.
/*
#include <iostream>
using namespace std;

struct Address
{
    string city;
    string country;
};

struct Student
{
    string name;
    int age;
    Address address;
};

int main()
{
    Student s1;

    s1.name = "John";
    s1.age = 20;

    s1.address.city = "Manila";
    s1.address.country = "Philippines";

    cout << "Name: " << s1.name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "City: " << s1.address.city << endl;
    cout << "Country: " << s1.address.country << endl;

    return 0;
}
*/

/*
Student
│
├── name = John
├── age = 20
│
└── Address
    ├── city = Manila
    └── country = Philippines
*/

// =================================== Array of Structs ====================================

/*
    An array of structs allows you to store multiple records of the same type.

    Instead of:

    Student s1;
    Student s2;
    Student s3;

    Use:

    Student students[3];
*/

// Example of 3 students 
/*
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
};

int main()
{
    Student students[3];

    students[0].name = "John";
    students[0].age = 20;

    students[1].name = "Mary";
    students[1].age = 21;

    students[2].name = "Peter";
    students[2].age = 19;

    for(int i = 0; i < 3; i++)
    {
        cout << "Student " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << endl;
    }

    return 0;
}
*/

// USER INPUT EXAMPLE
/*
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
};

int main()
{
    Student students[2];

    for(int i = 0; i < 2; i++)
    {
        cout << "Enter name: ";
        cin >> students[i].name;

        cout << "Enter age: ";
        cin >> students[i].age;
    }

    cout << "\nStudent Records\n";

    for(int i = 0; i < 2; i++)
    {
        cout << students[i].name
             << " - "
             << students[i].age
             << endl;
    }

    return 0;
}
*/
// Combination of nested struct + array of struct 
/*
#include <iostream>
using namespace std;

struct Address
{
    string city;
    string country;
};

struct Student
{
    string name;
    int age;
    Address address;
};

int main()
{
    Student students[2];

    students[0].name = "John";
    students[0].age = 20;
    students[0].address.city = "Manila";
    students[0].address.country = "Philippines";

    students[1].name = "Mary";
    students[1].age = 21;
    students[1].address.city = "Davao";
    students[1].address.country = "Philippines";

    for(int i = 0; i < 2; i++)
    {
        cout << "\nStudent " << i + 1 << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "City: " << students[i].address.city << endl;
        cout << "Country: "
             << students[i].address.country
             << endl;
    }

    return 0;
}
*/

