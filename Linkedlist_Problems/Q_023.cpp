/*
--------------------------------------------
🧠 PROBLEM: Remove Duplicates from Sorted Doubly Linked List (DLL)
--------------------------------------------

Given a **sorted doubly linked list**, remove all duplicate nodes so that each element appears only once.

--------------------------------------------
📘 Example:
--------------------------------------------
Input: 1 <-> 1 <-> 2 <-> 3 <-> 3 <-> 4 <-> 4 <-> 5  
Output: 1 <-> 2 <-> 3 <-> 4 <-> 5

--------------------------------------------
🧩 Observation:
--------------------------------------------
Since the DLL is **sorted**, all duplicates will appear **next to each other**.
That allows us to easily detect and remove them in one traversal.

--------------------------------------------
💡 APPROACH 1: Single Traversal (Optimal)
--------------------------------------------

🔹 Idea:
Compare the current node with its next node.  
If both have the same value, remove the next node by updating pointers.

🔹 Steps:
1. Start from head node.
2. While traversing:
   - If (current->data == current->next->data), delete the next node.
   - Else, move to the next node.
3. Continue until the end of the list.

🔹 Time Complexity → O(N)
🔹 Space Complexity → O(1)
--------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

Node* removeDuplicates(Node* head) {
    if (head == NULL) return head; // Empty list

    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        // If duplicate found
        if (curr->data == curr->next->data) {
            Node* duplicate = curr->next;

            // Skip the duplicate node
            curr->next = duplicate->next;
            if (duplicate->next != NULL)
                duplicate->next->prev = curr;

            delete duplicate; // Free memory
        } else {
            curr = curr->next; // Move to next unique node
        }
    }
    return head;
}

/*
--------------------------------------------
💡 APPROACH 2: Using Set (Extra Space)
--------------------------------------------

🔹 Idea:
Even though the list is sorted, we can use a `set` to store unique elements.
This is not optimal but works for **unsorted DLLs** as well.

🔹 Steps:
1. Traverse DLL and store all values in a set.
2. Reconstruct DLL using unique values from the set.

🔹 Time Complexity → O(N)
🔹 Space Complexity → O(N)
⚠️ Not recommended for **sorted** lists since Approach 1 is better.
--------------------------------------------
*/

Node* removeDuplicatesUsingSet(Node* head) {
    if (!head) return NULL;

    unordered_set<int> seen;
    Node* curr = head;

    while (curr != NULL) {
        if (seen.find(curr->data) != seen.end()) {
            Node* duplicate = curr;
            Node* prevNode = curr->prev;
            Node* nextNode = curr->next;

            prevNode->next = nextNode;
            if (nextNode != NULL)
                nextNode->prev = prevNode;

            curr = nextNode;
            delete duplicate;
        } else {
            seen.insert(curr->data);
            curr = curr->next;
        }
    }
    return head;
}

/*
--------------------------------------------
🧩 DRY RUN EXAMPLE (Approach 1)
--------------------------------------------
List: 1 <-> 1 <-> 2 <-> 3 <-> 3

Step 1: curr = 1 → duplicate found → remove second 1  
List → 1 <-> 2 <-> 3 <-> 3

Step 2: curr = 2 → no duplicate → move forward  
Step 3: curr = 3 → duplicate found → remove second 3  
List → 1 <-> 2 <-> 3 ✅

--------------------------------------------
✅ PROOF OF CORRECTNESS
--------------------------------------------
1️⃣ Because DLL is sorted, duplicates appear contiguously.
2️⃣ We traverse only once and adjust next/prev pointers correctly.
3️⃣ No new memory allocation → O(1) extra space.

--------------------------------------------
*/

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(1);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    cout << "Original List: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}

/*
--------------------------------------------
🧾 SUMMARY
--------------------------------------------
Approach 1: Single Traversal (Optimal) → O(N), O(1)
Approach 2: Using Set (Extra Space) → O(N), O(N)

🔥 Recommended: Approach 1 — efficient and in-place.
--------------------------------------------
*/

