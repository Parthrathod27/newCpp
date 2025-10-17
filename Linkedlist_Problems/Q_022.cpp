/*
--------------------------------------------
🧠 PROBLEM: Find All Pairs with Given Sum in Doubly Linked List (DLL)
--------------------------------------------

Given a **sorted Doubly Linked List**, and an integer `target`,
we need to find all pairs of nodes whose sum equals the target.

--------------------------------------------
📘 Example:
--------------------------------------------
Input: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9,  target = 7  
Output: (1,6), (2,5)

Explanation:
1+6 = 7 ✅  
2+5 = 7 ✅

--------------------------------------------
💡 APPROACH 1: Brute Force (O(N²))
--------------------------------------------
🔹 Idea:
For each node, check all nodes after it and see if the sum equals the target.

🔹 Steps:
1. Start from each node `i`.
2. Traverse another pointer `j` from `i->next` till end.
3. If (i->data + j->data == target), store that pair.

🔹 Time Complexity → O(N²)
🔹 Space Complexity → O(1)
--------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = NULL;
    }
};

vector<pair<int, int>> findPairsBrute(Node* head, int target) {
    vector<pair<int, int>> ans;
    for (Node* i = head; i != NULL; i = i->next) {
        for (Node* j = i->next; j != NULL; j = j->next) {
            if (i->data + j->data == target)
                ans.push_back({i->data, j->data});
        }
    }
    return ans;
}

/*
--------------------------------------------
💡 APPROACH 2: Two Pointer Approach (Optimal)
--------------------------------------------

🔹 Intuition:
Since DLL is **sorted**, we can use the same two-pointer logic as in arrays.

🔹 Steps:
1. Initialize:
   - `left` = head (start of list)
   - `right` = last node (end of list)

2. Loop while `left != right` and `left->data < right->data`
   - If (left->data + right->data == target) → store pair & move both
   - If sum < target → move left forward
   - If sum > target → move right backward

🔹 Time Complexity → O(N)
🔹 Space Complexity → O(1)
--------------------------------------------
*/

vector<pair<int, int>> findPairs(Node* head, int target) {
    vector<pair<int, int>> ans;

    // Step 1: Find the tail (rightmost node)
    Node* left = head;
    Node* right = head;
    while (right->next != NULL)
        right = right->next;

    // Step 2: Two-pointer traversal
    while (left != right && right->next != left) {
        int sum = left->data + right->data;

        if (sum == target) {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } 
        else if (sum < target)
            left = left->next;
        else
            right = right->prev;
    }

    return ans;
}

/*
--------------------------------------------
✅ PROOF OF CORRECTNESS (for Two Pointer)
--------------------------------------------
1️⃣ Since the list is sorted:
   - Moving `left` forward increases the sum.
   - Moving `right` backward decreases the sum.
2️⃣ We check all combinations exactly once.
3️⃣ Hence, no pairs are missed, and no duplicates are counted.

--------------------------------------------
🧩 Example Walkthrough
--------------------------------------------
List: 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9, target = 7

left = 1, right = 9 → sum = 10 > 7 → move right backward  
left = 1, right = 8 → sum = 9 > 7 → move right backward  
left = 1, right = 6 → sum = 7 ✅ store (1,6)  
left = 2, right = 5 → sum = 7 ✅ store (2,5)  
left = 4, right = 4 ❌ stop  

Output → (1,6), (2,5)
--------------------------------------------
*/

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(8);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(9);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    int target = 7;
    vector<pair<int, int>> res = findPairs(head, target);

    cout << "Pairs with sum " << target << ":\n";
    for (auto &p : res)
        cout << "(" << p.first << "," << p.second << ") ";

    return 0;
}

/*
--------------------------------------------
🧾 SUMMARY
--------------------------------------------
Approach 1: Brute Force → O(N²)
Approach 2: Two Pointer (Optimal) → O(N)
--------------------------------------------
🔥 Recommended: Use Two Pointer for sorted DLL.
--------------------------------------------
*/

