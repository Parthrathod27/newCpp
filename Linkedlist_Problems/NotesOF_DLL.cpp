#include <bits/stdc++.h>
using namespace std;

/*
🧠 What is a Doubly Linked List (DLL)?
--------------------------------------
A Doubly Linked List is a linear data structure where each node has
three components:
    1️⃣ data   → stores the actual value
    2️⃣ prev   → pointer to the previous node
    3️⃣ next   → pointer to the next node

Advantages over Singly Linked List:
-----------------------------------
✅ Can be traversed in both directions (forward & backward)
✅ Easier to delete or insert nodes in the middle
✅ Used in applications like LRU Cache, undo-redo, browsers, etc.
*/

//------------------------------------------------------
// 🌟 Define the structure (Node) for Doubly Linked List
//------------------------------------------------------
class Node {
public:
    int data;       // data part
    Node* prev;     // pointer to previous node
    Node* next;     // pointer to next node

    // Constructor to create new node
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

//------------------------------------------------------
// 🧩 Convert an array to Doubly Linked List
//------------------------------------------------------
Node* convertArrToDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;

    Node* head = new Node(arr[0]);   // create head node
    Node* prev = head;               // keep track of previous node

    // link all elements one by one
    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        prev->next = temp;   // link prev node to current
        temp->prev = prev;   // link current node to prev
        prev = temp;         // move prev forward
    }
    return head;
}

//------------------------------------------------------
// 👣 Traverse DLL (forward direction)
//------------------------------------------------------
void printDLL(Node* head) {
    Node* temp = head;
    cout << "DLL (forward): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

//------------------------------------------------------
// 🔁 Traverse DLL (backward direction)
//------------------------------------------------------
void printReverseDLL(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    // move to tail
    while (temp->next != nullptr)
        temp = temp->next;

    cout << "DLL (reverse): ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

//------------------------------------------------------
// 🔢 Count number of nodes in DLL
//------------------------------------------------------
int countDLL(Node* head) {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

//------------------------------------------------------
// 🔄 Reverse the DLL
//------------------------------------------------------
Node* reverseDLL(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head;  // single node or empty

    Node* curr = head;
    Node* prev = nullptr;

    while (curr != nullptr) {
        // swap the next and prev pointers
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;

        // move to next node (which is curr->prev now)
        curr = curr->prev;
    }

    // after loop, 'prev' will be at old head, so move one step back
    if (prev != nullptr)
        head = prev->prev;

    return head;
}

//------------------------------------------------------
// 🧠 Main function for demonstration
//------------------------------------------------------
int main() {
    vector<int> arr = {10, 20, 30, 40, 50};

    // convert array to DLL
    Node* head = convertArrToDLL(arr);

    // print DLL in forward direction
    printDLL(head);

    // print DLL in reverse direction
    printReverseDLL(head);

    // print count of nodes
    cout << "Total nodes in DLL: " << countDLL(head) << endl;

    // reverse DLL and print again
    head = reverseDLL(head);
    cout << "After Reversing: ";
    printDLL(head);

    return 0;
}

/*
🧩 Summary of Basic Operations
-------------------------------
✅ convertArrToDLL → Creates DLL from array
✅ printDLL → Prints DLL from head → tail
✅ printReverseDLL → Prints DLL from tail → head
✅ countDLL → Counts total number of nodes
✅ reverseDLL → Reverses the DLL

💡 Use Cases:
-------------
- LRU Cache
- Undo/Redo operations
- Browser history
- Playlist navigation
*/

