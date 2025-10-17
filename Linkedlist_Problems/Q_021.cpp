/*
==========================================================
🧠 PROBLEM: Delete All Occurrences of a Key in a Doubly Linked List
==========================================================

We are given the head of a doubly linked list (DLL) and an integer key.
We must delete **all nodes** that have the value equal to the key.

----------------------------------------------------------
📘 Example:
----------------------------------------------------------
Input: DLL = 1 <-> 2 <-> 3 <-> 2 <-> 4  
       key = 2  
Output: DLL = 1 <-> 3 <-> 4  

Explanation: Both occurrences of 2 are deleted.

----------------------------------------------------------
📌 Edge Cases:
----------------------------------------------------------
1️⃣ List is empty → return NULL  
2️⃣ Only one node present and equals key → return NULL  
3️⃣ Key not found → return original list  
4️⃣ Head node(s) to be deleted  
5️⃣ Tail node to be deleted  

----------------------------------------------------------
✅ STRUCTURE DEFINITION
----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Doubly Linked List Node Definition
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

/*
----------------------------------------------------------
✅ APPROACH 1: ITERATIVE (TRAVERSAL + DELETE LINKS)
----------------------------------------------------------
🔹 IDEA:
Traverse the list and delete every node having data == key.
Update both `next` and `prev` pointers properly.

🔹 STEPS:
1. Start from the head node.
2. If current node’s data == key:
    - Adjust links of previous and next nodes.
    - If deleting head → move head to next node.
3. Continue traversal to next node after deletion.
4. Return updated head.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(1)
*/

class Solution_Iterative {
public:
    Node* deleteAllOccurrences(Node* head, int key) {
        if (head == NULL) return NULL;

        Node* temp = head;

        while (temp != NULL) {
            // Save the next pointer before potential deletion
            Node* nextNode = temp->next;

            // If node matches key → delete it
            if (temp->data == key) {
                // If temp is the head node
                if (temp == head) {
                    head = temp->next;
                    if (head) head->prev = NULL;
                }
                else {
                    // Adjust previous node's next pointer
                    if (temp->prev) temp->prev->next = temp->next;
                    // Adjust next node's prev pointer
                    if (temp->next) temp->next->prev = temp->prev;
                }

                // Free current node memory
                delete temp;
            }

            // Move to next node
            temp = nextNode;
        }

        return head;
    }
};

/*
----------------------------------------------------------
✅ APPROACH 2: RECURSIVE APPROACH
----------------------------------------------------------
🔹 IDEA:
Use recursion to delete key occurrences.
We recursively call on the `next` pointer until list end.

🔹 STEPS:
1. Base case → if head == NULL → return NULL.
2. Recur for remaining list: head->next = deleteAllOccurrences(head->next, key)
3. After recursion:
   - If current node matches key → delete and fix links.
   - Else return the current node.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(N) (due to recursion stack)
*/

class Solution_Recursive {
public:
    Node* deleteAllOccurrences(Node* head, int key) {
        // Base case: empty list
        if (head == NULL) return NULL;

        // Recursive call to process rest of the list
        head->next = deleteAllOccurrences(head->next, key);

        // Fix the prev pointer after recursive call
        if (head->next != NULL)
            head->next->prev = head;

        // If current node needs to be deleted
        if (head->data == key) {
            Node* temp = head->next;
            delete head;
            return temp;  // Return next node as new head
        }

        return head;
    }
};

/*
----------------------------------------------------------
✅ APPROACH 3: CLEANER ITERATIVE (Using Dummy Node)
----------------------------------------------------------
🔹 IDEA:
Sometimes deletion of head is tricky.
So we use a dummy node before head to simplify handling head deletions.

🔹 STEPS:
1. Create a dummy node before head.
2. Traverse from dummy node.
3. Delete nodes where data == key.
4. Return dummy->next as new head.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(1)
*/

class Solution_Dummy {
public:
    Node* deleteAllOccurrences(Node* head, int key) {
        if (head == NULL) return NULL;

        // Dummy node simplifies head deletion
        Node* dummy = new Node(-1);
        dummy->next = head;
        head->prev = dummy;

        Node* temp = head;

        while (temp != NULL) {
            if (temp->data == key) {
                Node* prevNode = temp->prev;
                Node* nextNode = temp->next;

                prevNode->next = nextNode;
                if (nextNode) nextNode->prev = prevNode;

                delete temp;
            }
            temp = temp->next;
        }

        // New head (after dummy)
        Node* newHead = dummy->next;
        if (newHead) newHead->prev = NULL;

        delete dummy;
        return newHead;
    }
};

/*
----------------------------------------------------------
🧩 SUMMARY TABLE
----------------------------------------------------------
| Approach | Method Type  | Time | Space | Notes |
|-----------|--------------|------|-------|--------|
| 1         | Iterative    | O(N) | O(1)  | Straightforward, efficient |
| 2         | Recursive    | O(N) | O(N)  | Elegant, but uses stack    |
| 3         | Dummy Node   | O(N) | O(1)  | Simplifies head handling   |

----------------------------------------------------------
💡 INTUITION:
----------------------------------------------------------
In a doubly linked list, deletion is easy because we can directly access
the previous node (unlike in singly linked list).
We must just correctly handle:
- Head deletion
- Tail deletion
- Consecutive deletions
----------------------------------------------------------
*/

