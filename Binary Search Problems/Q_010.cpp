/*
--------------------------------------------------------
Find how many times a sorted array has been rotated
--------------------------------------------------------
Brute Force:
- Traverse array, find index of minimum element.
- Time: O(N), Space: O(1)

Optimal (Binary Search):
- Use binary search to locate the index of minimum element.
- That index = rotation count.
- Time: O(log N), Space: O(1)
--------------------------------------------------------
*/

// Brute Force Approach
int countRotationsBrute(vector<int>& nums) {
    int n = nums.size();
    int mn = nums[0], idx = 0;

    for (int i = 1; i < n; i++) {
        if (nums[i] < mn) {
            mn = nums[i];
            idx = i;
        }
    }
    return idx; // rotation count
}

// Optimal Approach (Binary Search)
int countRotationsOptimal(vector<int>& nums) {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        // if mid element is smaller than rightmost → min is in left half
        if (nums[mid] < nums[high]) {
            high = mid;
        } 
        else {
            low = mid + 1;
        }
    }
    return low; // index of min element = rotation count
}

