/*
Brute Force and Optimal approaches for reversing a Doubly Linked List
Class definition provided by LeetCode/Platform:
*/

/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // =======================================================
    // 1️⃣ Brute Force Approach
    // =======================================================
    /*
    Logic:
    - Brute force swaps the values of nodes from front and back.
    - Uses two pointers: one starting from head, one from tail.
    - Swap data until pointers meet.
    - Time Complexity: O(N)
    - Space Complexity: O(1)
    */

    Node* reverseBruteForce(Node* head) {
        if(head == nullptr) return nullptr;

        Node* left = head;
        Node* right = head;

        // Move right to the tail of DLL
        while(right->next != nullptr) {
            right = right->next;
        }

        // Swap data from front and back
        while(left != right && left->prev != right) {
            swap(left->data, right->data);
            left = left->next;
            right = right->prev;
        }

        return head;
    }


    // =======================================================
    // 2️⃣ Optimal Approach (Pointer Reversal)
    // =======================================================
    /*
    Logic:
    - Optimal approach reverses the DLL by changing links in-place.
    - For each node, swap its 'next' and 'prev' pointers.
    - Move to original next node (which is current->prev after swap).
    - Finally, return the last processed node as the new head.
    - Time Complexity: O(N)
    - Space Complexity: O(1)
    */

    Node* reverseOptimal(Node* head) {
        Node* current = head;
        Node* temp = nullptr;

        while(current != nullptr) {
            // Swap next and prev
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // Move to next node (original next)
            current = current->prev;
        }

        // After the loop, temp points to previous node of null (new head)
        if(temp != nullptr) {
            head = temp->prev;
        }

        return head;
    }
};


// ======================
// Example Usage (Test)
// ======================

int main() {
    // Example: 1 <-> 2 <-> 3 <-> 4
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;

    Solution sol;

    // ✅ Brute Force
    Node* head1 = sol.reverseBruteForce(n1);

    // ✅ Optimal
    Node* head2 = sol.reverseOptimal(head1);

    return 0;
}

