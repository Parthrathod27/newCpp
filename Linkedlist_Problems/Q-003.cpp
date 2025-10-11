// ---------------------------------------------------------------
// L3. Introduction to Doubly LinkedList | Insertions & Deletions
// (Take U Forward)  
// ---------------------------------------------------------------
//
// This covers operations on a doubly linked list (DLL):
// 1) Insert at head
// 2) Insert at tail
// 3) Insert at given position (1-based indexing)  
// 4) Delete head
// 5) Delete tail
// 6) Delete at given position  
//
// Each operation handles updating both `next` and `prev` (back) pointers.
// Edge cases (empty list, single node, out-of-range positions) are considered.
//
// Copy this into your file and use as your DLL reference.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;  // back pointer in DLL
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

// Utility: print list forward
void printForward(Node* head) {
    Node* cur = head;
    cout << "Forward: ";
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

// Utility: print list backward from tail
void printBackward(Node* tail) {
    Node* cur = tail;
    cout << "Backward: ";
    while (cur != nullptr) {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << "\n";
}

// Utility: find tail from head
Node* getTail(Node* head) {
    Node* cur = head;
    while (cur && cur->next != nullptr) {
        cur = cur->next;
    }
    return cur;
}

// 1) Insert at Head of DLL
/*
Approach:
- Create new node.
- newNode->next = head.
- If head exists: head->prev = newNode.
- newNode->prev = nullptr.
- Return newNode as new head.
Edge: head == nullptr case handled (list empty).
Time: O(1)
*/
Node* insertAtHeadDLL(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr) {
        head->prev = newNode;
    }
    return newNode;
}

// 2) Insert at Tail of DLL
/*
Approach:
- If list empty, same as insertAtHead.
- Else traverse to last node (or get tail via helper).
- tail->next = newNode; newNode->prev = tail.
- Return head unchanged.
Time: O(N) worst-case
*/
Node* insertAtTailDLL(Node* head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        return newNode;
    }
    Node* tail = getTail(head);
    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

// 3) Insert at Given Position (1-based) in DLL
/*
Approach:
- If pos == 1: insert at head.
- Else traverse to position pos-1 (prevNode).
- If prevNode is null or beyond list → position invalid, no insert.
- Insert between prevNode and next node:
    prevNode->next = newNode;
    newNode->prev = prevNode;
    newNode->next = nextNode;
    if nextNode exists: nextNode->prev = newNode.
Time: O(N)
*/
Node* insertAtPositionDLL(Node* head, int val, int pos) {
    if (pos <= 0) {
        cout << "Invalid position " << pos << "\n";
        return head;
    }
    if (pos == 1) {
        return insertAtHeadDLL(head, val);
    }
    Node* cur = head;
    int count = 1;
    while (cur != nullptr && count < pos - 1) {
        cur = cur->next;
        count++;
    }
    if (cur == nullptr) {
        cout << "Position out of range " << pos << "\n";
        return head;
    }
    Node* nextNode = cur->next;
    Node* newNode = new Node(val);
    cur->next = newNode;
    newNode->prev = cur;
    newNode->next = nextNode;
    if (nextNode != nullptr) {
        nextNode->prev = newNode;
    }
    return head;
}

// 4) Delete Head of DLL
/*
Approach:
- If head is null: nothing to delete.
- Else move head to head->next.
- If new head exists: set its prev = nullptr.
- Disconnect old head, delete it.
Time: O(1)
*/
Node* deleteHeadDLL(Node* head) {
    if (head == nullptr) return nullptr;
    Node* temp = head;
    Node* newHead = head->next;
    if (newHead != nullptr) {
        newHead->prev = nullptr;
    }
    temp->next = nullptr;
    delete temp;
    return newHead;
}

// 5) Delete Tail of DLL
/*
Approach:
- If list empty: return null.
- If only one node: delete and return null.
- Else traverse to last node (tail). Use tail->prev.
- tailPrev->next = nullptr; tail->prev = nullptr; delete tail.
Time: O(N)
*/
Node* deleteTailDLL(Node* head) {
    if (head == nullptr) return nullptr;
    Node* tail = getTail(head);
    if (tail->prev == nullptr) {
        // only one node
        delete tail;
        return nullptr;
    }
    Node* prevNode = tail->prev;
    prevNode->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

// 6) Delete at Given Position (1-based) in DLL
/*
Approach:
- If head null: no-op.
- If pos == 1: delete head.
- Else traverse to the node at position pos.
- If the node is null: out-of-range.
- Let delNode = current node, prevNode = delNode->prev, nextNode = delNode->next.
- Connect prevNode->next = nextNode, and if next exists: nextNode->prev = prevNode.
- Disconnect delNode and delete it.
Time: O(N)
*/
Node* deleteAtPositionDLL(Node* head, int pos) {
    if (head == nullptr) return nullptr;
    if (pos <= 0) {
        cout << "Invalid position " << pos << "\n";
        return head;
    }
    if (pos == 1) {
        return deleteHeadDLL(head);
    }
    Node* cur = head;
    int count = 1;
    while (cur != nullptr && count < pos) {
        cur = cur->next;
        count++;
    }
    if (cur == nullptr) {
        cout << "Position out of range " << pos << "\n";
        return head;
    }
    Node* prevNode = cur->prev;
    Node* nextNode = cur->next;
    prevNode->next = nextNode;
    if (nextNode != nullptr) {
        nextNode->prev = prevNode;
    }
    cur->next = nullptr;
    cur->prev = nullptr;
    delete cur;
    return head;
}

// ---------------------------------------------------------------
// Example main to test DLL operations
int main() {
    Node* head = nullptr;

    // Insertions
    head = insertAtHeadDLL(head, 10);
    head = insertAtTailDLL(head, 20);
    head = insertAtTailDLL(head, 30);
    head = insertAtPositionDLL(head, 25, 3);  // 10 <-> 20 <-> 25 <-> 30

    cout << "After insertions:\n";
    printForward(head);
    printBackward(getTail(head));

    // Deletions
    head = deleteHeadDLL(head);      // delete 10
    head = deleteTailDLL(head);      // delete 30
    head = deleteAtPositionDLL(head, 2);  // delete 25

    cout << "\nAfter deletions:\n";
    printForward(head);
    printBackward(getTail(head));

    // Clean up remaining
    while (head != nullptr) {
        head = deleteHeadDLL(head);
    }

    return 0;
}

