class Solution {
public:
    // ---------------- BRUTE FORCE APPROACH ----------------
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Idea: Traverse the array and compare pairs.
    // Since every element appears twice except one,
    // the unique element will not have a duplicate next to it.
    int singleNonDuplicateBrute(vector<int>& nums) {
        int n = nums.size();

        // If only one element exists
        if (n == 1) return nums[0];

        for (int i = 0; i < n; i++) {
            // Check first element
            if (i == 0 && nums[i] != nums[i + 1]) return nums[i];
            // Check last element
            if (i == n - 1 && nums[i] != nums[i - 1]) return nums[i];
            // Check middle elements
            if (i > 0 && i < n - 1 && nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                return nums[i];
        }
        return -1; // should not happen
    }

    // ---------------- OPTIMAL BINARY SEARCH APPROACH ----------------
    // Time Complexity: O(log n)
    // Space Complexity: O(1)
    // Idea: Use index parity (even/odd) to detect where the pairing breaks.
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        // Edge case: single element array
        if (n == 1) return nums[0];

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Edge checks
            if (mid == 0 && nums[mid] != nums[mid + 1]) return nums[mid];
            if (mid == n - 1 && nums[mid] != nums[mid - 1]) return nums[mid];

            // If mid is the unique element
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // If mid is even, the pair should start at mid (mid, mid+1)
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) {
                    // Pair is valid → move right
                    low = mid + 2;
                } else {
                    // Pair is broken → unique lies on left side
                    high = mid - 1;
                }
            }
            // If mid is odd, the pair should end at mid (mid-1, mid)
            else {
                if (nums[mid] == nums[mid - 1]) {
                    // Pair is valid → move right
                    low = mid + 1;
                } else {
                    // Pair is broken → unique lies on left side
                    high = mid - 1;
                }
            }
        }
        return -1; // should never reach here if input is valid
    }
};
