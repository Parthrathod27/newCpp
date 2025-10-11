// ---------------------------------------------------------------
// 🧩 LeetCode 237. Delete Node in a Linked List
// ---------------------------------------------------------------
// 🔹 Problem:
// We are given *only the node* to delete (not the head of the list).
// The node to be deleted is *not the last node* in the linked list.
// We need to remove this node from the list.
//
// 🔹 Key Trick / Idea:
// Since we don't have access to the previous node,
// we cannot adjust the previous node’s `next` pointer directly.
// Instead, we copy the data from the *next* node into the current node
// and then delete that next node.
//
// 🔹 Example:
// Input:  4 -> 5 -> 1 -> 9 , node = 5
// Steps:
//   1️⃣ Copy value of next node (1) into node (5)
//   2️⃣ Now list looks like: 4 -> 1 -> 1 -> 9
//   3️⃣ Delete the extra "1" (the next node)
// Output: 4 -> 1 -> 9
// ---------------------------------------------------------------

void deleteNode(ListNode* node) {

    // Step 1️⃣: Store the pointer to the next node
    ListNode* nextNode = node->next;

    // Step 2️⃣: Copy the next node's value into the current node
    node->val = nextNode->val;

    // Step 3️⃣: Connect current node to next of nextNode
    // (bypass the next node, effectively deleting it from the chain)
    node->next = nextNode->next;

    // Step 4️⃣: Delete the next node to free memory
    delete nextNode;
}

// ---------------------------------------------------------------
// 🧠 Dry Run Example:
//
// Suppose Linked List = 4 -> 5 -> 1 -> 9
// We are given pointer to node (5)
//
// nextNode = node->next (points to 1)
// node->val = 1          // list becomes 4 -> 1 -> 1 -> 9
// node->next = nextNode->next (bypass the duplicate 1)
// delete nextNode        // removes the extra node
//
// Final List: 4 -> 1 -> 9
// ---------------------------------------------------------------
//
// ✅ Time Complexity: O(1)
// ✅ Space Complexity: O(1)
// ---------------------------------------------------------------

