/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
💡 Problem: Find the Length of the Loop in a Linked List
------------------------------------------------------------
You are given the head of a linked list. If the linked list 
contains a loop (cycle), return the length of that loop.
If there’s no loop, return 0.

Example:
Input:  1 -> 2 -> 3 -> 4 -> 5
               ↑           ↓
               ←----------- 
Output: 3   (because 3 -> 4 -> 5 -> 3 forms the loop of length 3)
------------------------------------------------------------
We’ll cover:
1️⃣ Brute Force (using unordered_map)
2️⃣ Optimal Approach (Floyd’s Cycle Detection)
------------------------------------------------------------
*/


/*
------------------------------------------------------------
✅ 1️⃣ Brute Force — Using unordered_map
------------------------------------------------------------
Idea:
- Use a hash map to store each node’s address and its index (step number).
- While traversing the list:
   • If a node is visited again → loop detected.
   • Loop length = current step - index of that node.
- If we reach NULL, no loop exists.

Time Complexity: O(N)
Space Complexity: O(N)
*/

class Solution_Brute {
public:
    int countNodesinLoop(ListNode* head) {
        unordered_map<ListNode*, int> mp;
        ListNode* temp = head;
        int index = 0;

        while (temp != NULL) {
            // If node already visited, calculate loop length
            if (mp.find(temp) != mp.end()) {
                return index - mp[temp];
            }
            mp[temp] = index;
            index++;
            temp = temp->next;
        }

        // If no loop found
        return 0;
    }
};


/*
------------------------------------------------------------
✅ 2️⃣ Optimal — Floyd’s Cycle Detection Algorithm
------------------------------------------------------------
Also known as the "Tortoise and Hare" method.

👉 Step 1: Detect the presence of a loop
   - Use two pointers (slow and fast)
   - Move slow by 1 step and fast by 2 steps
   - If they meet → a cycle exists.

👉 Step 2: Find the length of the loop
   - Keep one pointer fixed at meeting point.
   - Move the other pointer one step at a time
     until it meets again → count the steps.

Example:
1 -> 2 -> 3 -> 4 -> 5 -> 3 forms a loop
slow = 3, fast = 3 (meeting point)
Now count from 3 → 4 → 5 → 3 → count = 3

Time Complexity: O(N)
Space Complexity: O(1)
------------------------------------------------------------
*/

class Solution_Optimal {
public:
    int countNodesinLoop(ListNode* head) {
        if (head == NULL || head->next == NULL) return 0;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // If they meet, loop detected
            if (slow == fast)
                return countLength(slow);  // call helper to find loop length
        }

        // No loop
        return 0;
    }

private:
    // Helper function to count length of the loop
    int countLength(ListNode* meetingPoint) {
        int count = 1;
        ListNode* temp = meetingPoint->next;

        while (temp != meetingPoint) {
            count++;
            temp = temp->next;
        }

        return count;
    }
};


/*
------------------------------------------------------------
✅ 3️⃣ Slight Variation — Modify Node Visited Flag (Not Recommended)
------------------------------------------------------------
⚠️  Modifies the structure (only for understanding).

Idea:
- Mark visited nodes by setting next pointer to a special marker.
- When you encounter a node that’s already marked,
  loop length = number of nodes revisited before marker repeats.

⚠️ Avoid this in interviews — destructive operation.
Time Complexity: O(N)
Space Complexity: O(1)
------------------------------------------------------------
*/

class Solution_Marking {
public:
    int countNodesinLoop(ListNode* head) {
        ListNode* marker = new ListNode(-1);
        ListNode* temp = head;
        int count = 0;

        while (temp != NULL) {
            if (temp->next == marker) {
                // Once marker encountered again, loop ends
                return count;
            }
            ListNode* nextNode = temp->next;
            temp->next = marker;  // mark node
            count++;
            temp = nextNode;
        }

        return 0;  // no loop found
    }
};


/*
------------------------------------------------------------
🧠 SUMMARY TABLE:
------------------------------------------------------------
| Approach                 | Time  | Space | Safe for Interview | Comment                     |
|---------------------------|-------|--------|--------------------|-----------------------------|
| 1. Hash Map (Brute)       | O(N)  | O(N)   | ✅ Yes             | Simple to write & debug     |
| 2. Floyd’s Algorithm      | O(N)  | O(1)   | ✅✅ Best Approach  | Most optimal solution       |
| 3. Marker Modification    | O(N)  | O(1)   | ❌ Not recommended | Alters list structure       |
------------------------------------------------------------
*/

