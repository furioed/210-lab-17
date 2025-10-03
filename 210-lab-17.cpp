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
void addToFront(Node*& head, int val);  // add new node at front
void output(Node* head);                // display linked list
void deleteList(Node*& head);           // delete entire linked list

int main() {
    srand(time(0));
    Node* head = nullptr;  // pointer to first node

    // create a linked list of size 7 with random numbers 0-99
    for (int i = 0; i < 7; i++) {
        addToFront(head, rand() % 100); // add each new random value at the front
    }

    cout << "Initial list" << endl;
    output(head); // display all nodes

    // delete the entire linked list
    deleteList(head); // remove all nodes and free memory

    cout << "Empty list." << endl; // indicate that list is now empty

    return 0;
}

// add a node at the front of the linked list
void addToFront(Node*& head, int val) {
    Node* newNode = new Node{val, head}; // create new node pointing to current head
    head = newNode;                       // update head to new node
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

// delete every node in the linked list
void deleteList(Node*& head) {
    Node* temp;
    while (head) {
        temp = head;       // store current node
        head = head->next; // move head forward
        delete temp;       // free memory
    }
}
