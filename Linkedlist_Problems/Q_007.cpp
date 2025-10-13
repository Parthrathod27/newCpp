// ✅ Approach 1: Counting Method (Brute Force)
// Time Complexity: O(2N)
// Space Complexity: O(1)
// Logic: Count total number of 0s, 1s, and 2s, then rewrite linked list values in order.

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* sortList(Node* head) {
    // Base case: If list is empty or has only one node
    if (head == nullptr || head->next == nullptr) return head;

    // Step 1️⃣: Count number of 0s, 1s, and 2s
    int count0 = 0, count1 = 0, count2 = 0;
    Node* temp = head;
    while (temp != nullptr
: Count total number of 0s, 1s, and 2s, then rewrite linked list values in order.

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};


Node* sortList(Node* head) {
    // Base case: If list is empty or has only one node
    if (head == nullptr || head->next == nullptr) return head;

    // Step 1️⃣: Count number of 0s, 1s, and 2s
    int count0 = 0, count1 = 0, count2 = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == 0) count0++;
        else if (temp->data == 1) count1++;
        else count2++;
        temp = temp->next;
    }

    // Step 2️⃣: Rewrite the values in the linked list
    temp = head;
    while (temp != nullptr) {
        if (count0 > 0) {
            temp->data = 0;
            count0--;
        } else if (count1 > 0) {
            temp->data = 1;
            count1--;
        } else {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }

    // Step 3️⃣: Return the sorted list
    return head;
}


// ✅ Approach 2: Using Three Dummy Lists
// Time Complexity: O(N)
// Space Complexity: O(1) — only a few extra pointers
// Logic: Create 3 separate lists for 0s, 1s, and 2s, then connect them together.

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

Node* sortList(Node* head) {
    // Base case: empty or single node
    if (head == nullptr || head->next == nullptr) return head;

    // Step 1️⃣: Create dummy heads for 0s, 1s, and 2s
    Node* zeroHead = new Node(-1);
    Node* oneHead  = new Node(-1);
    Node* twoHead  = new Node(-1);

    // Tail pointers for each list
    Node* zero = zeroHead;
    Node* one  = oneHead;
    Node* two  = twoHead;

    // Step 2️⃣: Traverse the list and segregate nodes into 0, 1, and 2 lists
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == 0) {
            zero->next = temp;
            zero = zero->next;
        } 
        else if (temp->data == 1) {
            one->next = temp;
            one = one->next;
        } 
        else {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    // Step 3️⃣: Merge all three lists
    // Connect end of 0s list to start of 1s (or 2s if 1s list is empty)
    zero->next = (oneHead->next != nullptr) ? oneHead->next : twoHead->next;
    // Connect end of 1s list to start of 2s list
    one->next = twoHead->next;
    // Mark end of 2s list
    two->next = nullptr;

    // Step 4️⃣: Final head will be start of 0s list
    Node* newHead = zeroHead->next;

    // Step 5️⃣: Free up dummy nodes (optional)
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    // Step 6️⃣: Return the new sorted linked list
    return newHead;
}

