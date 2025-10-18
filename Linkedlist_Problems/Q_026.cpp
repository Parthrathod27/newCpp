/*
--------------------------------------------
🧠 PROBLEM: Merge Two Sorted Linked Lists (LeetCode #21)
--------------------------------------------

Given two sorted linked lists, merge them into one sorted linked list and return the head of the merged list.

--------------------------------------------
📘 Example:
--------------------------------------------
Input:
list1 = [1,2,4]
list2 = [1,3,4]

Output:
[1,1,2,3,4,4]

--------------------------------------------
💡 INTUITION:
--------------------------------------------
Since both lists are already sorted, we can merge them
similar to the “merge” step of Merge Sort.
We’ll compare the nodes one by one and build a sorted merged list.

--------------------------------------------
🧩 Visualization:
--------------------------------------------
list1: 1 → 2 → 4
list2: 1 → 3 → 4

Merged: 1 → 1 → 2 → 3 → 4 → 4
--------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Linked list structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
--------------------------------------------
🪜 APPROACH 1: Brute Force (Using Array or Vector)
--------------------------------------------

🔹 Idea:
1️⃣ Store all values from both linked lists in a vector.
2️⃣ Sort the vector.
3️⃣ Build a new linked list from sorted values.

🔹 Time Complexity → O((n+m) log(n+m)) because of sorting
🔹 Space Complexity → O(n+m) (for vector storage)
--------------------------------------------
*/

ListNode* mergeTwoListsBrute(ListNode* list1, ListNode* list2) {
    vector<int> arr;

    // Step 1: Push all elements into array
    while(list1) {
        arr.push_back(list1->val);
        list1 = list1->next;
    }
    while(list2) {
        arr.push_back(list2->val);
        list2 = list2->next;
    }

    // Step 2: Sort the combined array
    sort(arr.begin(), arr.end());

    // Step 3: Build a new sorted linked list
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    for(int val : arr) {
        temp->next = new ListNode(val);
        temp = temp->next;
    }

    return dummy->next;
}

/*
--------------------------------------------
⚡ APPROACH 2: Optimal (Two-Pointer Merge)
--------------------------------------------

🔹 Idea:
Use two pointers (like in merge step of merge sort).

Steps:
1️⃣ Initialize a dummy node to build result.
2️⃣ Compare values of list1 and list2.
3️⃣ Append the smaller node to the result.
4️⃣ Move that list’s pointer forward.
5️⃣ Continue until both lists are exhausted.

🔹 Time Complexity → O(n + m)
🔹 Space Complexity → O(1)
✅ This is the most efficient approach.
--------------------------------------------
*/

ListNode* mergeTwoListsOptimal(ListNode* list1, ListNode* list2) {
    // Create a dummy node to start the merged list
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    // Step 1: Traverse both lists
    while(list1 != NULL && list2 != NULL) {
        if(list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    // Step 2: Attach remaining nodes
    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummy->next;
}

/*
--------------------------------------------
🧩 DRY RUN EXAMPLE
--------------------------------------------
list1 = 1 → 2 → 4
list2 = 1 → 3 → 4

Step 1: Compare 1 & 1 → pick any → merged = 1
Step 2: Compare 2 & 3 → pick 2 → merged = 1→1→2
Step 3: Compare 4 & 3 → pick 3 → merged = 1→1→2→3
Step 4: Compare 4 & 4 → pick any → merged = 1→1→2→3→4→4
--------------------------------------------
✅ Output: [1,1,2,3,4,4]
--------------------------------------------
*/

void printList(ListNode* head) {
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create first sorted list: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Create second sorted list: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    // Merge using optimal approach
    ListNode* merged = mergeTwoListsOptimal(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}

/*
--------------------------------------------
🧾 SUMMARY
--------------------------------------------
Approach 1: Brute Force (Vector + Sort)
    🔹 Time: O((n+m) log(n+m))
    🔹 Space: O(n+m)
    ⚠️ Simple but not memory efficient.

Approach 2: Optimal (Two Pointer)
    🔹 Time: O(n+m)
    🔹 Space: O(1)
    ✅ Best approach for interviews.

🔥 Key Takeaway:
Always try to reuse existing nodes instead of creating new ones.
--------------------------------------------
*/

