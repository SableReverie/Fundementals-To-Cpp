#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> people;

    // Add elements to the queue
    people.push("Alice");
    people.push("Bob");
    people.push("Charlie");

    cout << "Queue: " << endl;

    // Display and remove elements
    while (!people.empty()) {
        cout << people.front() << endl;
        people.pop();
    }

    return 0;
}