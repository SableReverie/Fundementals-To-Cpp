// ============================ Big O: O(n) Worst Case, Average Case, Best Case ============================
/*
#include <iostream>

using namespace std;


void printItems(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }
}


int main() { 

    printItems(10);

}

// The "1" is best case, the "4" is average case, the "7" is the worst case.
*/

// ============================== Drop Constants =====================================
// This function is n + n = 2n but the constant 2 will be dropped, so this will be O(n).
/*
#include <iostream>

using namespace std;


void printItems(int n) {
    for (int i = 0; i < n; i++) {
        cout << i << endl;
    }

    for (int j = 0; j < n; j++) {
        cout << j << endl;
    }
}


int main() { 

    printItems(10);

}
*/

// ================================== Big O: O(n^2) ==================================
// n * n = n^2, but it's less efficient than O(n)
/*
#include <iostream>

using namespace std;


void printItems(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }
}


int main() { 

    printItems(10);

}
*/

// ============================== Big O: Drop Non-Dominants ==================================

// So this nested loop is O(n^2) and the other function for-loop is O(n) = O(n^2 + n), but the n will be dropped,
// so the Big O is still O(n^2).
/*
#include <iostream>

using namespace std;


void printItems(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << j << endl;
        }
    }

    for (int k = 0; k < n; k++) {
            cout << k << endl;
    }
}



int main() { 

    printItems(10);

}
*/



// SINGLE LINKED LIST
/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
    }

    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;

    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);

    list.display();

    return 0;
}
*/


#include <iostream>
using namespace std;
int main() {
    
    int n = 5;
    cout << &n << endl; // Prints the memory address of n
    int *ptr = &n; // Pointer to n
    cout << ptr << endl; // Prints the memory address stored in ptr (which is the
    cout << *ptr << endl; // Dereferencing ptr to get the value of n
    *ptr = 10; // Changing the value of n through the pointer
    cout << *ptr << endl; // Prints the new value of n (10)
    cout << n << endl; // Prints the new value of n (10)

    int v;
    int* ptr2 = &v; // Pointer to v
    *ptr2 = 20; // Assigning value to v through the pointer
    cout << v << endl; // Prints the value of v (20)
    
    return 0;
}