//---------------------------------------------
// Definition of the singly linked list node
//---------------------------------------------
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//==============================================================
// 🧩 APPROACH 1: Using Vector (Brute Force)
//==============================================================
/*
  🔹 IDEA:
  - Traverse the linked list and store all node values in a vector.
  - Use two pointers (i = 0, j = n-1) to compare elements from both ends.
  - If all elements match, it’s a palindrome; otherwise, not.

  🔹 TIME COMPLEXITY: O(N)
  🔹 SPACE COMPLEXITY: O(N)
  🔹 SIMPLE but uses extra space.
*/

bool isPalindromeBrute(ListNode* head) {
    vector<int> arr;

    // Step 1: Store all node values into a vector
    ListNode* temp = head;
    while (temp != nullptr) {
        arr.push_back(temp->val);
        temp = temp->next;
    }

    // Step 2: Use two-pointer method to check palindrome
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        if (arr[i] != arr[j]) return false;  // Not a palindrome
        i++;
        j--;
    }

    // Step 3: If all matched
    return true;
}

//==============================================================
// 🧠 APPROACH 2: Optimal In-place (O(1) Space)
//==============================================================
/*
  🔹 IDEA:
  - Use slow and fast pointers to find the middle of the linked list.
  - Reverse the second half of the list.
  - Compare the first half and reversed second half node by node.
  - If all nodes match → Palindrome.
  - (Optional) Reverse the second half again to restore original list.

  🔹 TIME COMPLEXITY: O(N)
  🔹 SPACE COMPLEXITY: O(1)
  🔹 MOST OPTIMAL APPROACH used in interviews.
*/

// Helper function to reverse a linked list
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

// Main function to check palindrome using optimal approach
bool isPalindromeOptimal(ListNode* head) {
    if (!head || !head->next) return true;  // Single node or empty → palindrome

    // Step 1: Find the middle of the linked list using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the linked list
    slow->next = reverseList(slow->next);

    // Step 3: Compare both halves
    ListNode* first = head;
    ListNode* second = slow->next;
    while (second != nullptr) {
        if (first->val != second->val) return false;  // Mismatch found
        first = first->next;
        second = second->next;
    }

    // Step 4: (Optional) Reverse back second half to restore original structure
    slow->next = reverseList(slow->next);

    // Step 5: If all matched, it’s a palindrome
    return true;
}

