/*
==========================================================
🧠 PROBLEM: Delete the Middle Node of a Linked List
==========================================================

We are given the head of a singly linked list.
We need to delete the **middle node** and return the modified list.

----------------------------------------------------------
📘 Example:
----------------------------------------------------------
Input: 1 -> 2 -> 3 -> 4 -> 5  
Output: 1 -> 2 -> 4 -> 5  
Explanation: The middle node (3) is removed.

If there are even number of nodes:
Input: 1 -> 2 -> 3 -> 4  
Output: 1 -> 2 -> 4  
(Here, node 3 is considered middle as we take ⌊n/2⌋)

----------------------------------------------------------
📌 Edge Cases:
----------------------------------------------------------
1️⃣ Empty List → return NULL  
2️⃣ Only One Node → delete it, return NULL  
3️⃣ Two Nodes → delete the 2nd (as per middle definition)

----------------------------------------------------------
✅ APPROACH 1: Using Count (Two Pass)
----------------------------------------------------------
🔹 IDEA:
1. First pass → count total number of nodes (let’s call it n).
2. Middle = n/2  (0-based index)
3. Second pass → traverse till (middle - 1)th node.
4. Change its next pointer to skip the middle node.

🔹 STEPS:
1. Count total nodes.
2. Traverse again and delete middle node.
3. Return head.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution_TwoPass {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL; // if single node or empty, delete it (return NULL)

        // Step 1: Count total nodes
        int count = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: Find middle index
        int mid = count / 2;

        // Step 3: Traverse again to node before middle
        temp = head;
        for (int i = 0; i < mid - 1; i++) {
            temp = temp->next;
        }

        // Step 4: Delete middle node
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};

/*
----------------------------------------------------------
✅ APPROACH 2: Using Slow and Fast Pointers (Single Pass)
----------------------------------------------------------
🔹 IDEA:
Use two pointers (slow and fast) to find the middle node in one traversal.
Keep track of the node before slow (called 'prev') so that we can delete the middle.

🔹 STEPS:
1. Initialize slow = head, fast = head, prev = NULL.
2. Move slow by 1 and fast by 2 until fast reaches the end.
3. Now slow points to middle node, prev points to node before middle.
4. Change prev->next = slow->next to delete middle node.
5. Return head.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(1)
*/

class Solution_FastSlow {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return NULL; // Single node case

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        // Move fast by 2 and slow by 1
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // slow is at middle
        prev->next = slow->next;
        delete slow;

        return head;
    }
};

/*
----------------------------------------------------------
✅ APPROACH 3: Using Vector (for understanding)
----------------------------------------------------------
🔹 IDEA:
Store all nodes in a vector for quick access.
Find middle index and delete that node by updating next pointer of previous node.

🔹 STEPS:
1. Traverse the list and store all nodes in vector.
2. Middle index = size / 2.
3. If middle is first node → return head->next.
4. Else set nodes[mid-1]->next = nodes[mid]->next.

🔹 TIME COMPLEXITY: O(N)
🔹 SPACE COMPLEXITY: O(N)
*/

class Solution_Vector {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next)
            return NULL;

        vector<ListNode*> nodes;
        ListNode* temp = head;
        while (temp != NULL) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int mid = nodes.size() / 2;

        // Delete first node case
        if (mid == 0) return head->next;

        // Connect previous node to next of middle
        nodes[mid - 1]->next = nodes[mid]->next;
        delete nodes[mid];

        return head;
    }
};

/*
----------------------------------------------------------
🧩 SUMMARY
----------------------------------------------------------
| Approach | Technique           | Time | Space | Notes                          |
|-----------|--------------------|------|-------|--------------------------------|
| 1         | Two-pass (count)   | O(N) | O(1)  | Simple, clear logic             |
| 2         | Slow/Fast pointers | O(N) | O(1)  | Best approach (single traversal)|
| 3         | Vector storage     | O(N) | O(N)  | Easy to visualize, not optimal  |

----------------------------------------------------------
💡 INTUITION (Slow & Fast Pointer)
----------------------------------------------------------
- Fast moves twice as fast as slow.
- When fast reaches end, slow reaches the middle.
- Keeping track of the previous node helps us skip the middle node safely.
----------------------------------------------------------
*/

