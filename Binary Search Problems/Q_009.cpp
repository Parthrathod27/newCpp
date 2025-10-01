/*
--------------------------------------------------------
Find Minimum in Rotated Sorted Array
LeetCode 153
--------------------------------------------------------
Brute Force:
- Scan entire array and return min element.
- Time Complexity: O(N)
- Space Complexity: O(1)

Optimal (Binary Search):
- Use binary search to find rotation point.
- If array already sorted, return nums[0].
- Else move search space accordingly.
- Time Complexity: O(log N)
- Space Complexity: O(1)
--------------------------------------------------------
*/

// Brute Force Approach
int findMinBrute(vector<int>& nums) {
    int mn = nums[0];
    for (int x : nums) {
        mn = min(mn, x);
    }
    return mn;
}

// Optimal Approach (Binary Search)
int findMinOptimal(vector<int>& nums) {
    int low = 0, high = nums.size() - 1;

    while (low < high) {
        // If array segment is sorted
        if (nums[low] <= nums[high]) {
            return nums[low];
        }

        int mid = low + (high - low) / 2;

        // Minimum is in right half
        if (nums[mid] >= nums[low]) {
            low = mid + 1;
        }
        // Minimum is in left half
        else {
            high = mid;
        }
    }
    return nums[low];
}
