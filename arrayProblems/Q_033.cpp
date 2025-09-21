// ------------------------------------------------------------
// Problem: Count Inversions in an Array
// An inversion is a pair (i, j) such that i < j and arr[i] > arr[j].
//
// Example:
// Input: arr = {5, 3, 2, 1, 4}
// Inversions are: (5,3), (5,2), (5,1), (5,4), (3,2), (3,1), (2,1)
// Total = 7
//
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;


// ---------------- Approach 1: Brute Force -------------------
// For every pair (i, j), check if arr[i] > arr[j].
// Count all such pairs.
// Time: O(n^2), Space: O(1)
// ------------------------------------------------------------
long long countInversions_Brute(vector<int>& arr) {
    int n = arr.size();
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) count++;
        }
    }
    return count;
}


// ---------------- Approach 2: Optimal (Merge Sort) ----------
// Idea: While merging two sorted halves, if arr[i] > arr[j],
// then all remaining elements in left half (i..mid) are also
// greater than arr[j], so count inversions in bulk.
//
// Time: O(n log n), Space: O(n) (due to temporary array)
// ------------------------------------------------------------

long long mergeAndCount(vector<int>& arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid+1;
    long long count = 0;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            count += (mid - left + 1); // all remaining in left part
            right++;
        }
    }
    while (left <= mid) temp.push_back(arr[left++]);
    while (right <= high) temp.push_back(arr[right++]);

    for (int i = low; i <= high; i++) arr[i] = temp[i - low];

    return count;
}

long long mergeSortAndCount(vector<int>& arr, int low, int high) {
    long long count = 0;
    if (low < high) {
        int mid = (low + high) / 2;
        count += mergeSortAndCount(arr, low, mid);
        count += mergeSortAndCount(arr, mid+1, high);
        count += mergeAndCount(arr, low, mid, high);
    }
    return count;
}

long long countInversions_Optimal(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size()-1);
}


// ---------------- Main Function for Testing ----------------
int main() {
    vector<int> arr = {5, 3, 2, 1, 4};

    cout << "Brute Force -> Inversions: " << countInversions_Brute(arr) << endl;

    // Need fresh copy of arr for merge sort (since it sorts the array)
    vector<int> arr2 = {5, 3, 2, 1, 4};
    cout << "Optimal     -> Inversions: " << countInversions_Optimal(arr2) << endl;

    return 0;
}

