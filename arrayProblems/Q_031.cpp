// ------------------------------------------------------------
// Problem: Merge Sorted Arrays Without Extra Space
// Given two sorted arrays arr1[] and arr2[], merge them so that
// after merging, arr1 contains the smaller elements and arr2 
// contains the larger elements. Do this without using extra space.
// ------------------------------------------------------------


// ------------------ Approach 1: Swap + Sort -----------------
// 1. Traverse arr1 from left and arr2 from right.
// 2. If arr1[i] > arr2[j], swap them.
// 3. After traversing, sort both arrays again.
// 4. This ensures correct placement but uses sorting again.
//
// Time Complexity: O((n+m) log(n+m))   (due to sorting at the end)
// Space Complexity: O(1)
// ------------------------------------------------------------

class SolutionSwapSort {
public:
    void merge(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        int i = n - 1, j = 0;

        // Step 1: Swap elements if arr1[i] > arr2[j]
        while (i >= 0 && j < m) {
            if (arr1[i] > arr2[j]) {
                swap(arr1[i], arr2[j]);
            }
            i--;
            j++;
        }

        // Step 2: Sort both arrays again
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
    }
};


// ------------------ Approach 2: Gap Method (Shell Sort idea) ---------
// 1. Treat arr1 and arr2 as a single combined array of size (n+m).
// 2. Use a "gap" (initially ceil((n+m)/2)) and compare elements 
//    gap apart. Swap if out of order.
// 3. Reduce gap each iteration until gap = 1.
// 4. Works like Shell Sort → ensures in-place merging without extra space.
//
// Time Complexity: O((n+m) log(n+m))
// Space Complexity: O(1)
// ------------------------------------------------------------

class SolutionGapMethod {
public:
    void merge(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        int total = n + m;

        // Helper function to get next gap
        auto nextGap = [&](int gap) {
            if (gap <= 1) return 0;
            return (gap / 2) + (gap % 2);
        };

        // Start with initial gap
        for (int gap = nextGap(total); gap > 0; gap = nextGap(gap)) {
            int i, j;

            // Case 1: compare within arr1
            for (i = 0; i + gap < n; i++) {
                if (arr1[i] > arr1[i + gap]) {
                    swap(arr1[i], arr1[i + gap]);
                }
            }

            // Case 2: compare across arr1 and arr2
            for (j = (gap > n) ? gap - n : 0; i < n && j < m; i++, j++) {
                if (arr1[i] > arr2[j]) {
                    swap(arr1[i], arr2[j]);
                }
            }

            // Case 3: compare within arr2
            if (j < m) {
                for (j = 0; j + gap < m; j++) {
                    if (arr2[j] > arr2[j + gap]) {
                        swap(arr2[j], arr2[j + gap]);
                    }
                }
            }
        }
    }
};

