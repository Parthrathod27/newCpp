/*
==========================================================
🧠 PROBLEM: Find the Starting Point of the Loop/Cycle in Linked List
==========================================================

We are given the head of a singly linked list.
We need to **find the node where the cycle (loop) begins**, if any.
If no loop exists, return NULL.

----------------------------------------------------------
📘 Example:
----------------------------------------------------------
Input: head = [3 -> 2 -> 0 -> -4]
             ↑              |
             |______________|

Output: Node with value = 2  
Explanation: Tail connects to node with value 2, so start of loop is node 2.

----------------------------------------------------------
📌 Edge Cases:
----------------------------------------------------------
1️⃣ Empty list → return NULL  
2️⃣ Single node → return NULL  
3️⃣ No cycle → return NULL  
4️⃣ Full list in cycle → start is head itself  

----------------------------------------------------------
✅ APPROACH 1: Using Hashing (Visited Nodes)
----------------------------------------------------------
🔹 IDEA:
Use a hash set (unordered_set) to store visited nodes.
If a node is visited twice, that node is the start of the loop.

🔹 STEPS:
1. Create an unordered_set.
2. Traverse the linked list.
3. If the current node is already in the set → return that node (start of loop).
4. Else, insert the node into the set.
5. If traversal ends (NULL) → no cycle, return NULL.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_Hashing {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> visited;

        ListNode* temp = head;
        while (temp != NULL) {
            // If node already visited → start of loop found
            if (visited.find(temp) != visited.end()) {
                return temp;
            }
            // Otherwise add to visited
            visited.insert(temp);
            temp = temp->next;
        }
        return NULL; // No loop found
    }
};

/*
----------------------------------------------------------
✅ APPROACH 2: Floyd’s Cycle Detection (Tortoise & Hare Algorithm)
----------------------------------------------------------
🔹 IDEA:
We use two pointers (slow & fast) to detect a loop,
and then use a mathematical relationship to find the starting node of the cycle.

----------------------------------------------------------
📘 PROOF OF CONCEPT:
----------------------------------------------------------
Let:
- distance from head to start of loop = L
- distance from start of loop to meeting point = X
- length of the loop = C

When fast and slow meet inside the loop:
  Distance(slow) = L + X
  Distance(fast) = L + X + n*C  (because fast moves extra full loops)

Since fast moves twice as fast:
  2*(L + X) = L + X + n*C
  => L = n*C - X
  => Distance from head to start (L) = Distance from meeting point to start (C - X)

💡 Therefore:
After detecting the loop (meeting point),
if we move one pointer to head and move both one step at a time,
they meet exactly at the start of the loop.

----------------------------------------------------------
🔹 STEPS:
1. Use slow & fast pointers.
2. Move slow = slow->next, fast = fast->next->next until they meet or fast becomes NULL.
3. If they meet → loop exists.
4. Set one pointer to head.
5. Move both pointers one step at a time until they meet again.
6. The node where they meet again is the **start of the loop**.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(1)
*/

class Solution_Floyd {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* intersection = NULL;

        // Step 1: Detect loop using slow-fast method
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                intersection = slow; // Loop detected
                break;
            }
        }

        if (intersection == NULL)
            return NULL; // No cycle found

        // Step 2: Move one pointer to head
        ListNode* start = head;

        // Step 3: Move both one step until they meet
        while (start != intersection) {
            start = start->next;
            intersection = intersection->next;
        }

        // Step 4: Return starting point of loop
        return start;
    }
};

/*
----------------------------------------------------------
✅ APPROACH 3: Modified Floyd’s with Helper Function
----------------------------------------------------------
This version is a clean modular variation of the Floyd’s algorithm.
It separates detection and finding loop start into two functions.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(1)
*/

class Solution_Modular {
private:
    // Function to detect intersection point
    ListNode* getIntersection(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return slow; // Intersection found
        }
        return NULL;
    }

public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* intersection = getIntersection(head);
        if (intersection == NULL)
            return NULL; // No cycle

        ListNode* ptr1 = head;
        ListNode* ptr2 = intersection;

        // Move both pointers until they meet → start of loop
        while (ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1;
    }
};

/*
----------------------------------------------------------
🧩 SUMMARY
----------------------------------------------------------
| Approach | Technique              | Time | Space | Notes                        |
|-----------|-----------------------|------|-------|------------------------------|
| 1         | Hashing               | O(N) | O(N)  | Simple, uses extra memory     |
| 2         | Floyd’s (Tortoise/Hare)| O(N) | O(1) | Optimal and elegant           |
| 3         | Modular Floyd’s        | O(N) | O(1) | Cleaner, reusable functions   |

----------------------------------------------------------
💡 INTUITION (Floyd’s)
----------------------------------------------------------
- Fast moves twice as fast as slow.
- When they meet, the loop exists.
- Reset one pointer to head; now both move at same speed.
- Their next meeting point will be the start of the cycle.
----------------------------------------------------------
*/

