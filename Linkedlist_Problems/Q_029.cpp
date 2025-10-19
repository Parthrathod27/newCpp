/*
------------------------------------------------------------
🧠 PROBLEM: Sort a Linked List
------------------------------------------------------------
You are given the head of a singly linked list.  
Sort the list in ascending order and return the sorted list.

------------------------------------------------------------
📘 Example:
------------------------------------------------------------
Input:  4 -> 2 -> 1 -> 3
Output: 1 -> 2 -> 3 -> 4

------------------------------------------------------------
💡 INTUITION:
------------------------------------------------------------
We need to sort nodes of a linked list.  
Unlike arrays, we cannot access elements randomly — only sequentially.  
So we must use approaches suited for linked list traversal.

We’ll see two main approaches:
1️⃣ Brute Force (Using Extra Space)
2️⃣ Merge Sort (Optimal In-Place Linked List Sort)
------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

/*
------------------------------------------------------------
🧩 STRUCTURE DEFINITION
------------------------------------------------------------
*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
------------------------------------------------------------
🪜 APPROACH 1: Brute Force Using Extra Space
------------------------------------------------------------
🔹 IDEA:
- Traverse the linked list and store all node values in a vector.
- Sort the vector.
- Reassign the sorted values back to the linked list nodes.

------------------------------------------------------------
🔹 STEPS:
------------------------------------------------------------
1️⃣ Traverse the linked list and push all values into a vector.
2️⃣ Sort the vector using built-in sort().
3️⃣ Traverse the list again and replace node values with sorted ones.

------------------------------------------------------------
⏱️ Time Complexity: O(N log N)
🧠 Space Complexity: O(N) → uses vector
------------------------------------------------------------
*/

ListNode* sortList_BruteForce(ListNode* head) {
    if (!head || !head->next) return head;

    vector<int> vals;
    ListNode* temp = head;

    // Step 1: Store values
    while (temp) {
        vals.push_back(temp->val);
        temp = temp->next;
    }

    // Step 2: Sort values
    sort(vals.begin(), vals.end());

    // Step 3: Replace node values
    temp = head;
    for (int v : vals) {
        temp->val = v;
        temp = temp->next;
    }

    return head;
}

/*
------------------------------------------------------------
🪜 APPROACH 2: Merge Sort on Linked List (Optimal)
------------------------------------------------------------
🔹 IDEA:
Merge Sort works great for linked lists because:
✅ We can easily split the list into halves using slow/fast pointers.
✅ Merging two sorted lists is efficient.

------------------------------------------------------------
🔹 STEPS:
------------------------------------------------------------
1️⃣ Use the "slow and fast pointer" technique to find the middle node.
2️⃣ Split the list into two halves.
3️⃣ Recursively sort both halves.
4️⃣ Merge both sorted halves into one sorted list.

------------------------------------------------------------
⏱️ Time Complexity: O(N log N)
🧠 Space Complexity: O(log N) (due to recursion)
------------------------------------------------------------
*/

// Helper function to merge two sorted linked lists
ListNode* merge(ListNode* left, ListNode* right) {
    if (!left) return right;
    if (!right) return left;

    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (left && right) {
        if (left->val < right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if (left) tail->next = left;
    if (right) tail->next = right;

    return dummy->next;
}

// Helper function to find the middle of a linked list
ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Main merge sort function
ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) return head;

    // Step 1: Find middle node
    ListNode* mid = findMiddle(head);

    // Step 2: Split the list
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = nullptr;

    // Step 3: Sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Step 4: Merge sorted halves
    return merge(left, right);
}

/*
------------------------------------------------------------
🧩 DRIVER FUNCTION FOR MERGE SORT APPROACH
------------------------------------------------------------
*/
ListNode* sortList_MergeSort(ListNode* head) {
    return mergeSort(head);
}

/*
------------------------------------------------------------
🧪 DRY RUN EXAMPLE:
------------------------------------------------------------
Input: 4 -> 2 -> 1 -> 3

Step 1: Split into two halves:
    Left: 4 -> 2
    Right: 1 -> 3

Step 2: Recursively split:
    Left1: 4
    Left2: 2
    Right1: 1
    Right2: 3

Step 3: Merge sorted halves:
    Merge(4,2) → 2 -> 4
    Merge(1,3) → 1 -> 3

Step 4: Merge(2->4, 1->3) → 1 -> 2 -> 3 -> 4

Output: 1 -> 2 -> 3 -> 4
------------------------------------------------------------
*/

/*
------------------------------------------------------------
📋 SUMMARY
------------------------------------------------------------
🔹 Approach 1: Brute Force
    - Easy to implement
    - Uses extra space (O(N))
    - ⏱ O(N log N), 🧠 O(N)

🔹 Approach 2: Merge Sort
    - In-place sorting (no extra space for values)
    - Efficient for large linked lists
    - ⏱ O(N log N), 🧠 O(log N)

🔥 Best Approach → Merge Sort (Optimal for Linked Lists)
------------------------------------------------------------
*/

// Helper function to print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example usage:
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));

    cout << "Original List: ";
    printList(head);

    // Uncomment the desired approach:

    // Brute Force
    // head = sortList_BruteForce(head);

    // Merge Sort
    head = sortList_MergeSort(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}

