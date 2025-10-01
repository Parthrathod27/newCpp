/*
-------------------------------------------------------
Search in Rotated Sorted Array II (with duplicates)
-------------------------------------------------------
Idea:
- Similar to normal rotated search, but duplicates cause ambiguity.
- If nums[low] == nums[mid] == nums[high], we can't decide → shrink both ends.
- Otherwise, apply the same logic as before:
    - Check which half is sorted.
    - Move into the half where target can lie.
-------------------------------------------------------
Time Complexity: O(log N) on average, but worst-case O(N) (when many duplicates).
Space Complexity: O(1)
-------------------------------------------------------
*/

bool searchRotatedWithDuplicates(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return true; // Found target

        // If duplicates at edges → shrink
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++;
            high--;
        }
        // Left half sorted
        else if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half sorted
        else {
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false; // target not found
}
