/*
-----------------------------------------------------------
🧠 PROBLEM: Merge K Sorted Linked Lists
-----------------------------------------------------------
Given K sorted linked lists, you need to merge them into a single sorted linked list.

-----------------------------------------------------------
📘 Example:
-----------------------------------------------------------
Input:
K = 3
List1: 1 -> 4 -> 5
List2: 1 -> 3 -> 4
List3: 2 -> 6

Output:
1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6

-----------------------------------------------------------
💡 INTUITION:
-----------------------------------------------------------
We have multiple sorted linked lists, and we must combine them into one sorted list.
This is an extension of the "Merge Two Sorted Lists" problem.
We can do this in several ways — some simple but inefficient, and some highly optimized.

-----------------------------------------------------------
🧩 STRUCTURE DEFINITION:
-----------------------------------------------------------
Every node has:
    - val: integer value
    - next: pointer to next node
-----------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
-----------------------------------------------------------
🪜 APPROACH 1: Brute Force (Collect + Sort)
-----------------------------------------------------------

🔹 IDEA:
1️⃣ Traverse all K linked lists and store every node’s value into a vector.
2️⃣ Sort the vector.
3️⃣ Create a new sorted linked list from the sorted vector.

-----------------------------------------------------------
🔹 STEPS:
-----------------------------------------------------------
- Iterate over each list and push all values into a vector.
- Sort the vector.
- Create a new linked list using sorted values.

-----------------------------------------------------------
⏱️ Time Complexity: O(N log N)
    (where N = total number of nodes across all lists)
🧠 Space Complexity: O(N)
-----------------------------------------------------------
*/

ListNode* mergeKLists_Brute(vector<ListNode*>& lists) {
    vector<int> values;

    // Collect all node values
    for (auto list : lists) {
        while (list) {
            values.push_back(list->val);
            list = list->next;
        }
    }

    // Sort all values
    sort(values.begin(), values.end());

    // Build new sorted list
    ListNode dummy;
    ListNode* temp = &dummy;
    for (int v : values) {
        temp->next = new ListNode(v);
        temp = temp->next;
    }

    return dummy.next;
}

/*
-----------------------------------------------------------
🪜 APPROACH 2: Sequential Merge (One by One)
-----------------------------------------------------------

🔹 IDEA:
Merge the first two lists,
then merge the result with the next list,
and continue until all K lists are merged.

-----------------------------------------------------------
🔹 STEPS:
-----------------------------------------------------------
1️⃣ Use the helper function mergeTwoLists to merge two sorted lists.
2️⃣ Start merging from the first list, one by one.

-----------------------------------------------------------
⏱️ Time Complexity: O(K * N)
    (Each merge traverses many nodes repeatedly)
🧠 Space Complexity: O(1)
-----------------------------------------------------------
*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    ListNode dummy;
    ListNode* tail = &dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}

ListNode* mergeKLists_Sequential(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;

    ListNode* merged = lists[0];
    for (int i = 1; i < lists.size(); i++) {
        merged = mergeTwoLists(merged, lists[i]);
    }

    return merged;
}

/*
-----------------------------------------------------------
🪜 APPROACH 3: Divide and Conquer (Efficient)
-----------------------------------------------------------

🔹 IDEA:
This is similar to the merge sort algorithm.
We merge pairs of lists in a divide-and-conquer manner.

-----------------------------------------------------------
🔹 STEPS:
-----------------------------------------------------------
1️⃣ Merge lists in pairs: (list[0], list[1]), (list[2], list[3]), ...
2️⃣ Continue merging these intermediate results until one list remains.

-----------------------------------------------------------
⏱️ Time Complexity: O(N log K)
    (Each level of merging takes O(N), and there are logK levels)
🧠 Space Complexity: O(1)
-----------------------------------------------------------
*/

ListNode* mergeKLists_DivideAndConquer(vector<ListNode*>& lists) {
    if (lists.empty()) return nullptr;

    while (lists.size() > 1) {
        vector<ListNode*> newLists;

        for (int i = 0; i < lists.size(); i += 2) {
            if (i + 1 < lists.size())
                newLists.push_back(mergeTwoLists(lists[i], lists[i + 1]));
            else
                newLists.push_back(lists[i]);
        }

        lists = newLists;
    }

    return lists[0];
}

/*
-----------------------------------------------------------
🪜 APPROACH 4: Min-Heap / Priority Queue (Optimal)
-----------------------------------------------------------

🔹 IDEA:
We always need the smallest node among the K lists at each step.
So, use a Min-Heap to efficiently get the smallest value.

-----------------------------------------------------------
🔹 STEPS:
-----------------------------------------------------------
1️⃣ Push the head of each list into a min-heap (value, node).
2️⃣ Pop the smallest node, attach it to the result list.
3️⃣ If that node has a next, push its next node into the heap.
4️⃣ Repeat until heap is empty.

-----------------------------------------------------------
⏱️ Time Complexity: O(N log K)
    (Each insertion/deletion in heap takes O(log K))
🧠 Space Complexity: O(K)
-----------------------------------------------------------
*/

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists_Heap(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;

    // Push head of each list
    for (auto list : lists) {
        if (list) pq.push(list);
    }

    ListNode dummy;
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();

        tail->next = node;
        tail = tail->next;

        if (node->next)
            pq.push(node->next);
    }

    return dummy.next;
}

/*
-----------------------------------------------------------
🧩 DRY RUN EXAMPLE
-----------------------------------------------------------
Input:
K = 3
List1: 1 -> 4 -> 5
List2: 1 -> 3 -> 4
List3: 2 -> 6

Heap initially:
[1(from list1), 1(from list2), 2(from list3)]

Step 1: Pop 1(list1), push 4
Step 2: Pop 1(list2), push 3
Step 3: Pop 2(list3), push 6
Step 4: Pop 3, push 4
Step 5: Pop 4, push 5
Step 6: Pop 4
Step 7: Pop 5
Step 8: Pop 6

Output: 1->1->2->3->4->4->5->6
-----------------------------------------------------------
*/

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

/*
-----------------------------------------------------------
🧾 SUMMARY
-----------------------------------------------------------
🔹 Approach 1: Brute Force
    ⏱ O(N log N), 🧠 O(N)
    ✅ Simple, but inefficient.

🔹 Approach 2: Sequential Merge
    ⏱ O(K*N), 🧠 O(1)
    ✅ Easy to code, but slow for large K.

🔹 Approach 3: Divide and Conquer
    ⏱ O(N log K), 🧠 O(1)
    ✅ Efficient and simple to implement.

🔹 Approach 4: Min-Heap
    ⏱ O(N log K), 🧠 O(K)
    ✅ Most optimal for large datasets.

🔥 Best for Interviews → Divide and Conquer or Min-Heap.
-----------------------------------------------------------
*/

int main() {
    // Example usage

    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));

    vector<ListNode*> lists = {l1, l2, l3};

    cout << "Merged List (Using Min-Heap): ";
    ListNode* merged = mergeKLists_Heap(lists);
    printList(merged);

    return 0;
}

