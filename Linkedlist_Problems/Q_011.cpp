//----------------------------------------------------
// Definition for singly-linked list node
//----------------------------------------------------
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//====================================================
// 🧩 APPROACH 1: Reverse + Add + Reverse Back (Brute)
//====================================================
/*
  🔹 IDEA:
  - Since the least significant digit (LSD) is at the end of the list,
    we reverse the list first to make addition easy.
  - Add 1 to the first node (which was last in original list).
  - Manage carry as we move forward.
  - If carry still remains after traversal → add new node.
  - Finally reverse the list again to restore original order.

  🔹 TIME COMPLEXITY: O(N)
  🔹 SPACE COMPLEXITY: O(1)
*/

// Helper function to reverse the linked list
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

ListNode* addOneBrute(ListNode* head) {
    // Step 1: Reverse the list
    head = reverseList(head);

    // Step 2: Add 1 to the head (now LSD)
    ListNode* temp = head;
    int carry = 1;
    while (temp != nullptr && carry > 0) {
        int sum = temp->val + carry;
        temp->val = sum % 10;
        carry = sum / 10;

        // Move ahead if next node exists
        if (temp->next == nullptr && carry) {
            temp->next = new ListNode(carry);
            carry = 0;
        }
        temp = temp->next;
    }

    // Step 3: Reverse back the list
    head = reverseList(head);
    return head;
}

//====================================================
// ⚡ APPROACH 2: Optimal Recursive Approach
//====================================================
/*
  🔹 IDEA:
  - Traverse to the end recursively (reach least significant digit).
  - Add 1 to the last node and propagate carry backward during recursion.
  - Update node values as recursion unwinds.
  - If carry remains at the end → create a new head node with carry.

  🔹 TIME COMPLEXITY: O(N)
  🔹 SPACE COMPLEXITY: O(N) due to recursion stack
  🔹 Elegant & clean solution (no explicit reverse)
*/

int addOneRecursiveHelper(ListNode* head) {
    // Base case: if null, return carry = 1 (to add one)
    if (head == nullptr) return 1;

    // Recursive call to reach the last node
    int carry = addOneRecursiveHelper(head->next);

    // Add carry to current node
    int sum = head->val + carry;
    head->val = sum % 10;
    return sum / 10; // Return new carry
}

ListNode* addOneOptimal(ListNode* head) {
    // Step 1: Start recursion from head
    int carry = addOneRecursiveHelper(head);

    // Step 2: If carry remains, add new node at beginning
    if (carry) {
        ListNode* newHead = new ListNode(carry);
        newHead->next = head;
        return newHead;
    }
    return head;
}
