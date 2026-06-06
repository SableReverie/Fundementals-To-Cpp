// ======================================= GUESSING NUMBER =======================================
/*
#include <iostream> // INPUT AND OUTPUT 
#include <limits> // TO HAVE SAFETY INPUT WITH cin.clear and cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#include <cstdlib> // for RAND 
#include <ctime> // returns time but use chrono in modern c++

using std::cout;
using std::cin;

int getMaxNumber(int difficulty) {
    if (difficulty == 1) {
        return 10;
    }
    else if (difficulty == 2) {
        return 50;
    }
    else {
        return 100;
    }
}

void playGame(int maxNumber) {
    int randomNumber = rand() % maxNumber + 1;
    int guess;
    int attempts = 0;

    cout << "\nI'm thinking of a number between 1 and " << maxNumber << ".\n";

    do {
        cout << "Enter your guess: ";

        while (!(cin >> guess)) {
            cout << "Invalid input! Enter a number: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        attempts++;

        if (guess > randomNumber) {
            cout << "Too High!\n";
        }
        else if (guess < randomNumber) {
            cout << "Too Low!\n";
        }
        else {
            cout << "\nCorrect! 🎉\n";
            cout << "You guessed the number in "
                 << attempts << " attempts.\n";
        }

    } while (guess != randomNumber);
}

int main() {
    srand(time(0)); // RANDOM SEED 

    int difficulty;

    cout << "===== NUMBER GUESSING GAME =====\n";
    cout << "Choose Difficulty:\n";
    cout << "1. Easy (1-10)\n";
    cout << "2. Medium (1-50)\n";
    cout << "3. Hard (1-100)\n";
    cout << "Enter choice: ";

    while (!(cin >> difficulty) ||
           difficulty < 1 || difficulty > 3) {

        cout << "Invalid input! Enter 1, 2, or 3: ";

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int maxNumber = getMaxNumber(difficulty);

    playGame(maxNumber);

    cout << "\nThanks for playing!\n";

    return 0;
}
*/
// 
/*
// =========================== ROCK PAPER SCISSORS GAME ==========================
An enumeration (enum) 
in C++ is a user-defined data type that consists of a set of named integer constants.
*/
/*
#include <iostream>   // For input and output operations
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time() function used as random seed

using std::cout, std::endl, std::cin, std::string; // Import commonly used std names

// Enumeration for the three possible choices
enum Choice {
    ROCK = 1,         // Rock is represented by 1
    PAPER = 2,        // Paper is represented by 2
    SCISSORS = 3      // Scissors is represented by 3
};

// Generates and returns a random computer choice
Choice getComputerChoice() {
    return static_cast<Choice>((rand() % 3) + 1); // Random number between 1 and 3
}

// Gets and validates the user's choice
Choice getUserChoice() {
    int input; // Variable to store user input

    cout << "\nChoose(1 = Rock, 2 = Paper, 3 = Scissors): "; // Prompt user
    cin >> input; // Read user input

    // Keep asking until a valid choice is entered
    while (input < 1 || input > 3) {
        cout << "Invalid Choice!"; // Error message
        cin >> input; // Read input again
    }

    return static_cast<Choice>(input); // Convert integer to Choice enum
}

// Converts a Choice value to a readable string
string choiceToString(Choice c) {
    switch (c) {
        case ROCK: return "Rock";         // If choice is ROCK
        case PAPER: return "Paper";       // If choice is PAPER
        case SCISSORS: return "Scissors"; // If choice is SCISSORS
        default: return "Unknown";        // Fallback case
    }
}

// Determines the winner of a round
int getRoundResult(Choice user, Choice computer) {

    // If both choices are the same, it's a draw
    if (user == computer)
        return 0;

    // Check all winning conditions for the user
    if ((user == ROCK && computer == SCISSORS) ||
        (user == PAPER && computer == ROCK) ||
        (user == SCISSORS && computer == PAPER)) {

        return 1; // User wins
    }

    return -1; // Computer wins
}

// Plays one round and updates scores
void playRound(int &userScore, int &computerScore) {

    Choice user = getUserChoice(); // Get user's choice
    Choice computer = getComputerChoice(); // Generate computer's choice

    // Display selected choices
    cout << "You chose: " << choiceToString(user) << endl;
    cout << "Computer chose: " << choiceToString(computer) << endl;

    // Determine round result
    int result = getRoundResult(user, computer);

    if (result == 1) { // User wins
        cout << "You win this round!\n";
        userScore++; // Increase user score
    }
    else if (result == -1) { // Computer wins
        cout << "Computer wins this round!\n";
        computerScore++; // Increase computer score
    }
    else { // Draw
        cout << "It's a draw!\n";
    }

    // Display current score
    cout << "Score -> You: "
         << userScore
         << " | Computer: "
         << computerScore
         << endl;
}

// Checks whether either player has reached the target score
bool isGameOver(int userScore, int computerScore, int target) {
    return userScore == target || computerScore == target;
}

// Controls the overall game flow
void playGame(int bestOf) {

    // Calculate wins needed to become champion
    int target = (bestOf / 2) + 1;

    // Initialize scores
    int userScore = 0, computerScore = 0;

    // Display game mode
    cout << "\n=== Rock Paper Scissors (Best of "
         << bestOf
         << ") ===\n";

    // Continue playing until someone reaches target score
    while (!isGameOver(userScore, computerScore, target)) {
        playRound(userScore, computerScore);
    }

    cout << "\n=== Game Over ===\n";

    // Announce overall winner
    if (userScore > computerScore)
        cout << "🎉 You win the game!\n";
    else
        cout << "💻 Computer wins the game!\n";
}

// Program entry point
int main() {

    srand(time(0)); // Seed random number generator using current time

    char playAgain; // Stores user's decision to replay

    do {

        int mode; // Stores selected game mode

        // Display menu
        cout << "\nChoose game mode:\n";
        cout << "1. Best of 3\n";
        cout << "2. Best of 5\n";
        cout << "Enter choice: ";

        cin >> mode; // Read mode selection

        // Start selected game mode
        if (mode == 1)
            playGame(3); // Best of 3
        else if (mode == 2)
            playGame(5); // Best of 5
        else
            cout << "Invalid mode!\n"; // Invalid input

        // Ask if user wants another game
        cout << "\nPlay again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y'); // Repeat if yes

    cout << "\nThanks for playing!\n"; // Goodbye message

    return 0; // Successful program termination
}
*/

// ============================== TIC TAC TOE =============================================
/*
#include <iostream>
using std::endl, std::cin, std::cout;

char board[3][3];
char currentPlayer;

// Initialize board
void initializeBoard() {
    char position = '1';

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = position++;
        }
    }

    currentPlayer = 'X';
}

// Display board
void displayBoard() {
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << " " << board[i][0] << " | "
             << board[i][1] << " | "
             << board[i][2] << "\n";

        if (i < 2)
            cout << "-----------\n";
    }

    cout << "\n";
}

// Make move
bool makeMove(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9)
        return false;

    if (board[row][col] == 'X' || board[row][col] == 'O')
        return false;

    board[row][col] = currentPlayer;
    return true;
}

// Check winner
bool checkWinner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    // Diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

// Check draw
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// Switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

int main() {
    char playAgain;

    do {
        initializeBoard();

        bool gameOver = false;

        while (!gameOver) {
            displayBoard();

            int choice;
            cout << "Player " << currentPlayer
                 << ", enter position (1-9): ";
            cin >> choice;

            if (!makeMove(choice)) {
                cout << "Invalid move! Try again.\n";
                continue;
            }

            if (checkWinner()) {
                displayBoard();
                cout << "🎉 Player " << currentPlayer
                     << " wins!\n";
                gameOver = true;
            }
            else if (checkDraw()) {
                displayBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            }
            else {
                switchPlayer();
            }
        }

        cout << "\nPlay again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "Thanks for playing!\n";

    return 0;
}
*/