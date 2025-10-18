\/*
--------------------------------------------
🧠 PROBLEM: Rotate a LinkedList (LeetCode #61)
--------------------------------------------

Given the head of a linked list, rotate the list to the right by k places.

--------------------------------------------
📘 Example:
--------------------------------------------
Input: head = [1,2,3,4,5], k = 2  
Output: [4,5,1,2,3]

Explanation:
- Rotate once → [5,1,2,3,4]
- Rotate twice → [4,5,1,2,3]

--------------------------------------------
💡 INTUITION:
--------------------------------------------
Rotating a linked list means taking the last k nodes 
and moving them to the front while maintaining order.

--------------------------------------------
🧩 Example Visualization
--------------------------------------------
Original: 1 → 2 → 3 → 4 → 5  
Rotate by 2 → 4 → 5 → 1 → 2 → 3  
--------------------------------------------
*/


#include <bits/stdc++.h>
using namespace std;

// Linked List structure
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
--------------------------------------------
🪜 APPROACH 1: Brute Force
--------------------------------------------

🔹 Idea:
Rotate the linked list one step at a time, k times.

Steps:
1️⃣ Find the last node.
2️⃣ Move it to the front.
3️⃣ Repeat k times.

🔹 Time Complexity → O(N * K)
🔹 Space Complexity → O(1)
⚠️ Not efficient for large k.
--------------------------------------------
*/

ListNode* rotateRightBrute(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    int len = 0;
    ListNode* temp = head;

    // Step 1: Find length of list
    while (temp) {
        len++;
        temp = temp->next;
    }

    k = k % len; // Handle cases where k > len
    if (k == 0) return head;

    // Step 2: Perform rotation k times
    for (int i = 0; i < k; i++) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        // Move to last node
        while (curr->next) {
            prev = curr;
            curr = curr->next;
        }

        // Move last node to front
        curr->next = head;
        prev->next = NULL;
        head = curr;
    }

    return head;
}

/*
--------------------------------------------
⚡ APPROACH 2: Optimal (Efficient Approach)
--------------------------------------------

🔹 Idea:
Use length and make the list circular temporarily.

Steps:
1️⃣ Count total nodes.
2️⃣ Connect last node → head (make it circular).
3️⃣ Find new head after (len - k % len) steps.
4️⃣ Break the circular connection.

🔹 Time Complexity → O(N)
🔹 Space Complexity → O(1)
✅ Efficient and clean approach.
--------------------------------------------
*/

ListNode* rotateRightOptimal(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Step 1: Count total nodes
    int len = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        len++;
    }

    // Step 2: Make it circular
    tail->next = head;

    // Step 3: Find new head position
    k = k % len; // Handle large k
    int stepsToNewHead = len - k;

    // Step 4: Move to the new head and break circle
    ListNode* newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }

    ListNode* newHead = newTail->next;
    newTail->next = NULL; // break circular connection

    return newHead;
}

/*
--------------------------------------------
🧩 DRY RUN EXAMPLE
--------------------------------------------
Input: head = [1,2,3,4,5], k = 2

Step 1: Make circular → 1 → 2 → 3 → 4 → 5 → (back to 1)
Step 2: len = 5, stepsToNewHead = 5 - (2 % 5) = 3
Step 3: Move 3 steps → newTail = node 3, newHead = node 4
Step 4: Break circle at node 3

✅ Output: 4 → 5 → 1 → 2 → 3
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
    // Create LinkedList: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    cout << "Original List: ";
    printList(head);

    // Call optimal rotation
    head = rotateRightOptimal(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}

/*
--------------------------------------------
🧾 SUMMARY
--------------------------------------------
Approach 1: Brute Force (Rotate one by one)
    🔹 Time: O(N * K)
    🔹 Space: O(1)

Approach 2: Optimal (Make circular + Break)
    🔹 Time: O(N)
    🔹 Space: O(1)
    ✅ Recommended for interviews.

🔥 Key Takeaway:
Connecting the list circularly makes rotation simple and elegant!
--------------------------------------------
*/

