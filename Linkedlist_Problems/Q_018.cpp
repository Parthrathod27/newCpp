/*
==========================================================
🧠 PROBLEM: Find the Length of the Loop in a Linked List
==========================================================

We are given the head of a linked list.
We need to determine if there is a cycle (loop) in it,
and if so, find the **length of that loop**.

----------------------------------------------------------
📘 Example:
----------------------------------------------------------
Input:  1 -> 2 -> 3 -> 4 -> 5
                   ^         |
                   |_________|
Output: 3   (since the loop contains nodes 3, 4, 5)

----------------------------------------------------------
✅ APPROACH 1: Using Hashing (Extra Space)
----------------------------------------------------------
🔹 IDEA:
We use an unordered_map (or unordered_set) to keep track of visited nodes
and their positions (or steps count).
When a repeated node is encountered, the difference between the
current step and the step when that node was first seen = loop length.

🔹 STEPS:
1. Create unordered_map<ListNode*, int> to store node → position.
2. Traverse the list and keep a counter `pos`.
3. If a node is already in the map → loop detected.
4. Loop length = current position - stored position of that node.
5. Return loop length.
6. If list ends (NULL) → no loop → return 0.

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
    int countLoopLength(ListNode* head) {
        unordered_map<ListNode*, int> visited;
        int pos = 0;
        while (head != NULL) {
            if (visited.find(head) != visited.end()) {
                // Loop length = current step - stored step
                return pos - visited[head];
            }
            visited[head] = pos;
            head = head->next;
            pos++;
        }
        return 0; // No loop found
    }
};

/*
----------------------------------------------------------
✅ APPROACH 2: Floyd’s Cycle Detection Algorithm (Optimal)
----------------------------------------------------------
🔹 IDEA:
First, use Floyd’s cycle detection (Tortoise & Hare) to check for a loop.
If a loop exists, both pointers (slow and fast) meet inside the loop.

Once they meet, we can find the **loop length** as follows:
 - Keep one pointer fixed.
 - Move the other pointer step by step until it comes back to the same node.
 - Count the steps → that is the loop length.

🔹 STEPS:
1. Use two pointers: slow and fast.
2. Move slow by 1 step and fast by 2 steps.
3. If they meet → loop detected.
4. Keep one pointer at meeting point.
5. Move the other pointer one step at a time, count steps until it meets again.
6. Return the count (length of loop).
7. If fast or fast->next becomes NULL → no loop → return 0.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(1)
*/

class Solution_Floyd {
public:
    int countLoopLength(ListNode* head) {
        if (head == NULL || head->next == NULL) return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect Loop
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // Meeting point found → loop detected
            if (slow == fast) {
                // Step 2: Find length of loop
                int count = 1;
                fast = fast->next;
                while (fast != slow) {
                    count++;
                    fast = fast->next;
                }
                return count;
            }
        }
        return 0; // No loop found
    }
};

/*
----------------------------------------------------------
🧩 SUMMARY
----------------------------------------------------------
| Approach | Method        | Time | Space | Notes                          |
|-----------|---------------|------|-------|--------------------------------|
| 1         | Hashing       | O(N) | O(N)  | Easy but uses extra space      |
| 2         | Floyd’s Algo  | O(N) | O(1)  | Most efficient & elegant       |

----------------------------------------------------------
💡 INTUITION BEHIND FLOYD’S APPROACH
----------------------------------------------------------
When fast and slow meet inside the loop, both are within the cycle.
Since the cycle is circular, we can just start from that meeting point
and count how many steps it takes to return to the same node again.

That step count = length of the cycle.

Mathematically guaranteed because:
- Both pointers are in the same cycle.
- Moving one pointer through each node of the cycle must lead back to start.
----------------------------------------------------------
*/

