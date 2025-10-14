/*
💡 Problem: Find the Middle Element of a Linked List

You are given the head of a singly linked list.
Your task is to return the middle node of the linked list.

If there are two middle nodes (even number of nodes),
return the **second** middle node.

Example:
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 3

Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 4
*/

/*
-------------------------------------------------------
Approach 1: Brute Force (Using Length Count)  ✅
-------------------------------------------------------
🔹 Idea:
First, count the total number of nodes (n).
Then, traverse again to the (n/2)th node and return it.

🔹 Steps:
1. Initialize a counter = 0 and traverse the list to find total length.
2. Again traverse till counter == n/2.
3. Return that node as the middle node.

🔹 Example:
For list: 1 -> 2 -> 3 -> 4 -> 5
Total length = 5 → middle = 5/2 = 2 (0-based indexing)
Middle element = 3

🔹 Time Complexity: O(2N)
🔹 Space Complexity: O(1)
*/

class Solution_Brute {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* temp = head;

        // Step 1: Count total nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: Move till middle
        int mid = count / 2;
        temp = head;
        for (int i = 0; i < mid; i++) {
            temp = temp->next;
        }

        return temp; // middle node
    }
};

/*
-------------------------------------------------------
Approach 2: Better (Store Nodes in a Vector)  ✅
-------------------------------------------------------
🔹 Idea:
Store all nodes in a vector, then directly access the middle using index.

🔹 Steps:
1. Create a vector of ListNode*.
2. Traverse the list and push all nodes into the vector.
3. Return vector[size/2] as middle node.

🔹 Time Complexity: O(N)
🔹 Space Complexity: O(N)
*/

#include <vector>

class Solution_Better {
public:
    ListNode* middleNode(ListNode* head) {
        std::vector<ListNode*> arr;
        ListNode* temp = head;

        // Store all nodes in array
        while (temp != NULL) {
            arr.push_back(temp);
            temp = temp->next;
        }

        // Return middle node
        return arr[arr.size() / 2];
    }
};

/*
-------------------------------------------------------
Approach 3: Optimal (Slow & Fast Pointer)  🚀
-------------------------------------------------------
🔹 Idea:
Use two pointers — slow and fast.
Slow moves 1 step at a time, Fast moves 2 steps.
When fast reaches the end, slow will be at the middle.

🔹 Intuition:
Fast pointer moves twice as quickly as slow.
So when fast finishes, slow will be halfway.

🔹 Steps:
1. Initialize slow = head, fast = head.
2. Move fast = fast->next->next and slow = slow->next.
3. Stop when fast == NULL or fast->next == NULL.
4. Return slow.

🔹 Example:
For list: 1 -> 2 -> 3 -> 4 -> 5
Iterations:
fast moves: 1→3→5
slow moves: 1→2→3
So middle = 3

🔹 Time Complexity: O(N)
🔹 Space Complexity: O(1)
*/

class Solution_Optimal {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // middle node
    }
};

/*
-------------------------------------------------------
🔹 Summary:
-------------------------------------------------------
✅ Brute Force → O(2N) time, O(1) space  
✅ Better (Vector) → O(N) time, O(N) space  
✅ Optimal (Two Pointers) → O(N) time, O(1) space  ← BEST APPROACH

📘 Tip:
This “slow and fast pointer” method is a fundamental pattern for Linked List problems like:
- Detect cycle
- Find intersection
- Split list into halves
*/


