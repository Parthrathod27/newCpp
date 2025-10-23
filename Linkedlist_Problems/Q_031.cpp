/*
    🧠 Problem: Design a Browser History
    -----------------------------------
    You need to design a browser history system that allows:
        1. Visiting a new URL.
        2. Going back 'n' steps in history.
        3. Going forward 'n' steps in history.

    Functions:
        - BrowserHistory(string homepage)
        - void visit(string url)
        - string back(int steps)
        - string forward(int steps)

    Example:
        BrowserHistory browserHistory("leetcode.com");
        browserHistory.visit("google.com");
        browserHistory.visit("facebook.com");
        browserHistory.visit("youtube.com");
        browserHistory.back(1);      // facebook.com
        browserHistory.back(1);      // google.com
        browserHistory.forward(1);   // facebook.com
        browserHistory.visit("linkedin.com");
        browserHistory.forward(2);   // linkedin.com (cannot move forward)
        browserHistory.back(2);      // google.com
        browserHistory.back(7);      // leetcode.com
*/

/* ---------------------------------------------------------------------------
   📘 APPROACH 1: Using a Doubly Linked List
   ---------------------------------------------------------------------------
   🔹 Intuition:
       - Each page (node) will have `prev`, `next`, and `url`.
       - When we visit a new URL, we:
            → Remove all forward nodes (clear forward history).
            → Add the new page as the next of the current node.
       - Back: Move pointer to previous node up to ‘steps’ times.
       - Forward: Move pointer to next node up to ‘steps’ times.

   🔹 Why LinkedList?
       - Because moving back and forward becomes O(steps).
       - Visiting and deleting forward history becomes O(1).

   🔹 Time Complexity:
       - visit(url): O(1)
       - back(steps): O(steps)
       - forward(steps): O(steps)
   🔹 Space Complexity: O(N)
*/

class BrowserHistory {
public:
    // Node structure for doubly linked list
    struct Node {
        string url;
        Node* prev;
        Node* next;
        Node(string u) : url(u), prev(nullptr), next(nullptr) {}
    };

    Node* curr; // pointer to current page

    // Constructor initializes homepage
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }

    // Visit a new URL: clear forward history and create new node
    void visit(string url) {
        Node* newNode = new Node(url);
        curr->next = newNode;  // forward link
        newNode->prev = curr;  // backward link
        curr = newNode;        // move to new page
    }

    // Move 'steps' backward
    string back(int steps) {
        while (steps > 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }
        return curr->url;
    }

    // Move 'steps' forward
    string forward(int steps) {
        while (steps > 0 && curr->next != nullptr) {
            curr = curr->next;
            steps--;
        }
        return curr->url;
    }
};

/* ---------------------------------------------------------------------------
   📗 APPROACH 2: Using Two Stacks (Simpler to Understand)
   ---------------------------------------------------------------------------
   🔹 Intuition:
       - Use two stacks → backStack and forwardStack.
       - backStack stores all visited URLs (past history).
       - forwardStack stores pages you can move forward to.

       Steps:
        ➤ visit(url):
             push current page into backStack
             clear forwardStack
             move to new url

        ➤ back(steps):
             while steps>0 and backStack not empty:
                 push current page to forwardStack
                 pop from backStack and make it current

        ➤ forward(steps):
             while steps>0 and forwardStack not empty:
                 push current page to backStack
                 pop from forwardStack and make it current

   🔹 Time Complexity:
       visit → O(1)
       back  → O(steps)
       forward → O(steps)
   🔹 Space Complexity: O(N)
*/

class BrowserHistory_Stack {
public:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentPage;

    BrowserHistory_Stack(string homepage) {
        currentPage = homepage;
    }

    void visit(string url) {
        backStack.push(currentPage);
        currentPage = url;
        while (!forwardStack.empty()) forwardStack.pop(); // clear forward history
    }

    string back(int steps) {
        while (steps > 0 && !backStack.empty()) {
            forwardStack.push(currentPage);
            currentPage = backStack.top();
            backStack.pop();
            steps--;
        }
        return currentPage;
    }

    string forward(int steps) {
        while (steps > 0 && !forwardStack.empty()) {
            backStack.push(currentPage);
            currentPage = forwardStack.top();
            forwardStack.pop();
            steps--;
        }
        return currentPage;
    }
};

/* ---------------------------------------------------------------------------
   🧩 DRY RUN EXAMPLE
   ---------------------------------------------------------------------------
   Input:
       BrowserHistory bh("leetcode.com");
       bh.visit("google.com");
       bh.visit("facebook.com");
       bh.visit("youtube.com");
       bh.back(1);     // facebook.com
       bh.back(1);     // google.com
       bh.forward(1);  // facebook.com
       bh.visit("linkedin.com");
       bh.forward(2);  // linkedin.com (no forward possible)
       bh.back(2);     // google.com
       bh.back(7);     // leetcode.com

   Output:
       facebook.com
       google.com
       facebook.com
       linkedin.com
       google.com
       leetcode.com
*/

/* ---------------------------------------------------------------------------
   ✅ CONCLUSION:
   ---------------------------------------------------------------------------
   ➤ Approach 1 (Doubly Linked List) = Realistic browser simulation.
   ➤ Approach 2 (Two Stacks) = Easier, but slightly less memory efficient.
   ➤ Both give same time complexity and similar performance.
*/

