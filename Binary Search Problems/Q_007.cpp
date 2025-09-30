/*
-------------------------------------------------------
Search in Rotated Sorted Array
-------------------------------------------------------
Idea:
- The array is sorted but rotated at some pivot.
- At each step of binary search, one half is always sorted.
- We check:
    1. If left half is sorted:
        - If target lies in that half → move there.
        - Else → move to right half.
    2. Else (right half is sorted):
        - If target lies in that half → move there.
        - Else → move to left half.
- Continue until found or low > high.
-------------------------------------------------------
Time Complexity: O(log N)
Space Complexity: O(1)
-------------------------------------------------------
*/

int searchRotated(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid; // Found target

        // Check if left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1; // target in left half
            } else {
                low = mid + 1; // target in right half
            }
        }
        // Else right half is sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1; // target in right half
            } else {
                high = mid - 1; // target in left half
            }
        }
    }
    return -1; // target not found
}
