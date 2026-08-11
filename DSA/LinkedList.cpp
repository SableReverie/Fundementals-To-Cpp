#include <iostream>

// 1. Definition of a Node
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a node easily
    Node(int val) : data(val), next(nullptr) {}
};

// 2. LinkedList Class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // --- INSERTION OPERATIONS ---

    // Insert at the beginning: O(1)
    void insertAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at the end: O(n)
    void insertAtTail(int val) {
        Node* newNode = new Node(val);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific 0-based index: O(n)
    void insertAtPosition(int val, int index) {
        if (index == 0) {
            insertAtHead(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            std::cout << "Index out of bounds.\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // --- DELETION OPERATIONS ---

    // Delete node by value: O(n)
    void deleteByValue(int val) {
        if (head == nullptr) return;

        // If the head node itself holds the value
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp; // Free memory
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != val) {
            current = current->next;
        }

        // Value was not present in the list
        if (current->next == nullptr) {
            std::cout << "Value " << val << " not found in list.\n";
            return;
        }

        Node* temp = current->next;
        current->next = current->next->next;
        delete temp; // Free memory
    }

    // --- UTILITY & UTILITY OPERATIONS ---

    // Search for a value: O(n)
    bool search(int val) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    // Print all elements: O(n)
    void printList() const {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "nullptr\n";
    }

    // Get the length of the list: O(n)
    int getLength() const {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Destructor to prevent memory leaks: O(n)
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

// --- DEMONSTRATION ---
int main() {
    LinkedList list;

    // Building the list: 10 -> 20 -> 30
    list.insertAtTail(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    std::cout << "Initial list:\n";
    list.printList(); // 10 -> 20 -> 30 -> nullptr

    // Insert at head: 5 -> 10 -> 20 -> 30
    list.insertAtHead(5);
    std::cout << "\nAfter insertAtHead(5):\n";
    list.printList();

    // Insert at index 2: 5 -> 10 -> 15 -> 20 -> 30
    list.insertAtPosition(15, 2);
    std::cout << "\nAfter insertAtPosition(15, index 2):\n";
    list.printList();

    // Deleting value 20
    list.deleteByValue(20);
    std::cout << "\nAfter deleteByValue(20):\n";
    list.printList();

    // Search query
    std::cout << "\nIs 15 in the list? " << (list.search(15) ? "Yes" : "No") << "\n";
    std::cout << "Is 99 in the list? " << (list.search(99) ? "Yes" : "No") << "\n";

    // Length
    std::cout << "Total elements: " << list.getLength() << "\n";

    return 0;
}        