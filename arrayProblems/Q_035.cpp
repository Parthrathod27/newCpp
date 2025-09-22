#include <bits/stdc++.h>
using namespace std;

/*
🔥 Problem: Maximum Product Subarray
Given an integer array nums, find the contiguous subarray within an array 
which has the largest product, and return the product.

---

💡 Brute Force Approach:
1. Generate all subarrays using two loops.
2. For each subarray, calculate the product.
3. Keep track of the maximum product found.
⏱️ Time Complexity: O(n^2)
📦 Space Complexity: O(1)
*/

int maxProductBrute(vector<int>& nums) {
    int n = nums.size();
    int result = INT_MIN;

    for (int i = 0; i < n; i++) {
        int product = 1;
        for (int j = i; j < n; j++) {
            product *= nums[j];
            result = max(result, product);
        }
    }
    return result;
}

/*
💡 Optimal Approach (Kadane’s Algorithm for Product):
1. The challenge: product can turn negative → might become positive again if multiplied by another negative.
2. So, we track both:
   - `maxProd`: maximum product ending at current index.
   - `minProd`: minimum product ending at current index.
3. At each step:
   - If nums[i] < 0 → swap(maxProd, minProd) because multiplying by negative flips roles.
   - Update maxProd = max(nums[i], maxProd * nums[i])
   - Update minProd = min(nums[i], minProd * nums[i])
   - Update global result.
⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)
*/

int maxProductOptimal(vector<int>& nums) {
    int n = nums.size();
    int result = nums[0];
    int maxProd = nums[0], minProd = nums[0];

    for (int i = 1; i < n; i++) {
        if (nums[i] < 0) swap(maxProd, minProd);

        maxProd = max(nums[i], maxProd * nums[i]);
        minProd = min(nums[i], minProd * nums[i]);

        result = max(result, maxProd);
    }
    return result;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};

    cout << "Brute Force Result: " << maxProductBrute(nums) << endl;
    cout << "Optimal Result: " << maxProductOptimal(nums) << endl;

    return 0;
}

