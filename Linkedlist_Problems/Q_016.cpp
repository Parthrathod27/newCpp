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
💡 Problem: Delete the Middle Node of a Linked List
------------------------------------------------------------
Given the head of a singly linked list, delete the middle node 
and return the head of the modified list.

🧠 Definition of "middle":
If the number of nodes is n:
- The middle node is at index ⌊n / 2⌋ (0-based indexing)
  Example:
    [1, 3, 4, 7, 1, 2, 6] → middle = 4th element (7)
    [1, 2, 3, 4]          → middle = 2nd element (3)

------------------------------------------------------------
We will cover:
1️⃣ Brute Force (Two-pass approach using length)
2️⃣ Optimal (Single-pass approach using slow-fast pointer)
------------------------------------------------------------
*/


/*
------------------------------------------------------------
✅ 1️⃣ Brute Force — Count Length then Delete Middle
------------------------------------------------------------
Idea:
1. Traverse the entire list once to find its length.
2. Compute mid = length / 2
3. Traverse again till the (mid-1)th node and delete its next.

Example:
List: 1 -> 2 -> 3 -> 4 -> 5
Length = 5 → mid = 2 (0-based)
We stop at node 2 and remove node 3.

Time Complexity:  O(2N)  ≈ O(N)
Space Complexity: O(1)
------------------------------------------------------------
*/

class Solution_Brute {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Base case: empty or single node
        if (head == NULL || head->next == NULL)
            return NULL;

        // Step 1: Find length
        int length = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            length++;
            temp = temp->next;
        }

        // Step 2: Find middle index
        int mid = length / 2;

        // Step 3: Traverse again till (mid-1)th node
        temp = head;
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        // Step 4: Delete the middle node
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};



/*
------------------------------------------------------------
✅ 2️⃣ Optimal — Slow and Fast Pointer (Single Pass)
------------------------------------------------------------
👉 Idea:
- Use two pointers: `slow` and `fast`
- Move `fast` by two steps and `slow` by one step
- Keep a `prev` pointer to track the node before `slow`
- When `fast` reaches the end, `slow` will be at the middle
- Then delete the middle (`slow`) node.

Example:
1 -> 2 -> 3 -> 4 -> 5
slow = 3 (middle)
prev = 2 → prev->next = slow->next (deletes 3)

Time Complexity:  O(N)
Space Complexity: O(1)
------------------------------------------------------------
*/

class Solution_Optimal {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Base cases: no node or one node
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Move fast by 2 and slow by 1
        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node (slow)
        prev->next = slow->next;
        delete slow;

        return head;
    }
};



/*
------------------------------------------------------------
✅ 3️⃣ Alternate Variation — Using Vector (for clarity only)
------------------------------------------------------------
⚠️ Not space-efficient but good for learning.

Idea:
- Store all node values in a vector.
- Erase the middle index.
- Build a new linked list from the vector.

Time Complexity:  O(N)
Space Complexity: O(N)
------------------------------------------------------------
*/

class Solution_Vector {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL;

        // Step 1: Store all values
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // Step 2: Remove middle element
        int mid = arr.size() / 2;
        arr.erase(arr.begin() + mid);

        // Step 3: Create new linked list
        ListNode* newHead = new ListNode(arr[0]);
        temp = newHead;
        for (int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return newHead;
    }
};


/*
------------------------------------------------------------
🧠 SUMMARY TABLE:
------------------------------------------------------------
| Approach            | Time  | Space | Notes                            |
|----------------------|-------|--------|----------------------------------|
| 1. Brute (2-pass)    | O(N)  | O(1)   | Easy, intuitive                 |
| 2. Optimal (Floyd)   | O(N)  | O(1)   | Best approach (1 pass)          |
| 3. Vector Rebuild    | O(N)  | O(N)   | For understanding only          |
------------------------------------------------------------
*/

