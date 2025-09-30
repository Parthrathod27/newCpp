
/*
---------------------------------------------------
🔹 Problem:
Given a sorted array and a target x, 
find the first and last occurrence of x.
If not found, return -1, -1.

Example:
nums = [5, 7, 7, 8, 8, 10], target = 8
Output = {3, 4}
---------------------------------------------------
*/

/* =================================================
   BRUTE FORCE APPROACH (O(n))
   -------------------------------------------------
   1. Traverse the array linearly.
   2. The first time we see x → mark as "first".
   3. Keep updating "last" whenever we see x again.
   4. If x not found at all, return {-1, -1}.
   ================================================= */
pair<int, int> bruteForce(vector<int>& nums, int x) {
    int first = -1, last = -1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == x) {
            if (first == -1) first = i; // mark first index
            last = i;                   // update last index
        }
    }
    return {first, last};
}

/* =================================================
   OPTIMAL APPROACH (BINARY SEARCH) (O(log n))
   -------------------------------------------------
   We use binary search twice:
   1. First Occurrence → when found, move left.
   2. Last Occurrence → when found, move right.
   ================================================= */

// Find FIRST occurrence of x
int firstOccurrence(vector<int>& nums, int x) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == x) {
            ans = mid;      // store answer
            high = mid - 1; // move left to check earlier indices
        }
        else if (nums[mid] < x) {
            low = mid + 1;  // move right
        }
        else {
            high = mid - 1; // move left
        }
    }
    return ans;
}

// Find LAST occurrence of x
int lastOccurrence(vector<int>& nums, int x) {
    int low = 0, high = nums.size() - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == x) {
            ans = mid;      // store answer
            low = mid + 1;  // move right to check later indices
        }
        else if (nums[mid] < x) {
            low = mid + 1;  // move right
        }
        else {
            high = mid - 1; // move left
        }
    }
    return ans;
}

// Optimal wrapper
pair<int, int> optimal(vector<int>& nums, int x) {
    int first = firstOccurrence(nums, x);
    int last = lastOccurrence(nums, x);
    return {first, last};
}
