#include <bits/stdc++.h>
using namespace std;

/*
====================================================================
 🧠 PROBLEM STATEMENT
====================================================================
Given two sorted arrays nums1[] and nums2[] of different sizes (m and n),
find the median of the two sorted arrays.

Median = middle element if total size is odd,
          or average of two middle elements if even.

We must handle both sorted arrays efficiently.
====================================================================
*/

/*
====================================================================
💡 APPROACH 1: MERGE + FIND MEDIAN (Brute Force)
--------------------------------------------------------------------
🔹 IDEA:
Merge both sorted arrays into one sorted array.
Then directly pick the middle element(s) to find the median.

🔹 TIME COMPLEXITY:  O(m + n)
🔹 SPACE COMPLEXITY: O(m + n)
====================================================================
*/
double median_merge(vector<int> &a, vector<int> &b) {
    vector<int> merged;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) merged.push_back(a[i++]);
        else merged.push_back(b[j++]);
    }
    while (i < a.size()) merged.push_back(a[i++]);
    while (j < b.size()) merged.push_back(b[j++]);

    int n = merged.size();
    if (n % 2 == 1) return merged[n / 2];
    else return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
}

/*
====================================================================
💡 APPROACH 2: TWO POINTERS (WITHOUT EXTRA SPACE)
--------------------------------------------------------------------
🔹 IDEA:
Instead of creating a merged array, just simulate the merge process.
Stop once we reach the middle index.

🔹 TIME COMPLEXITY:  O(m + n)
🔹 SPACE COMPLEXITY: O(1)
====================================================================
*/
double median_two_pointers(vector<int> &a, vector<int> &b) {
    int m = a.size(), n = b.size();
    int total = m + n;
    int mid1 = (total - 1) / 2;
    int mid2 = total / 2;

    int i = 0, j = 0, count = 0;
    int val1 = -1, val2 = -1;

    while (count <= mid2) {
        int val;
        if (i < m && (j >= n || a[i] <= b[j])) val = a[i++];
        else val = b[j++];

        if (count == mid1) val1 = val;
        if (count == mid2) val2 = val;
        count++;
    }

    return (val1 + val2) / 2.0;
}

/*
====================================================================
💡 APPROACH 3: BINARY SEARCH PARTITION METHOD (Optimal)
--------------------------------------------------------------------
🔹 IDEA:
We perform binary search on the smaller array to find a partition
such that elements on the left side of both arrays together
are less than or equal to all elements on the right side.

If total length = m + n:
- left partition size = (m + n + 1) / 2
- right partition = remaining elements

We ensure:
  maxLeftA <= minRightB
  maxLeftB <= minRightA

🔹 TIME COMPLEXITY:  O(log(min(m, n)))
🔹 SPACE COMPLEXITY: O(1)
====================================================================
*/
double median_binary_search(vector<int> &a, vector<int> &b) {
    if (a.size() > b.size()) return median_binary_search(b, a); // binary search on smaller array

    int m = a.size(), n = b.size();
    int totalLeft = (m + n + 1) / 2;
    int low = 0, high = m;

    while (low <= high) {
        int cutA = (low + high) / 2;
        int cutB = totalLeft - cutA;

        int leftA  = (cutA == 0) ? INT_MIN : a[cutA - 1];
        int rightA = (cutA == m) ? INT_MAX : a[cutA];
        int leftB  = (cutB == 0) ? INT_MIN : b[cutB - 1];
        int rightB = (cutB == n) ? INT_MAX : b[cutB];

        if (leftA <= rightB && leftB <= rightA) {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            else
                return max(leftA, leftB);
        }
        else if (leftA > rightB)
            high = cutA - 1;
        else
            low = cutA + 1;
    }

    return 0.0; // should never reach here
}

