/*
--------------------------------------------
🧠 PROBLEM: Reverse Nodes in K Group (LeetCode #25)
--------------------------------------------

Given the head of a linked list, reverse the nodes of the list 
k at a time, and return the modified list.

If the number of nodes is not a multiple of k, 
leave the last remaining nodes as it is.

--------------------------------------------
📘 Example:
--------------------------------------------
Input: head = [1,2,3,4,5], k = 2  
Output: [2,1,4,3,5]

Input: head = [1,2,3,4,5], k = 3  
Output: [3,2,1,4,5]

--------------------------------------------
💡 INTUITION:
--------------------------------------------
We want to reverse every group of size K in the linked list.
Example (k = 3):
1 → 2 → 3 → 4 → 5 → 6 → 7  
→ (3,2,1) (6,5,4) 7 (remains same if < k)

--------------------------------------------
🧩 APPROACH 1: BRUTE FORCE (Using Array)
--------------------------------------------

🔹 Idea:
1️⃣ Traverse the linked list and store all node values in a vector.
2️⃣ Then reverse every K-sized block in that vector.
3️⃣ Create a new linked list from the modified array.

🔹 Time Complexity → O(N)
🔹 Space Complexity → O(N)
⚠️ Not in-place (uses extra memory)
--------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroupBrute(ListNode* head, int k) {
    if (!head || k <= 1) return head;

    vector<int> arr;
    ListNode* temp = head;

    // Step 1: Store all values in array
    while (temp) {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    // Step 2: Reverse every group of k
    for (int i = 0; i + k <= arr.size(); i += k)
        reverse(arr.begin() + i, arr.begin() + i + k);

    // Step 3: Copy values back to linked list
    temp = head;
    int idx = 0;
    while (temp) {
        temp->val = arr[idx++];
        temp = temp->next;
    }

    return head;
}

/*
--------------------------------------------
🧠 APPROACH 2: OPTIMAL (In-Place Reversal)
--------------------------------------------

🔹 Idea:
Reverse the nodes directly in the linked list, k at a time,
without using any extra data structure.

--------------------------------------------
🔹 STEPS:
--------------------------------------------
1️⃣ Count total nodes.  
2️⃣ While at least k nodes remain:
    - Reverse next k nodes.
    - Connect the reversed part with the previous section.
3️⃣ Stop when remaining nodes < k.

--------------------------------------------
🔹 TIME COMPLEXITY → O(N)
🔹 SPACE COMPLEXITY → O(1)
--------------------------------------------
*/

int getLength(ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k == 1) return head;

    int length = getLength(head);

    // Dummy node to simplify connection logic
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* prevGroupEnd = dummy;
    ListNode* curr = head;
    ListNode* nextNode = NULL;

    while (length >= k) {
        ListNode* groupStart = curr;
        ListNode* prev = NULL;

        // Reverse k nodes
        for (int i = 0; i < k; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Connect reversed part with the rest
        prevGroupEnd->next = prev;  // 'prev' is now new head of this group
        groupStart->next = curr;    // 'curr' is start of next group
        prevGroupEnd = groupStart;  // Move to end of current group

        length -= k;
    }

    return dummy->next;
}

/*
--------------------------------------------
🧩 DRY RUN EXAMPLE
--------------------------------------------
Input: 1 → 2 → 3 → 4 → 5, k = 2

Step 1: Reverse first 2 → (2 → 1)
Step 2: Reverse next 2 → (4 → 3)
Step 3: Remaining 5 < k → keep same

Output: 2 → 1 → 4 → 3 → 5 ✅

--------------------------------------------
✅ PROOF OF CORRECTNESS:
--------------------------------------------
- Each group of size K is reversed in-place.
- Connections are handled by dummy node for simplicity.
- No extra memory used beyond a few pointers.

--------------------------------------------
*/

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create LinkedList: 1->2->3->4->5->6->7
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = new ListNode(7);

    int k = 3;

    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in K Group: ";
    printList(head);

    return 0;
}

/*
--------------------------------------------
🧾 SUMMARY
--------------------------------------------
Approach 1: Using Array → O(N), O(N)
Approach 2: In-Place Reversal → O(N), O(1) ✅ (Best)

🔥 Recommended: Approach 2 — Efficient and clean pointer manipulation.
--------------------------------------------
*/

