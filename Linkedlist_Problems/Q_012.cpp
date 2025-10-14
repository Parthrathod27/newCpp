/*
💡 Problem: Find the intersection point of two Y-shaped Linked Lists.

You are given the heads of two singly linked lists that merge at some point (Y-shaped).
You need to find the node (address) where both lists intersect.

Example:
List A: 1 -> 2 -> 3
                     \
                      6 -> 7 -> NULL
                     /
List B:      4 -> 5

Output: 6 (since node with value 6 is the intersection point)
*/

/*
-----------------------------------------------
Approach 1: Brute Force (O(N*M) Time, O(1) Space)
-----------------------------------------------
🔹 Idea:
For every node in list A, traverse the entire list B and check if any node is same (by address).
If a match is found, that’s the intersection node.

🔹 Intuition:
Two lists intersect when they share the same node (not just same value, but same memory address).

🔹 Steps:
1. Take one pointer for list A (temp1).
2. For each node of A, traverse the entire list B (temp2).
3. If temp1 == temp2 → intersection found.
4. If not found till end, return NULL.

🔹 Time Complexity: O(N*M)
🔹 Space Complexity: O(1)
*/

ListNode* getIntersectionNode_Brute(ListNode* headA, ListNode* headB) {
    for (ListNode* temp1 = headA; temp1 != NULL; temp1 = temp1->next) {
        for (ListNode* temp2 = headB; temp2 != NULL; temp2 = temp2->next) {
            if (temp1 == temp2) return temp1; // Intersection found
        }
    }
    return NULL; // No intersection
}

/*
-----------------------------------------------
Approach 2: Better Approach using Hashing (O(N+M) Time, O(N) Space)
-----------------------------------------------
🔹 Idea:
Store the addresses of all nodes of the first list in a hash set.
Then, traverse the second list and check if any node exists in the set.

🔹 Steps:
1. Traverse list A, store each node address in a set.
2. Traverse list B, check if any node exists in the set.
3. If found → that’s the intersection node.
4. Else return NULL.

🔹 Time Complexity: O(N + M)
🔹 Space Complexity: O(N)
*/

#include <unordered_set>
ListNode* getIntersectionNode_Better(ListNode* headA, ListNode* headB) {
    unordered_set<ListNode*> seen;
    ListNode* temp = headA;

    // Store all nodes of list A
    while (temp != NULL) {
        seen.insert(temp);
        temp = temp->next;
    }

    // Check nodes of list B
    temp = headB;
    while (temp != NULL) {
        if (seen.find(temp) != seen.end()) return temp; // Intersection found
        temp = temp->next;
    }

    return NULL; // No intersection
}

/*
-----------------------------------------------
Approach 3: Optimal Two Pointer Method (O(N+M) Time, O(1) Space)
-----------------------------------------------
🔹 Idea:
Use two pointers — one on each list. 
When a pointer reaches the end of its list, redirect it to the start of the other list.
If the lists intersect, both pointers will meet at the intersection node after at most (lenA + lenB) steps.

🔹 Intuition:
By switching heads, both pointers traverse equal total lengths before meeting.

🔹 Steps:
1. Initialize two pointers: a = headA, b = headB.
2. Move both pointers one step at a time.
3. When a reaches NULL, move it to headB.
   When b reaches NULL, move it to headA.
4. Continue until a == b.
5. Return a (which is either intersection node or NULL).

🔹 Time Complexity: O(N + M)
🔹 Space Complexity: O(1)
*/

ListNode* getIntersectionNode_Optimal(ListNode* headA, ListNode* headB) {
    if (headA == NULL || headB == NULL) return NULL;

    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
        a = (a == NULL) ? headB : a->next;
        b = (b == NULL) ? headA : b->next;
    }

    return a; // either intersection node or NULL
}

/*
-----------------------------------------------
🔹 Summary:
-----------------------------------------------
✅ Brute Force → O(N*M) time, O(1) space
✅ Better (Hashing) → O(N+M) time, O(N) space
✅ Optimal (Two Pointer) → O(N+M) time, O(1) space  ← BEST APPROACH

📘 Tip:
The optimal two-pointer technique is widely used in Linked List problems
(like cycle detection, intersection, merging points, etc.)
*/


