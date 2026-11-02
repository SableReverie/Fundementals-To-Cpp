/*
#include <iostream>
using std::endl, 
std::string;

int main(){
    int n = 10;
    for(int i = 1; i <= n; i++){
        std::cout << "  * " << " ";
    }
    return 0;
}
*/
/*
#include <iostream>
#include <string> // Added to ensure standard string compatibility

using std::endl;
using std::string;
using std::cout;
using std::cin;

class Print {
private:
    string name;
public:
    void callName(string name) {
        this->name = name;
    }
    
    // Added a method to actually display the stored name
    void displayName() {
        cout << "Hello, " << name << "!" << endl;
    }
};

int main() {
    Print printer;                // Create an object of the Print class
    printer.callName("Alice");    // Pass a name string to the object
    printer.displayName();        // Output the result to the console
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Pos {
    int x{}, y{};

    bool operator==(const Pos& other) const {
        return x == other.x && y == other.y;
    }
};

class Game {
    static constexpr int W = 15;
    static constexpr int H = 9;

    vector<string> map{
        "###############",
        "#@     #      #",
        "# ###  # ###  #",
        "#   #     #   #",
        "### ##### ### #",
        "#     #       #",
        "# ### # ##### #",
        "#   E       K #",
        "###############"
    };

    Pos player{};
    Pos key{};
    vector<Pos> clones;

    vector<char> currentMoves;
    vector<vector<char>> recordings;

    int loop = 1;
    bool hasKey = false;
    bool running = true;

public:
    Game() {
        resetPlayer();

        for (int y = 0; y < H; ++y) {
            for (int x = 0; x < W; ++x) {
                if (map[y][x] == '@')
                    player = {x, y};

                if (map[y][x] == 'K')
                    key = {x, y};
            }
        }
    }

    void run() {
        while (running) {
            draw();

            cout << "\nLoop " << loop << " | "
                 << "Moves: " << currentMoves.size() << "\n";

            cout << "WASD = move | R = restart loop | Q = quit\n";
            cout << "> ";

            char input;
            cin >> input;

            input = static_cast<char>(
                tolower(static_cast<unsigned char>(input))
            );

            if (input == 'q') {
                running = false;
                continue;
            }

            if (input == 'r') {
                restartLoop();
                continue;
            }

            if (input == 'w' || input == 'a' ||
                input == 's' || input == 'd') {

                currentMoves.push_back(input);
                movePlayer(input);

                if (player == key) {
                    hasKey = true;
                }

                if (hasKey && map[player.y][player.x] == 'E') {
                    win();
                    return;
                }

                if (currentMoves.size() >= 30) {
                    restartLoop();
                }
            }
        }
    }

private:
    void draw() {
        system("cls");

        vector<string> screen = map;

        // Draw previous selves.
        for (const auto& clone : clones) {
            if (screen[clone.y][clone.x] == ' ')
                screen[clone.y][clone.x] = 'C';
        }

        screen[player.y][player.x] = '@';

        cout << "================================\n";
        cout << "          T I M E  L O O P      \n";
        cout << "================================\n\n";

        for (const auto& row : screen)
            cout << row << '\n';

        cout << "\n@ You   C Past self   K Key   E Exit\n";
    }

    void resetPlayer() {
        player = {1, 1};
        hasKey = false;
    }

    bool canMove(Pos p) const {
        if (p.x < 0 || p.x >= W ||
            p.y < 0 || p.y >= H)
            return false;

        return map[p.y][p.x] != '#';
    }

    void movePlayer(char direction) {
        Pos next = player;

        switch (direction) {
        case 'w': --next.y; break;
        case 's': ++next.y; break;
        case 'a': --next.x; break;
        case 'd': ++next.x; break;
        }

        if (canMove(next))
            player = next;
    }

    Pos simulate(const vector<char>& moves) {
        Pos p{1, 1};

        for (char move : moves) {
            Pos next = p;

            switch (move) {
            case 'w': --next.y; break;
            case 's': ++next.y; break;
            case 'a': --next.x; break;
            case 'd': ++next.x; break;
            }

            if (canMove(next))
                p = next;
        }

        return p;
    }

    void restartLoop() {
        // The current run becomes a past self.
        recordings.push_back(currentMoves);

        // Calculate where each past self ends.
        clones.clear();

        for (const auto& recording : recordings)
            clones.push_back(simulate(recording));

        currentMoves.clear();
        resetPlayer();
        ++loop;

        if (loop > 20) {
            cout << "\nYou ran out of loops!\n";
            running = false;
        }
    }

    void win() {
        system("cls");

        cout << "\n";
        cout << "================================\n";
        cout << "          YOU ESCAPED!\n";
        cout << "================================\n\n";

        cout << "You escaped the time loop in "
             << loop << " loops.\n";

        cout << "\nYour past selves helped you reach the exit.\n";
        cout << "Congratulations!\n\n";
    }
};

int main() {
    Game game;
    game.run();

    cout << "\nThanks for playing!\n";
    return 0;
}