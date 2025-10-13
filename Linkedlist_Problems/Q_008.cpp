// ✅ Approach 1: Brute Force (Two Traversals)
// Time Complexity: O(2N)
// Space Complexity: O(1)
// Idea: 
// 1️⃣ First pass → find total length of linked list.
// 2️⃣ Second pass → delete (length - n)th node from start.

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Base case: if list is empty
        if (head == nullptr) return nullptr;

        // Step 1️⃣: Find total length of list
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Step 2️⃣: If the node to delete is the head itself
        if (n == length) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 3️⃣: Traverse to the node before the one we need to delete
        int pos = length - n;
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }

        // Step 4️⃣: Delete target node
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;

        // Step 5️⃣: Return updated head
        return head;
    }
};


// ✅ Approach 2: Optimal (Single Traversal using Two Pointers)
// Time Complexity: O(N)
// Space Complexity: O(1)
// Idea:
// Use two pointers: 'fast' and 'slow'.
// Move 'fast' pointer n steps ahead first.
// Then move both 'fast' and 'slow' together until 'fast' reaches the end.
// Now 'slow' is just before the node that needs to be deleted.

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1️⃣: Create a dummy node to handle edge cases easily (like removing the head)
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // Step 2️⃣: Initialize two pointers
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Step 3️⃣: Move 'fast' n+1 steps ahead so that the gap between fast & slow is 'n'
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Step 4️⃣: Move both pointers until fast reaches the end
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 5️⃣: Now, 'slow->next' is the node to delete
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;

        // Step 6️⃣: Return updated head (skipping dummy)
        ListNode* newHead = dummy->next;
        delete dummy;

        return newHead;
    }
};



// ✅ Approach 3: Stack Method
// Time Complexity: O(N)
// Space Complexity: O(N)
// Idea:
// Push all nodes into a stack.
// Pop n nodes → the top node now is the one before the node to delete.

#include <stack>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1️⃣: Create dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // Step 2️⃣: Push all nodes onto a stack
        std::stack<ListNode*> st;
        ListNode* temp = dummy;
        while (temp != nullptr) {
            st.push(temp);
            temp = temp->next;
        }

        // Step 3️⃣: Pop n nodes to reach node before the one to remove
        for (int i = 0; i < n; i++) {
            st.pop();
        }

        // Step 4️⃣: The node on top is just before the one we delete
        ListNode* prev = st.top();
        ListNode* delNode = prev->next;
        prev->next = prev->next->next;

        delete delNode;

        // Step 5️⃣: Return new head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

