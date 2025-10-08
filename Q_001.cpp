#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------------------
// Approach 1: Two Pointer Approach (Optimal)
// ----------------------------------------------------------
// Idea: Use two pointers — one at start, one at end. 
// Swap elements and move both pointers inward until they meet.
// Time: O(N), Space: O(1)
void reverseString_TwoPointer(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

// ----------------------------------------------------------
// Approach 2: Using STL reverse() function
// ----------------------------------------------------------
// Idea: Use C++ STL built-in reverse function for simplicity.
// Time: O(N), Space: O(1)
void reverseString_STL(vector<char>& s) {
    reverse(s.begin(), s.end());
}

// ----------------------------------------------------------
// Approach 3: Recursive Approach
// ----------------------------------------------------------
// Idea: Swap first and last, then recurse on the middle part.
// Time: O(N), Space: O(N) due to recursion stack
void helper(vector<char>& s, int left, int right) {
    if (left >= right) return;
    swap(s[left], s[right]);
    helper(s, left + 1, right - 1);
}

void reverseString_Recursive(vector<char>& s) {
    helper(s, 0, s.size() - 1);
}

// -------------------------
// MAIN FUNCTION
// -------------------------
int main() {
    vector<char> s = {'h','e','l','l','o'};
    reverseString_TwoPointer(s);
    for (auto c : s) cout << c; // Output: olleh
    return 0;
}

