/*
=============================================
🧠 PROBLEM: Detect a Loop or Cycle in Linked List
=============================================

We are given the head of a linked list.  
We need to determine whether the linked list contains a cycle (loop) or not.

A cycle occurs when a node’s next pointer points back to a previous node,
causing an infinite loop.

-------------------------------------------------
📘 Example:
-------------------------------------------------
Input:  1 -> 2 -> 3 -> 4 -> 5
                   ^         |
                   |_________|
Output: True (because 5->next points to 3)

-------------------------------------------------
✅ APPROACH 1: Using Hashing (Extra Space)
-------------------------------------------------
🔹 IDEA:
We can store each visited node in a hash set (unordered_set in C++).
If we visit a node that’s already in the set, it means there’s a cycle.

🔹 STEPS:
1. Create an unordered_set<ListNode*>.
2. Traverse the linked list node by node.
3. If current node already exists in the set → loop detected → return true.
4. Else insert the node in the set and continue.
5. If we reach NULL, return false (no loop).

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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;
        while (head != NULL) {
            if (visited.find(head) != visited.end())
                return true; // Loop detected
            visited.insert(head);
            head = head->next;
        }
        return false; // No loop
    }
};

/*
-------------------------------------------------
✅ APPROACH 2: Floyd’s Cycle Detection Algorithm (Tortoise & Hare)
-------------------------------------------------
🔹 INTUITION:
If two people are running around a circular track at different speeds,
the faster one will eventually meet the slower one again.

🔹 PROOF OF CORRECTNESS:
Let:
 - Distance from head to start of loop = D
 - Length of loop = C
 - Distance from loop start to meeting point = X

At meeting point:
    Distance traveled by slow pointer = D + X
    Distance traveled by fast pointer = D + X + n*C  (since it makes n full circles)

Since fast moves twice as fast as slow:
    2(D + X) = D + X + n*C
    ⟹ D + X = n*C
    ⟹ D = n*C - X

This means: if we move one pointer to head, and keep another at meeting point,
and move both at same speed, they’ll meet again at the start of the loop.

🔹 STEPS:
1. Initialize two pointers → slow and fast → both pointing to head.
2. Move slow by one step, fast by two steps.
3. If they meet → loop exists.
4. Else if fast or fast->next becomes NULL → no loop.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(1)

*/

class Solution_Floyd {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true; // Loop detected
        }
        return false; // No loop
    }
};

/*
-------------------------------------------------
🧩 SUMMARY
-------------------------------------------------
| Approach | Method        | Time | Space | Notes                          |
|-----------|---------------|------|-------|--------------------------------|
| 1         | Hashing       | O(N) | O(N)  | Easy but uses extra space      |
| 2         | Floyd’s Algo  | O(N) | O(1)  | Most efficient (Tortoise-Hare) |

-------------------------------------------------
💡 INTUITION (WHY FLOYD WORKS)
-------------------------------------------------
Because the fast pointer moves at 2x speed, when slow enters the cycle,
the fast pointer will keep looping and eventually “lap” slow,
guaranteeing a meeting point if a loop exists.
This mathematical inevitability makes Floyd’s algorithm elegant and optimal.
-------------------------------------------------
*/

