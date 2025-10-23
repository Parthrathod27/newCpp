#include <bits/stdc++.h>
using namespace std;

/*
----------------------------------------------
💡 PROBLEM: Clone a Linked List with Next and Random Pointers
----------------------------------------------
You are given a linked list where each node has two pointers:
1️⃣ next – points to the next node in the list
2️⃣ random – points to any node in the list (or NULL)

Your task is to create a deep copy (clone) of the list such that
both next and random pointers are correctly replicated.

----------------------------------------------
🧠 EXAMPLE:
----------------------------------------------
Original list:
1 -> 2 -> 3 -> 4 -> NULL
Random links:
1.random -> 3
2.random -> 1
3.random -> 4
4.random -> 2

Cloned list (independent copy):
1' -> 2' -> 3' -> 4' -> NULL
Random links:
1'.random -> 3'
2'.random -> 1'
3'.random -> 4'
4'.random -> 2'

----------------------------------------------
📘 APPROACH 1: Using HashMap (Brute Force)
----------------------------------------------
🪄 IDEA:
- Use a map to store the mapping of original node -> cloned node.
- First pass: Create clone nodes (next pointers only) and store mapping.
- Second pass: Assign random pointers using the map.

🧩 STEPS:
1. Traverse original list, create new nodes for each, and map them.
2. Traverse again, set:
   - clone->next = map[original->next]
   - clone->random = map[original->random]
3. Return the cloned head (map[head]).

🧮 TIME: O(N)
🧮 SPACE: O(N) (for the map)
*/

class Node {
public:
    int data;
    Node* next;
    Node* random;
    Node(int d) {
        data = d;
        next = random = NULL;
    }
};

// ✅ APPROACH 1: Using HashMap
Node* cloneLinkedList_HashMap(Node* head) {
    if (!head) return NULL;

    unordered_map<Node*, Node*> mp;
    Node* temp = head;

    // Step 1: Create clone nodes and store in map
    while (temp) {
        mp[temp] = new Node(temp->data);
        temp = temp->next;
    }

    temp = head;
    // Step 2: Connect next and random using map
    while (temp) {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    // Step 3: Return the cloned head
    return mp[head];
}

/*
----------------------------------------------
📘 APPROACH 2: Optimized (Without Extra Space)
----------------------------------------------
🪄 IDEA:
Use *interweaving technique* — Insert cloned nodes between original nodes.
Then set random pointers using this structure, and finally detach clone list.

🧩 STEPS:
1️⃣ Step 1: Insert cloned node after each original node.
   Example:
   Original: 1 -> 2 -> 3
   After insertion: 1 -> 1' -> 2 -> 2' -> 3 -> 3'

2️⃣ Step 2: Set random pointers for cloned nodes:
   clone->random = original->random->next

3️⃣ Step 3: Separate both lists:
   original: 1 -> 2 -> 3
   clone: 1' -> 2' -> 3'

🧮 TIME: O(N)
🧮 SPACE: O(1)
*/

Node* cloneLinkedList_Optimized(Node* head) {
    if (!head) return NULL;

    Node* temp = head;

    // Step 1: Insert cloned nodes after original nodes
    while (temp) {
        Node* nextNode = temp->next;
        Node* copy = new Node(temp->data);
        temp->next = copy;
        copy->next = nextNode;
        temp = nextNode;
    }

    // Step 2: Set random pointers of cloned nodes
    temp = head;
    while (temp) {
        if (temp->random)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    // Step 3: Detach both lists
    Node* dummy = new Node(-1);
    Node* copy = dummy;
    temp = head;

    while (temp) {
        copy->next = temp->next;
        temp->next = temp->next->next;

        temp = temp->next;
        copy = copy->next;
    }

    return dummy->next;
}

/*
----------------------------------------------
🔬 DRY RUN (Optimized Approach)
----------------------------------------------
Original: 1 -> 2 -> 3
Randoms: 1.random->3, 2.random->1, 3.random->2

Step 1: Interleave nodes
1 -> 1' -> 2 -> 2' -> 3 -> 3'

Step 2: Set random pointers
1'.random = 3'
2'.random = 1'
3'.random = 2'

Step 3: Detach lists
Original: 1 -> 2 -> 3
Clone:    1' -> 2' -> 3'

----------------------------------------------
✅ PROOF OF CORRECTNESS:
----------------------------------------------
Each cloned node lies exactly after its original counterpart.
Thus, every random pointer’s clone can be directly accessed via:
   clone->random = original->random->next
This avoids extra space for mapping and ensures one-pass connection.
----------------------------------------------
*/

void printList(Node* head) {
    while (head) {
        cout << "Data: " << head->data << ", ";
        if (head->random)
            cout << "Random: " << head->random->data;
        else
            cout << "Random: NULL";
        cout << endl;
        head = head->next;
    }
}

// Example Driver Code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head->random = head->next->next;       // 1 -> 3
    head->next->random = head;             // 2 -> 1
    head->next->next->random = head->next->next->next; // 3 -> 4
    head->next->next->next->random = head->next;       // 4 -> 2

    cout << "Original List:\n";
    printList(head);

    Node* clonedHead = cloneLinkedList_Optimized(head);
    cout << "\nCloned List:\n";
    printList(clonedHead);
    return 0;
}

