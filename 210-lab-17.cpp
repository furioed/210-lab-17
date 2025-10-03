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
void addToFront(Node*& head, int val);   // add new node at front
void addToTail(Node*& head, int val);    // add new node at tail
void output(Node* head);                 // display linked list
void deleteNode(Node*& head, int pos);   // delete node at position
void deleteList(Node*& head);            // delete entire linked list

int main() {
    srand(time(0));
    Node* head = nullptr;  // pointer to first node

    // create a linked list of size 7 with random numbers 0-99
    for (int i = 0; i < 4; i++) addToFront(head, rand() % 100); // first half front
    for (int i = 0; i < 3; i++) addToTail(head, rand() % 100);  // second half tail

    cout << "Initial list" << endl;
    output(head); // display current list

    // deleting a node
    int entry;
    cout << "Which node to delete? " << endl; // prompt user
    output(head); // show list for reference
    cout << "Choice --> ";
    cin >> entry;
    deleteNode(head, entry); // remove selected node

    cout << "List after deletion" << endl;
    output(head); // show updated list

    // delete the entire linked list
    deleteList(head); // free memory for all remaining nodes

    cout << "Empty list." << endl; // indicate list is empty

    return 0;
}

// add a node at the front
void addToFront(Node*& head, int val) {
    Node* newNode = new Node{val, head}; // create node pointing to current head
    head = newNode;                       // update head
}

// add a node at the tail
void addToTail(Node*& head, int val) {
    Node* newNode = new Node{val, nullptr}; // new node points to nullptr
    if (!head) {                             // if list empty
        head = newNode;                      // new node becomes head
        return;
    }
    Node* temp = head; // traverse to end
    while (temp->next) temp = temp->next; // move to last node
    temp->next = newNode; // link last node to new node
}

// delete a node at a given position
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

// display the linked list
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
