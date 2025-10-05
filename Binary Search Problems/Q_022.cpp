class Solution {
public:
    // 🔹 Helper: Sum of all array elements
    int sumArr(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
        }
        return count;
    }

    // 🔹 Helper: How many parts (students) needed 
    // if each part can't exceed 'x' pages
    int splitArr(vector<int>& nums, int x) {
        int count = 1;      // at least 1 student
        int lastSum = 0;    // pages allocated to current student
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + lastSum <= x) {
                lastSum += nums[i];  // add book to current student
            } else {
                count++;             // need a new student
                lastSum = nums[i];   // start new student's allocation
            }
        }
        return count;
    }

    // 🔹 Brute Force: Try every possible 'max pages'
    int splitArrayBrute(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;  // not enough books for students

        int low = *max_element(nums.begin(), nums.end());  // minimum possible max
        int high = sumArr(nums);                          // maximum possible max
        int ans = -1;

        // check every possible page limit
        for (int i = low; i <= high; i++) {
            int val = splitArr(nums, i); // how many students needed if max pages=i
            if (val <= k) {              // if students <= k, it’s valid
                ans = i;                 // record answer
                break;                   // break because we want the first (minimum) i
            }
        }
        return ans;
    }
};


/*
Instead of checking every possible max pages sequentially,
we can binary search over the range [max(nums), sum(nums)].

We:

Compute mid = (low + high)/2

Check if we can allocate with max pages = mid

If yes → try smaller max pages (high = mid - 1)

If no → increase max pages (low = mid + 1)
*/

class Solution {
public:
    // 🔹 Helper: sum of all array elements
    int sumArr(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i];
        }
        return count;
    }

    // 🔹 Helper: how many parts (students) needed if max pages allowed = x
    int splitArr(vector<int>& nums, int x) {
        int count = 1;       // at least one student
        int lastSum = 0;     // pages allocated to current student
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] + lastSum <= x) {
                lastSum += nums[i];    // add book to current student
            } else {
                count++;               // need new student
                lastSum = nums[i];
            }
        }
        return count;
    }

    // 🔹 Optimized: Binary search on answer
    int splitArray(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;   // not enough books

        int low = *max_element(nums.begin(), nums.end());
        int high = sumArr(nums);

        // binary search over possible max pages
        while (low <= high) {
            int mid = (low + high) / 2;    // guess a max pages
            int val = splitArr(nums, mid); // how many students needed?

            if (val <= k) {
                // we can allocate with mid pages, try smaller max pages
                high = mid - 1;
            } else {
                // can't allocate, need more pages
                low = mid + 1;
            }
        }
        return low; // low = smallest max pages possible
    }
};
