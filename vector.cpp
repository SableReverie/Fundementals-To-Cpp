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