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
// ============================= 2nd Practice Project ===============================
/*
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <random>

using std::cin;
using std::cout;
using std::string;

// ==========================================
// 1. DATA STRUCTURES & CONFIGURATION
// ==========================================

enum class MenuOption { 
    ENTER_ARENA = 1, 
    VISIT_MERCHANT = 2, 
    VIEW_INVENTORY = 3, 
    QUIT = 4 
};

enum class CombatOption {
    ATTACK = 1,
    HEAL = 2,
    FLEE = 3,
};

// Senior Dev Tip: Structs must be defined BEFORE they are used in other structs
struct Item {
    string Name;
    int Price;
    int HealingPower;
};

struct Player {
    int health = 100;
    int maxHealth = 100;
    int gold = 100;
    int attackPower = 15;
    std::vector<Item> inventory; // Capitalized 'Item' now matches the struct above
    int potionCount = 2;
};

struct Enemy {
    string Name;
    int Health;
    int AttackPower;
    int GoldReward;
};

// ==========================================
// 2. CORE HELPER FUNCTIONS (Input Validation)
// ==========================================
int generateRandomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

int getValidatedIntegerInput(int minValue, int maxValue) {
    int userInput;
    while (true) {
        cout << "Enter your choice (" << minValue << "-" << maxValue << "): ";
        cin >> userInput;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a valid numerical digit.\n\n";
            continue;
        }

        if (userInput >= minValue && userInput <= maxValue) {
            return userInput;
        } else {
            cout << "Selection out of bounds. Please try again.\n\n";
        }
    }
}

// ==========================================
// 3. GAME SUBSYSTEMS
// ==========================================

bool executeCombatRound(Player& player, Enemy& enemy) {
    cout << "\n--- COMBAT TURN ---\n";
    // Fixed: Member variables capitalized to match the Enemy struct definition
    cout << enemy.Name << " | HP: " << enemy.Health << "\n";
    cout << "Player HP: " << player.health << "/" << player.maxHealth << " | Potions: " << player.potionCount << "\n\n";
    cout << "1. Attack\n2. Heal\n3. Flee\n";

    int rawChoice = getValidatedIntegerInput(1, 3);
    CombatOption choice = static_cast<CombatOption>(rawChoice);

    switch (choice) {
        case CombatOption::ATTACK: {
            int damageDealt = player.attackPower;

            if (generateRandomNumber(1, 100) > 80) {
                damageDealt *= 2;
                cout << ">> CRITICAL HIT! <<\n";
            }

            enemy.Health -= damageDealt; // Fixed capitalization
            cout << "You slashed " << enemy.Name << " for " << damageDealt << " damage.\n";
            break;
        }
        case CombatOption::HEAL: {
            if (player.potionCount > 0) {
                player.health += 30;
                if (player.health > player.maxHealth) {
                    player.health = player.maxHealth;
                }
                player.potionCount--;
                cout << "You consumed a potion. Recovered to " << player.health << " HP.\n";
            } else {
                cout << "You reach for a potion but your bag is empty!\n";
                return true; 
            }
            break;
        }
        case CombatOption::FLEE: {
            cout << "You retreat from the arena back to the main hub safety.\n";
            return false; 
        }
    }

    // Enemy Counter-Attack Phase
    if (enemy.Health > 0) { // Fixed capitalization
        cout << enemy.Name << " lunges forward and hits you!\n"; // Fixed capitalization
        player.health -= enemy.AttackPower; // Fixed capitalization
        cout << "You sustained " << enemy.AttackPower << " damage.\n"; // Fixed capitalization
    }

    return true;
}

void handleArenaSystem(Player& player) {
    cout << "\n========================================\n";
    cout << "Entering the Arena: Iron-Clad Pit\n";
    cout << "========================================\n";
    
    // Capitalized arguments match our updated Enemy struct definition fields
    Enemy monster{"Orc Vanguard", 60, 14, 50};
    bool isCombatActive = true;

    while (isCombatActive && monster.Health > 0 && player.health > 0) {
        isCombatActive = executeCombatRound(player, monster);
    }

    if (player.health <= 0) {
        cout << "\nYou were crushed by the " << monster.Name << "...\n";
    } else if (monster.Health <= 0) {
        cout << "\nVictory! You successfully eradicated " << monster.Name << ".\n";
        player.gold += monster.GoldReward;
        cout << "Earned " << monster.GoldReward << " gold coins.\n";
    }
}

void handleMerchantSystem(Player& player) {
    Item ironSword{"Reforged Iron Sword", 45, 0};
    
    cout << "\n--- THE MERCHANT OUTPOST ---\n";
    cout << "Your Balance: " << player.gold << "g\n";
    cout << "1. Purchase " << ironSword.Name << " (" << ironSword.Price << "g)\n";
    cout << "2. Leave Shop\n";

    int choice = getValidatedIntegerInput(1, 2);

    if (choice == 1) {
        if (player.gold >= ironSword.Price) {
            player.gold -= ironSword.Price;
            player.attackPower += 10; 
            player.inventory.push_back(ironSword);
            cout << "Transaction successful! Your attack power grew to " << player.attackPower << ".\n";
        } else {
            cout << "Merchant sneers: 'Come back when you have actual currency.'\n";
        }
    } else {
        cout << "You step away from the counter.\n";
    }
}

void handleInventorySystem(const Player& player) {
    cout << "\n--- INVENTORY SHEETS ---\n";
    cout << "Current Gold Wallet: " << player.gold << "g\n";
    cout << "Stocked Consumables: " << player.potionCount << "x Rejuvenation Potions\n";
    cout << "Weaponry Manifest:\n";

    if (player.inventory.empty()) {
        cout << "  [No armaments registered in collection]\n";
    } else {
        for (const auto& item : player.inventory) {
            if (item.Name.empty()) {
                continue; 
            }
            cout << "  - " << item.Name << " (Appraised Value: " << item.Price << "g)\n";
        }
    }
}

// ==========================================
// 4. MAIN PROGRAM LIFESTYLE ENTRY
// ==========================================

int main() {
    Player localHero;
    bool isGameRunning = true;

    cout << "===============================================\n";
    cout << "     HERO'S GAUNTLET SIMULATION FRAMEWORK      \n";
    cout << "===============================================\n";

    do {
        cout << "\n========= MAIN HUB MENU =========\n";
        cout << "1. Enter Arena Pit\n";
        cout << "2. Visit Outpost Merchant\n";
        cout << "3. Inspect Character Equipment\n";
        cout << "4. Terminate Process (Quit)\n";
        cout << "=================================\n";

        int menuSelection = getValidatedIntegerInput(1, 4);
        MenuOption choice = static_cast<MenuOption>(menuSelection);

        switch (choice) {
            case MenuOption::ENTER_ARENA:
                handleArenaSystem(localHero);
                break;

            case MenuOption::VISIT_MERCHANT:
                handleMerchantSystem(localHero);
                break;

            case MenuOption::VIEW_INVENTORY:
                handleInventorySystem(localHero);
                break;

            case MenuOption::QUIT:
                cout << "Releasing active resource pools. Exiting execution stream...\n";
                isGameRunning = false;
                break;
        }

        if (localHero.health <= 0) {
            cout << "\n[CRITICAL FAILURE]: The Hero has expired. Database states reset.\n";
            isGameRunning = false;
        }

    } while (isGameRunning);

    cout << "\nProcess terminated gracefully. Code status: 0\n";
    return 0;
}
*/