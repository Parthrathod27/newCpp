/*
🔹 Brute Force Idea:
Try every possible ship capacity from max(weights) → sum(weights).
For each capacity, check if all packages can be shipped within D days.
Return the first (smallest) capacity that satisfies the condition.
*/

#include <bits/stdc++.h>
using namespace std;

class BruteForce {
public:
    // Helper to count days needed for given ship capacity
    int days_with_weight(vector<int>& weights, int weight) {
        int days = 1, cur_weight = 0;
        for (int w : weights) {
            if (cur_weight + w <= weight)
                cur_weight += w;
            else {
                days++;
                cur_weight = w;
            }
        }
        return days;
    }

    // Main brute force method
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = *max_element(weights.begin(), weights.end());
        int maxCap = accumulate(weights.begin(), weights.end(), 0);

        // 🔹 Test each capacity one by one
        for (int cap = minCap; cap <= maxCap; cap++) {
            int requiredDays = days_with_weight(weights, cap);
            if (requiredDays <= days) {
                return cap; // first valid (smallest) capacity found
            }
        }
        return maxCap;
    }
};

/*
🧩 Time Complexity:
   O(N * (sum(weights) - max(weights))) → very slow for large arrays
🧩 Space Complexity: O(1)
*/



/*
🔹 Problem: Ship Packages Within D Days (LeetCode 1011)
You are given an array of weights[] representing packages to ship in order, and an integer D.
You need to find the **minimum ship capacity** so that all packages can be shipped within D days.

We use **Binary Search on Answer**:
   - Minimum capacity → max(weights)  (smallest ship must at least carry the heaviest package)
   - Maximum capacity → sum(weights)  (if ship carries all in one day)

We binary search for the smallest capacity that can ship within D days.
*/


class Solution {
public:
    // 🔹 Helper Function: Calculate number of days required if ship capacity = 'weight'
    int days_with_weight(vector<int>& weights, int weight) {
        int days = 1; // Start with day 1
        int cur_weight = 0;
        for (int w : weights) {
            if (cur_weight + w <= weight) {
                cur_weight += w; // add current package to same day
            } else {
                days++;          // need a new day
                cur_weight = w;  // reset weight
            }
        }
        return days;
    }

    // 🔹 Main Function: Binary Search on minimum capacity
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // smallest possible capacity
        int high = accumulate(weights.begin(), weights.end(), 0); // largest possible capacity

        while (low <= high) {
            int mid = low + (high - low) / 2;  // mid = test capacity
            int requiredDays = days_with_weight(weights, mid);

            // if we can ship within given days, try smaller capacity
            if (requiredDays <= days) {
                high = mid - 1;
            }
            // else, we need a larger capacity
            else {
                low = mid + 1;
            }
        }
        return low; // smallest valid capacity
    }
};

/*
🧩 Time Complexity:
    O(N * log(sum(weights) - max(weights)))
    (binary search * days_with_weight simulation)
🧩 Space Complexity: O(1)
*/
