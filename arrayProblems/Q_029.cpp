// ------------------------------------------------------------
// Problem: 4Sum
// Given an integer array nums and an integer target, return all
// unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such
// that:
//    - a, b, c, and d are distinct indices
//    - nums[a] + nums[b] + nums[c] + nums[d] == target
// ------------------------------------------------------------

// -------------------- Approach ------------------------------
// 1. Sort the array → helps in two-pointer technique and skipping duplicates.
// 2. Fix two numbers (nums[i], nums[j]) using nested loops.
// 3. Use two-pointer approach on the remaining subarray (k, l).
//    - If sum < target → move k++ (need bigger sum).
//    - If sum > target → move l-- (need smaller sum).
//    - If sum == target → store quadruplet, then move k and l.
// 4. Skip duplicates at all levels (i, j, k, l) to ensure unique results.
// 5. Time complexity: O(n^3), Space complexity: O(1) excluding output.
// ------------------------------------------------------------

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: sort array
        sort(nums.begin(), nums.end());

        // Step 2: fix first number
        for (int i = 0; i < n; i++) {
            // skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: fix second number
            for (int j = i + 1; j < n; j++) {
                // skip duplicate j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int k = j + 1;
                int l = n - 1;

                // Step 4: two-pointer for remaining two numbers
                while (k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if (sum < target) {
                        k++;  // need bigger sum
                    } else if (sum > target) {
                        l--;  // need smaller sum
                    } else {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        // skip duplicate k
                        while (k < l && nums[k] == nums[k - 1]) k++;
                        // skip duplicate l
                        while (k < l && nums[l] == nums[l + 1]) l--;
                    }
                }
            }
        }
        return ans;
    }
};

