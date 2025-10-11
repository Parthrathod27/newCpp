// Striver — L2: Deletion and Insertion in Linked List (8 Problems)
// Copy-paste this file into: Patterns/LinkedList/ll_L2.cpp
// Example: mkdir -p Patterns/LinkedList && nano Patterns/LinkedList/ll_L2.cpp
// Then paste and save (Cmd+S in GUI or Ctrl+O, Enter, Ctrl+X in nano).
//
// This file contains:
// 1) insertAtHead
// 2) insertAtTail
// 3) insertAtPosition (1-based)
// 4) insertBeforeValue (insert before first node with value x)
// 5) deleteHead
// 6) deleteTail
// 7) deleteAtPosition (1-based)
// 8) deleteByValue (delete first occurrence of given value)
//
// Each function returns the (possibly new) head pointer where applicable.
// Time complexities are O(N) in the worst case where traversal is needed.

#include <iostream>
using namespace std;

// -----------------------------
// Node definition
// -----------------------------
struct Node {
    int data;
    Node* next;
    Node(int x, Node* n = nullptr) {
        data = x;
        next = n;
    }
};

// -----------------------------
// Helper utilities
// -----------------------------
void printList(Node* head) {
    // print nodes space-separated; prints "Empty" if list is empty
    if (head == nullptr) {
        cout << "Empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int getLength(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp != nullptr) { cnt++; temp = temp->next; }
    return cnt;
}

// -----------------------------
// 1) Insert at Head
// -----------------------------
/*
Approach:
- Create new node and point its next to current head.
- Return new node as new head.
Edge cases:
- Works for empty list (head == nullptr).
Time: O(1), Space: O(1)
*/
Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode; // new head
}

// -----------------------------
// 2) Insert at Tail
// -----------------------------
/*
Approach:
- If list empty -> new node becomes head.
- Else traverse until last node (temp->next == nullptr), attach new node.
Edge cases:
- Empty list handled explicitly.
Time: O(N) worst-case (traversal), Space: O(1)
*/
Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) return newNode;
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
    return head;
}

// -----------------------------
// 3) Insert at Given Position (1-based)
// -----------------------------
/*
Approach:
- If pos == 1 -> insertAtHead.
- Else traverse to node at index pos-1 (if exists) and insert there.
Edge cases:
- If pos is <= 0 -> treat as invalid (no op).
- If pos > length+1 -> position out of range (no insert) — function returns head unchanged.
Time: O(N), Space: O(1)
*/
Node* insertAtPosition(Node* head, int val, int pos) {
    if (pos <= 0) {
        // invalid position
        cout << "Invalid position: " << pos << "\n";
        return head;
    }
    if (pos == 1) return insertAtHead(head, val);
    Node* temp = head;
    int cnt = 1;
    while (temp != nullptr && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp == nullptr) {
        // pos is greater than length+1
        cout << "Position out of range: " << pos << "\n";
        return head;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

// -----------------------------
// 4) Insert BEFORE node with value X (first occurrence)
// -----------------------------
/*
Approach:
- If head null -> no-op.
- If head->data == x -> insert at head.
- Else keep previous and current pointers; when current->data == x, insert new node between prev and current.
Edge cases:
- Value x not found -> no-op (you can change to append or report).
Time: O(N), Space: O(1)
*/
Node* insertBeforeValue(Node* head, int val, int x) {
    if (head == nullptr) {
        cout << "List empty. Value " << x << " not found.\n";
        return head;
    }
    if (head->data == x) {
        return insertAtHead(head, val);
    }
    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr && curr->data != x) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) {
        cout << "Value " << x << " not found in list.\n";
        return head;
    }
    Node* newNode = new Node(val);
    prev->next = newNode;
    newNode->next = curr;
    return head;
}

// -----------------------------
// 5) Delete Head
// -----------------------------
/*
Approach:
- If head == nullptr -> nothing to delete.
- Save head->next, delete head, return saved pointer as new head.
Time: O(1), Space: O(1)
*/
Node* deleteHead(Node* head) {
    if (head == nullptr) return nullptr;
    Node* nxt = head->next;
    delete head;
    return nxt;
}

// -----------------------------
// 6) Delete Tail
// -----------------------------
/*
Approach:
- If empty -> no-op.
- If single node -> delete and return nullptr.
- Else traverse to second-last node (temp->next->next == nullptr), delete last, set temp->next = nullptr.
Time: O(N), Space: O(1)
*/
Node* deleteTail(Node* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) { delete head; return nullptr; }
    Node* temp = head;
    while (temp->next->next != nullptr) temp = temp->next; // stop at second last
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// -----------------------------
// 7) Delete at Given Position (1-based)
// -----------------------------
/*
Approach:
- If pos == 1 -> deleteHead.
- Else traverse to node at pos-1 and remove its next (if exists).
Edge cases:
- pos <= 0 : invalid
- pos > length : position out of range, no-op
Time: O(N), Space: O(1)
*/
Node* deleteAtPosition(Node* head, int pos) {
    if (head == nullptr) return nullptr;
    if (pos <= 0) {
        cout << "Invalid position: " << pos << "\n";
        return head;
    }
    if (pos == 1) return deleteHead(head);
    Node* temp = head;
    int cnt = 1;
    while (temp->next != nullptr && cnt < pos - 1) {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == nullptr) {
        cout << "Position out of range: " << pos << "\n";
        return head;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
    return head;
}

// -----------------------------
// 8) Delete by Value (first occurrence)
// -----------------------------
/*
Approach:
- If head == nullptr -> no-op.
- If head->data == val -> deleteHead.
- Else use prev and cur to find the first node with data == val, then relink prev->next = cur->next and delete cur.
Edge cases:
- Value not found -> no-op
Time: O(N), Space: O(1)
*/
Node* deleteByValue(Node* head, int val) {
    if (head == nullptr) return nullptr;
    if (head->data == val) return deleteHead(head);
    Node* prev = head;
    Node* curr = head->next;
    while (curr != nullptr && curr->data != val) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr) {
        cout << "Value " << val << " not found.\n";
        return head;
    }
    prev->next = curr->next;
    delete curr;
    return head;
}

// -----------------------------
// Example usage (demo)
// -----------------------------
int main() {
    // start with list: 10 -> 20 -> 30 -> 40
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Initial list:\n";
    printList(head);

    // 1) Insert at head
    head = insertAtHead(head, 5); // 5 -> 10 -> 20 -> 30 -> 40
    cout << "\nAfter insertAtHead(5):\n"; printList(head);

    // 2) Insert at tail
    head = insertAtTail(head, 50); // ... -> 40 -> 50
    cout << "\nAfter insertAtTail(50):\n"; printList(head);

    // 3) Insert at position (pos=3)
    head = insertAtPosition(head, 15, 3); // insert 15 at index 3
    cout << "\nAfter insertAtPosition(15,3):\n"; printList(head);

    // 4) Insert before value 20 (insert 18 before first occurrence of 20)
    head = insertBeforeValue(head, 18, 20);
    cout << "\nAfter insertBeforeValue(18,20):\n"; printList(head);

    // 5) Delete head
    head = deleteHead(head);
    cout << "\nAfter deleteHead():\n"; printList(head);

    // 6) Delete tail
    head = deleteTail(head);
    cout << "\nAfter deleteTail():\n"; printList(head);

    // 7) Delete at position (pos=4)
    head = deleteAtPosition(head, 4);
    cout << "\nAfter deleteAtPosition(4):\n"; printList(head);

    // 8) Delete by value (first occurrence of 30)
    head = deleteByValue(head, 30);
    cout << "\nAfter deleteByValue(30):\n"; printList(head);

    // final cleanup: delete remaining nodes to avoid leaks
    while (head) head = deleteHead(head);

    return 0;
}

