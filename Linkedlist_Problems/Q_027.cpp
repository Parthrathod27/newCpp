/*
--------------------------------------------
🧠 PROBLEM: Flattening a Linked List (GFG)
--------------------------------------------
You are given a linked list where each node has two pointers:
1️⃣ next → points to the next node in the same level
2️⃣ bottom → points to a linked list that is sorted

Your task is to "flatten" the list so that all nodes appear in a single sorted linked list.

--------------------------------------------
📘 Example:
--------------------------------------------
Input:

5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22    35
|           |     |
8           50    40
|                 |
30                45

Output:
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50

--------------------------------------------
💡 INTUITION:
--------------------------------------------
We have multiple sorted linked lists connected via `next` pointers.
Each list itself is sorted using `bottom` pointers.

We need to merge all these sorted lists into one.
This is similar to merging multiple sorted linked lists (like in Merge K Sorted Lists problem).

--------------------------------------------
🧩 STRUCTURE DEFINITION:
--------------------------------------------
Every node has two pointers:
    - next: to the right
    - bottom: downward linked list
--------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* bottom;
    Node(int x) : data(x), next(NULL), bottom(NULL) {}
};

/*
--------------------------------------------
🪜 APPROACH 1: Recursive Merge (Optimal)
--------------------------------------------

🔹 Idea:
We recursively flatten the list from right to left:
1️⃣ Flatten the rest of the list (list->next)
2️⃣ Merge the current list with the already flattened right list
3️⃣ Return the merged list.

This uses the concept of merging two sorted linked lists.

--------------------------------------------
🔹 Steps:
--------------------------------------------
1. Base case: If head is NULL or head->next is NULL, return head.
2. Recursively flatten the next list.
3. Merge current list and flattened list using a helper function `mergeTwoLists`.
4. Return the merged list.

--------------------------------------------
🔹 Time Complexity → O(N * M)
    (where N = number of nodes in main list, M = avg length of each sublist)
🔹 Space Complexity → O(1) (In-place)
--------------------------------------------
*/

Node* mergeTwoLists(Node* a, Node* b) {
    // If one list is empty
    if (!a) return b;
    if (!b) return a;

    Node* result;
    // Compare and merge recursively
    if (a->data < b->data) {
        result = a;
        result->bottom = mergeTwoLists(a->bottom, b);
    } else {
        result = b;
        result->bottom = mergeTwoLists(a, b->bottom);
    }
    result->next = NULL; // Ensure `next` is NULL
    return result;
}

Node* flattenRecursive(Node* root) {
    if (root == NULL || root->next == NULL)
        return root;

    // Flatten the right side first
    root->next = flattenRecursive(root->next);

    // Merge current list with right flattened list
    root = mergeTwoLists(root, root->next);

    return root;
}

/*
--------------------------------------------
⚡ APPROACH 2: Iterative Merge (Without Recursion)
--------------------------------------------

🔹 Idea:
Instead of recursion, use a while loop to merge each `next` list into a single flattened list.

--------------------------------------------
🔹 Steps:
--------------------------------------------
1️⃣ Start with the first list as `result`.
2️⃣ For each `next` list, merge it into the result using `mergeTwoLists`.
3️⃣ Continue until all lists are merged.

--------------------------------------------
🔹 Time Complexity → O(N * M)
🔹 Space Complexity → O(1)
--------------------------------------------
*/

Node* flattenIterative(Node* root) {
    if (!root) return NULL;

    Node* result = root;
    Node* temp = root->next;

    while (temp) {
        result = mergeTwoLists(result, temp);
        temp = temp->next;
    }

    return result;
}

/*
--------------------------------------------
💡 APPROACH 3: Min-Heap / Priority Queue (Efficient)
--------------------------------------------

🔹 Idea:
Use a Min-Heap to efficiently get the smallest node among all lists.

--------------------------------------------
🔹 Steps:
--------------------------------------------
1️⃣ Push the head of each list (connected by `next`) into a min-heap.
2️⃣ Pop the smallest node, and push its `bottom` node if it exists.
3️⃣ Continue until heap is empty, linking nodes in sorted order.

--------------------------------------------
🔹 Time Complexity → O(N * logK)
    where K = number of lists
🔹 Space Complexity → O(K)
--------------------------------------------
*/

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* flattenUsingHeap(Node* root) {
    if (!root) return NULL;

    priority_queue<Node*, vector<Node*>, compare> pq;
    Node* curr = root;

    // Push all heads of lists
    while (curr) {
        pq.push(curr);
        curr = curr->next;
    }

    Node* dummy = new Node(0);
    Node* temp = dummy;

    while (!pq.empty()) {
        Node* smallest = pq.top();
        pq.pop();

        temp->bottom = smallest;
        temp = temp->bottom;

        if (smallest->bottom)
            pq.push(smallest->bottom);
    }

    return dummy->bottom;
}

/*
--------------------------------------------
🧩 DRY RUN EXAMPLE
--------------------------------------------
Input:

5 -> 10 -> 19 -> 28
|     |     |     |
7     20    22    35
|           |     |
8           50    40
|                 |
30                45

Step-by-step merging:

→ Flatten rightmost (28→35→40→45)
→ Merge (19→22→50) with above
→ Merge (10→20) with above
→ Merge (5→7→8→30) with above

Final Output:
5→7→8→10→19→20→22→28→30→35→40→45→50
--------------------------------------------
*/

void printFlattened(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main() {
    /*
    Construct sample input:

    5 -> 10 -> 19 -> 28
    |     |     |     |
    7     20    22    35
    |           |     |
    8           50    40
    |                 |
    30                45
    */

    Node* head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);

    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    cout << "Flattened LinkedList (Recursive Approach): ";
    Node* flat1 = flattenRecursive(head);
    printFlattened(flat1);

    return 0;
}

/*
--------------------------------------------
🧾 SUMMARY
--------------------------------------------
🔹 Approach 1: Recursive Merge
    ✅ Clean, intuitive, most used in interviews
    ⏱ O(N*M), 🧠 O(1)

🔹 Approach 2: Iterative Merge
    ✅ Avoids recursion overhead
    ⏱ O(N*M), 🧠 O(1)

🔹 Approach 3: Min-Heap / Priority Queue
    ✅ Most efficient for large number of lists
    ⏱ O(N log K), 🧠 O(K)

🔥 Tip:
Use Recursive Merge for coding interviews
and Heap-based approach for large-scale systems.
--------------------------------------------
*/

