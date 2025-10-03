// COMSC-210 | Lab 17 | Mamadou Sissoko
// IDE used: Visual Studio Code
// Modularized linked list with functions for add, insert, delete, and destroy

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int value;     // holds data for each node
    Node* next;    // pointer to next node
};

// function prototypes
void addToFront(Node*& head, int val);          // add new node at front
void addToTail(Node*& head, int val);           // add new node at tail
void insertNode(Node*& head, int pos, int val); // insert node at position
void deleteNode(Node*& head, int pos);          // delete node at position
void output(Node* head);                         // display linked list
void deleteList(Node*& head);                    // delete entire linked list

int main() {
    srand(time(0));
    Node* head = nullptr; // pointer to first node

    // create a linked list of size 7 with random numbers 0-99
    for (int i = 0; i < 3; i++) addToFront(head, rand() % 100); // first part front
    for (int i = 0; i < 4; i++) addToTail(head, rand() % 100);  // second part tail

    cout << "Initial list" << endl;
    output(head); // display current list

    // insert a node
    int entry;
    cout << "After which node to insert 10000? " << endl; // prompt user
    output(head); // show current list
    cout << "Choice --> ";
    cin >> entry;
    insertNode(head, entry, 10000); // insert new node after chosen position

    cout << "List after insertion" << endl;
    output(head); // display updated list

    // delete a node
    cout << "Which node to delete? " << endl; // prompt user
    output(head); // show current list
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry); // delete chosen node

    cout << "List after deletion" << endl;
    output(head); // display final list

    // delete the entire linked list
    deleteList(head); // free all nodes

    cout << "Empty list." << endl; // indicate list is now empty

    return 0;
}

// add a node at front
void addToFront(Node*& head, int val) {
    Node* newNode = new Node{val, head}; // create new node pointing to head
    head = newNode;                       // update head
}

// add a node at tail
void addToTail(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr}; // new node points to nullptr
    if (!head) {                             // if list empty
        head = newNode;                      // new node becomes head
        return;
    }
    Node* temp = head; // traverse to last node
    while (temp->next) temp = temp->next; // move to last node
    temp->next = newNode; // link last node to new node
}

// insert a node after a given position
void insertNode(Node*& head, int pos, int val) {
    Node* newNode = new Node{val, nullptr}; // create new node
    if (pos == 0) {                          // if position is 0, insert at head
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head; // traverse to given position
    for (int i = 1; i < pos && temp; i++) temp = temp->next;
    if (temp) { // insert node
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        delete newNode; // position invalid, delete node
    }
}

// delete a node at given position
void deleteNode(Node*& head, int pos) {
    if (!head) return; // nothing to delete
    if (pos == 1) {   // delete first node
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* prev = head;
    for (int i = 1; i < pos - 1 && prev->next; i++) prev = prev->next; // traverse to previous node
    if (prev->next) { // if node exists
        Node* temp = prev->next;
        prev->next = temp->next; // bypass node
        delete temp;             // free memory
    }
}

// display linked list
void output(Node* head) {
    if (!head) return; // nothing to display
    int count = 1;
    while (head) {
        cout << "[" << count++ << "] " << head->value << endl; // show value with position
        head = head->next;
    }
}

// delete entire list
void deleteList(Node*& head) {
    Node* temp;
    while (head) {
        temp = head;       // store current node
        head = head->next; // move head forward
        delete temp;       // free memory
    }
}
