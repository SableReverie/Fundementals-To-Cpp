/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cctype>

using namespace std;

int main() {
    const int MAX_WRONG = 8;

    vector<string> words = {
        "computer",
        "programming",
        "hangman"
    };

  
    random_device rd;
    mt19937 gen(rd());
    shuffle(words.begin(), words.end(), gen);

    const string THE_WORD = words[0];
    string soFar(THE_WORD.size(), '-');
    string usedLetters = "";

    int wrong = 0;

    cout << "Welcome to Hangman. Good luck!\n";

    while (wrong < MAX_WRONG && soFar != THE_WORD) {

        cout << "\nIncorrect guesses left: " << (MAX_WRONG - wrong) << endl;
        cout << "Used letters: " << usedLetters << endl;
        cout << "Word: " << soFar << endl;

        string input;
        cout << "\nEnter a letter: ";
        cin >> input;

        // Input validation
        if (input.length() != 1 || !isalpha(input[0])) {
            cout << "Invalid input. Please enter ONE letter only.\n";
            continue;
        }

        char guess = tolower(input[0]);

        // Check if already used
        if (usedLetters.find(guess) != string::npos) {
            cout << "You already guessed '" << guess << "'. Try another letter.\n";
            continue;
        }

        usedLetters += guess;

        // Check if letter exists in word
        if (THE_WORD.find(guess) != string::npos) {
            cout << "Correct! '" << guess << "' is in the word.\n";

            for (size_t i = 0; i < THE_WORD.size(); i++) {
                if (THE_WORD[i] == guess) {
                    soFar[i] = guess;
                }
            }
        } else {
            cout << "Sorry, '" << guess << "' is not in the word.\n";
            wrong++;
        }
    }

    // Game result
    if (soFar == THE_WORD) {
        cout << "\nCongratulations! You guessed the word!\n";
    } else {
        cout << "\nGame Over! You've been hanged.\n";
    }

    cout << "The word was: " << THE_WORD << endl;

    return 0;
}
*/

/*
Vectors in C++ are one of the most useful containers in the Standard Library. Think of a vector as a dynamic array.

A normal array has a fixed size:

    int numbers[5];

You get exactly 5 elements and cannot easily grow it.

A vector can grow and shrink automatically:

    #include <vector>

    std::vector<int> numbers;

You can keep adding elements without knowing the size in advance.
*/
// ================ creating a vector ===========================
/*
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    return 0;
}
*/

// =================== Adding elements (push_back) ===========================
/*
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    for (int num : numbers) {
        std::cout << num << " ";
    }
}
*/
// ==================== accessing elements
/*
3. Accessing Elements

Just like arrays.

std::vector<int> numbers = {10, 20, 30};

std::cout << numbers[0];

Output:

10

Indexes:

Value: 10 20 30
Index: 0  1  2
*/

// ===================== changing values ======================
/*
std::vector<int> numbers = {10, 20, 30};

numbers[1] = 99;

for (int n : numbers)
    std::cout << n << " ";
*/
// ===================== finding size ========================
/*
std::vector<int> numbers = {10, 20, 30};

std::cout << numbers.size();
*/

// ======================= removing last element (pop_back) =========================
/*
std::vector<int> numbers = {10, 20, 30};

std::cout << numbers.size();

Now:

[10, 20]

Output:

for(int n : numbers)
    std::cout << n << " ";
10 20
*/
// ================ First and Last Element ===================
/*
std::vector<int> numbers = {10, 20, 30};

std::cout << numbers.front() << "\n";
std::cout << numbers.back();

Output:

10
30
*/


// ==================================================================================================

/*
9. Initializing a Vector
Method 1
std::vector<int> nums = {1, 2, 3, 4};
Method 2
std::vector<int> nums(5);

Creates:

[0,0,0,0,0]
Method 3
std::vector<int> nums(5, 100);

Creates:

[100,100,100,100,100]
10. Looping Through a Vector
Traditional Loop
for (int i = 0; i < numbers.size(); i++) {
    std::cout << numbers[i] << " ";
}
Range-Based Loop
for (int n : numbers) {
    std::cout << n << " ";
}
Using References
for (int &n : numbers) {
    n *= 2;
}

Example:

Before: [1,2,3]
After : [2,4,6]
11. Vector of Strings
#include <vector>
#include <string>

std::vector<std::string> names;

names.push_back("John");
names.push_back("Mary");
names.push_back("Alex");

Output:

John
Mary
Alex
12. Vector of Characters
std::vector<char> letters = {'a', 'b', 'c'};
13. Vector of Doubles
std::vector<double> grades = {95.5, 87.2, 99.1};
14. Sorting a Vector

Need:

#include <algorithm>

Example:

std::vector<int> nums = {5, 2, 8, 1, 4};

sort(nums.begin(), nums.end());

Result:

[1,2,4,5,8]

Full program:

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> nums = {5, 2, 8, 1, 4};

    sort(nums.begin(), nums.end());

    for (int n : nums)
        std::cout << n << " ";
}

Output:

1 2 4 5 8
15. Reverse Sorting
sort(nums.rbegin(), nums.rend());

Result:

[8,5,4,2,1]
16. Searching
#include <algorithm>

std::vector<int> nums = {10,20,30,40};

auto it = find(nums.begin(), nums.end(), 30);

if(it != nums.end())
    std::cout << "Found";

Output:

Found
17. Insert Element
std::vector<int> nums = {10,20,30};

nums.insert(nums.begin() + 1, 99);

Result:

[10,99,20,30]
18. Erase Element
std::vector<int> nums = {10,20,30,40};

nums.erase(nums.begin() + 2);

Result:

[10,20,40]
19. Clear Entire Vector
nums.clear();

Now:

[]

Size becomes:

std::cout << nums.size();
0
20. 2D Vectors (Matrix)

Think of a vector containing vectors.

std::vector<std::vector<int>> matrix = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};

Visual:

1 2 3
4 5 6
7 8 9

Access:

std::cout << matrix[1][2];

Output:

6
Example 1: Sum All Numbers
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {5,10,15,20};

    int sum = 0;

    for(int n : nums)
        sum += n;

    std::cout << "Sum = " << sum;
}

Output:

Sum = 50
Example 2: Find Largest Number
#include <iostream>
#include <vector>

int main() {
    std::vector<int> nums = {3,8,1,10,5};

    int largest = nums[0];

    for(int n : nums)
    {
        if(n > largest)
            largest = n;
    }

    std::cout << largest;
}

Output:

10
Example 3: Student Grades
#include <iostream>
#include <vector>

int main() {

    std::vector<int> grades;

    grades.push_back(90);
    grades.push_back(85);
    grades.push_back(100);

    double average = 0;

    for(int g : grades)
        average += g;

    average /= grades.size();

    std::cout << average;
}

Output:

91.6667
Example 4: Remove Even Numbers
#include <iostream>
#include <vector>

int main() {

    std::vector<int> nums = {1,2,3,4,5,6};

    for(int i = 0; i < nums.size(); )
    {
        if(nums[i] % 2 == 0)
            nums.erase(nums.begin() + i);
        else
            i++;
    }

    for(int n : nums)
        std::cout << n << " ";
}

Output:

1 3 5
Example 5: Store Names
#include <iostream>
#include <vector>
#include <string>

int main() {

    std::vector<std::string> names;

    names.push_back("Alice");
    names.push_back("Bob");
    names.push_back("Charlie");

    for(const std::string& name : names)
        std::cout << name << "\n";
}

Output:

Alice
Bob
Charlie
Mental Model

Think of a vector as a train:

[10][20][30][40]

Each box is an element.

push_back() → attach a new box at the end
pop_back() → remove the last box
size() → count boxes
[] → open a specific box
clear() → remove all boxes
Common Interview/Programming Contest Patterns
Input N numbers
int n;
std::cin >> n;

std::vector<int> nums;

for(int i = 0; i < n; i++)
{
    int x;
    std::cin >> x;
    nums.push_back(x);
}
Read then print
for(int n : nums)
    std::cout << n << " ";
Sort
sort(nums.begin(), nums.end());
Reverse
reverse(nums.begin(), nums.end());
Maximum
int mx = *max_element(nums.begin(), nums.end());
Minimum
int mn = *min_element(nums.begin(), nums.end());
Sum
int sum = accumulate(nums.begin(), nums.end(), 0);

(Requires #include <numeric>.)
*/