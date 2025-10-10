// --------------------------------------------
// 📘 L1. Introduction to LinkedList (Striver)
// Topic: Traversal | Length | Search an Element
// --------------------------------------------

// 🔹 What is a Linked List?
// A Linked List is a linear data structure where elements (nodes) are connected using pointers.
// Each node contains:
//   1️⃣ data  → value of node
//   2️⃣ next  → pointer to the next node

// --------------------------------------------
// 📦 Structure of Node
// --------------------------------------------

// Each node can be defined as:
struct Node {
    int data;        // stores value
    Node* next;      // stores address of next node

    // Constructor for easy initialization
    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

// --------------------------------------------
// 🧠 Example of Linked List
// --------------------------------------------
// Head -> [1 | *] -> [2 | *] -> [3 | *] -> NULL
// Each node points to the next, and last node points to NULL.

// --------------------------------------------
// 🛠️ Creating a Simple Linked List
// --------------------------------------------
Node* head = new Node(10);
head->next = new Node(20);
head->next->next = new Node(30);

// Now Linked List looks like: 10 -> 20 -> 30 -> NULL

// --------------------------------------------
// 🚶 Traversal (Printing all nodes)
// --------------------------------------------
void printLL(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Traversal Time Complexity → O(N)
// Space Complexity → O(1)

// --------------------------------------------
// 📏 Find Length of Linked List
// --------------------------------------------
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Time Complexity → O(N)
// Space Complexity → O(1)

// --------------------------------------------
// 🔍 Search for an Element in Linked List
// --------------------------------------------
bool searchElement(Node* head, int target) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == target)
            return true;
        temp = temp->next;
    }
    return false;
}

// Time Complexity → O(N)
// Space Complexity → O(1)

// --------------------------------------------
// 🧩 Dry Run Example
// Linked List: 10 -> 20 -> 30 -> NULL
// Length = 3
// Search(20) → Found ✅
// Search(40) → Not Found ❌

// --------------------------------------------
// 💡 Important Concepts Recap
// --------------------------------------------
// ✅ Node = {data + pointer to next}
// ✅ Head points to first node
// ✅ Last node points to NULL
// ✅ Traversal → visit each node using next
// ✅ getLength() → count nodes till NULL
// ✅ searchElement() → linear search through list

// --------------------------------------------
// 🧠 Next Steps (in upcoming lectures)
// --------------------------------------------
// - Insert at head, tail, or given position
// - Delete nodes
// - Reverse the linked list
// - Use slow/fast pointers for advanced operations
// --------------------------------------------

