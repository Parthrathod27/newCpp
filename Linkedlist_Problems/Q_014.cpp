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

/*
------------------------------------------------------------
💡 Problem: Detect a Loop / Cycle in a Linked List
------------------------------------------------------------
You are given the head of a linked list. Your task is to determine
if the linked list contains a cycle (loop). Return true if there 
is a cycle, otherwise return false.

A cycle exists if some node’s next pointer points to a previously 
visited node in the list.

Example:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: The tail connects to the second node.

------------------------------------------------------------
There are mainly 3 approaches:
------------------------------------------------------------
1️⃣  Brute Force — Using Map / Set (Extra Space)
2️⃣  Optimal — Using Slow and Fast Pointer (Floyd’s Cycle Detection)
3️⃣  Slight Variation — Modify Node Structure (Marking visited nodes)
------------------------------------------------------------
*/

// ✅ 1️⃣ Brute Force Approach (Using unordered_set)
/*
   Idea:
   - Traverse the linked list.
   - Store each node’s address in a hash set.
   - If we ever encounter a node that is already in the set, 
     it means a loop exists.
   - Otherwise, if we reach NULL, no loop exists.

   Time Complexity: O(N)
   Space Complexity: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution_Brute {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> visited;  // store node addresses

        ListNode* temp = head;
        while (temp != NULL) {
            // If this node is already visited, loop detected
            if (visited.find(temp) != visited.end())
                return true;
            
            visited.insert(temp);  // mark node as visited
            temp = temp->next;
        }

        // If we reached end, no cycle
        return false;
    }
};


/*
------------------------------------------------------------
✅ 2️⃣ Optimal Approach — Floyd’s Cycle Detection Algorithm
------------------------------------------------------------
Also called the "Tortoise and Hare" method.

Idea:
- Use two pointers:
  - slow moves 1 step at a time
  - fast moves 2 steps at a time
- If there is a cycle, fast and slow will eventually meet.
- If fast reaches NULL, there’s no cycle.

Intuition:
If both start at the same node, and one moves faster, 
it’ll eventually “lap” the slower one if there’s a cycle.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution_Optimal {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;  // no cycle possible

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;           // move 1 step
            fast = fast->next->next;     // move 2 steps

            if (slow == fast)            // they met => cycle exists
                return true;
        }

        // if we reached end => no cycle
        return false;
    }
};


/*
------------------------------------------------------------
✅ 3️⃣ Marking Nodes (Less Preferred)
------------------------------------------------------------
⚠️  Not a standard or safe approach (modifies the list).

Idea:
- Temporarily change each node’s next pointer to a dummy node (marker).
- If we encounter a node whose next is already set to that marker,
  it means we’ve visited it before — cycle detected.

Time Complexity: O(N)
Space Complexity: O(1)
Note: Modifies the linked list (not suitable for interview platforms).
*/

class Solution_Marking {
public:
    bool hasCycle(ListNode* head) {
        ListNode* marker = new ListNode(-1); // marker node

        while (head != NULL) {
            if (head->next == marker)  // visited before
                return true;

            ListNode* temp = head->next;
            head->next = marker;       // mark as visited
            head = temp;
        }

        return false;
    }
};

/*
------------------------------------------------------------
🧠 Summary of Approaches:
------------------------------------------------------------
| Approach                 | Time  | Space | Safe for Interviews | Comment                    |
|---------------------------|-------|--------|---------------------|----------------------------|
| 1. Hash Set (Brute)       | O(N)  | O(N)   | ✅ Yes              | Simple but uses memory     |
| 2. Floyd’s Algorithm      | O(N)  | O(1)   | ✅✅ Best Approach   | Most optimized and clean   |
| 3. Marking Nodes          | O(N)  | O(1)   | ❌ Not recommended  | Modifies the linked list   |
------------------------------------------------------------
*/

