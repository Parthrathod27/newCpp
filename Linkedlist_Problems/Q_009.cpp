// Definition for singly linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
===========================================
 APPROACH 1: BRUTE FORCE (Using a vector)
===========================================

🔹 Intuition:
- Traverse the linked list and store all values in a vector.
- Then, traverse the list again and copy values back in reverse order.

🔹 Time Complexity: O(2N)
🔹 Space Complexity: O(N)
*/

ListNode* reverseList_brute(ListNode* head) {
    if (!head || !head->next) return head;

    vector<int> arr;
    ListNode* temp = head;

    // Step 1: Store all node values in a vector
    while (temp != nullptr) {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    // Step 2: Copy values back in reverse order
    temp = head;
    int i = arr.size() - 1;
    while (temp != nullptr) {
        temp->val = arr[i--];
        temp = temp->next;
    }

    return head;
}

/*
===========================================
 APPROACH 2: OPTIMAL (Iterative Method)
===========================================

🔹 Intuition:
- We will change the next pointers of each node to point backward.
- Keep track of 3 pointers: `prev`, `curr`, and `next`.

🔹 Steps:
1️⃣ Initialize prev = NULL, curr = head.
2️⃣ Loop while curr != NULL:
    - Store next = curr->next
    - Reverse link: curr->next = prev
    - Move prev = curr, curr = next
3️⃣ Return prev as the new head.

🔹 Time Complexity: O(N)
🔹 Space Complexity: O(1)
*/

ListNode* reverseList_iterative(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* next = curr->next;  // store next node
        curr->next = prev;            // reverse link
        prev = curr;                  // move prev forward
        curr = next;                  // move curr forward
    }

    return prev; // new head after reversal
}

/*
===========================================
 APPROACH 3: RECURSIVE METHOD
===========================================

🔹 Intuition:
- Use recursion to reach the end of the list.
- While coming back from recursion, reverse the links.

🔹 Steps:
1️⃣ Base case: if head is NULL or head->next is NULL, return head.
2️⃣ Recursively call reverseList on head->next.
3️⃣ Reverse the link using:
        head->next->next = head
        head->next = NULL
4️⃣ Return newHead (returned from recursion).

🔹 Time Complexity: O(N)
🔹 Space Complexity: O(N) (due to recursion stack)
*/

ListNode* reverseList_recursive(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode* newHead = reverseList_recursive(head->next);

    head->next->next = head;  // reverse link
    head->next = nullptr;     // set tail next to null

    return newHead;
}

