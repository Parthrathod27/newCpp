/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // -------------------------------//
    // 🧠 APPROACH 1 — Using Vector
    // -------------------------------//
    // Time: O(N)  |  Space: O(N)
    // Idea:
    // 1. Traverse the linked list and store odd index values first, then even index values in a vector.
    // 2. Traverse the linked list again and overwrite node values from that vector.
    // 3. This changes only values, not node links (less efficient but simple).
    ListNode* oddEvenList(ListNode* head) {
        // If list has 0 or 1 node, no change needed
        if (head == nullptr || head->next == nullptr) return head;

        vector<int> arr; // to store node values

        ListNode* temp = head;
        int index = 1; // positions start from 1 (odd/even based on index)

        // First loop → store odd index values
        while (temp != nullptr) {
            if (index % 2 != 0) arr.push_back(temp->val);
            temp = temp->next;
            index++;
        }

        // Second loop → store even index values
        temp = head;
        index = 1;
        while (temp != nullptr) {
            if (index % 2 == 0) arr.push_back(temp->val);
            temp = temp->next;
            index++;
        }

        // Third loop → rewrite values from arr into linked list
        temp = head;
        int i = 0;
        while (temp != nullptr) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    // -----------------------------------//
    // ⚡ APPROACH 2 — Optimal In-place
    // -----------------------------------//
    // Time: O(N)  |  Space: O(1)
    // Idea:
    // - Use two pointers: one for odd nodes and one for even nodes.
    // - Rearrange the next pointers directly (no need for extra space).
    // - Finally, link the end of odd list to the start of even list.
    ListNode* oddEvenList(ListNode* head) {
        // Edge cases: 0 or 1 node
        if (head == nullptr || head->next == nullptr) return head;

        // Pointers for odd and even positions
        ListNode* odd = head;           // points to 1st node
        ListNode* even = head->next;    // points to 2nd node
        ListNode* evenHead = even;      // store head of even nodes (to connect later)

        // Rearrange nodes while maintaining relative order
        while (even != nullptr && even->next != nullptr) {
            // Connect odd node to the next odd node
            odd->next = even->next;
            odd = odd->next;

            // Connect even node to the next even node
            even->next = odd->next;
            even = even->next;
        }

        // After all connections, attach even list to the end of odd list
        odd->next = evenHead;

        // Return modified head
        return head;
    }
};

