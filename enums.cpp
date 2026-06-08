// ENUMS = An enumeration is a user-defined data type that allows you to create a set of named constants.
/*
    Syntax
    enum EnumName
    {
        VALUE1,
        VALUE2,
        VALUE3
    };
*/
/*
#include <iostream>
using namespace std;

enum Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY
};

int main()
{
    Day today = WEDNESDAY;

    cout << today << endl;

    return 0;
}
*/
/*
Output
2

Why 2?

Because enums start at 0 by default:

MONDAY     = 0
TUESDAY    = 1
WEDNESDAY  = 2
THURSDAY   = 3
FRIDAY     = 4
*/
/*
// Using enum in Conditions

#include <iostream>
using namespace std;

enum TrafficLight
{
    RED,
    YELLOW,
    GREEN
};

int main()
{
    TrafficLight light = GREEN;

    if(light == GREEN)
    {
        cout << "Go!" << endl;
    }

    return 0;
}

Output
Go!

*/

// ============== enum with switch ==============
/*
#include <iostream>
using namespace std;

enum Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY
};

int main()
{
    Day today = TUESDAY;

    switch(today)
    {
        case MONDAY:
            cout << "Monday";
            break;

        case TUESDAY:
            cout << "Tuesday";
            break;

        case WEDNESDAY:
            cout << "Wednesday";
            break;
    }

    return 0;
}
    Output
    Tuesday

*/

/*
2. enum class
    What is enum class?

    enum class is a strongly typed enumeration.

    Benefits:

    ✔ Prevents name conflicts
    ✔ Better type safety
    ✔ More modern C++ style


    Syntax
    enum class EnumName
    {
        VALUE1,
        VALUE2,
        VALUE3
    };



*/
/*
#include <iostream>
using namespace std;

enum class Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY
};

int main()
{
    Day today = Day::MONDAY;

    return 0;
}
*/
/*
Notice:

    Day::MONDAY

The enum name must be specified.
*/

/*
// ACCESSING VALUES 

#include <iostream>
using namespace std;

enum class TrafficLight
{
    RED,
    YELLOW,
    GREEN
};

int main()
{
    TrafficLight light = TrafficLight::GREEN;

    if(light == TrafficLight::GREEN)
    {
        cout << "Go!" << endl;
    }

    return 0;
}
*/