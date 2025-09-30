/*
-------------------------------------------------------
Brute Force Approach
-------------------------------------------------------
- Loop through the array.
- For each element, compare it with x.
- If it matches, increase the counter.
- Time Complexity: O(N)
- Space Complexity: O(1)
-------------------------------------------------------
*/
int countOccurrencesBrute(vector<int>& nums, int x) {
    int count = 0;
    for (int val : nums) {
        if (val == x) count++;
    }
    return count;
}


/*
-------------------------------------------------------
Optimized Approach (Binary Search using STL)
-------------------------------------------------------
- Since nums[] is sorted, we can use:
    * lower_bound(nums.begin(), nums.end(), x)
      → gives first index where x could appear
    * upper_bound(nums.begin(), nums.end(), x)
      → gives index just after last occurrence of x
- Count = (upper_bound - lower_bound)
- Time Complexity: O(log N)
- Space Complexity: O(1)
-------------------------------------------------------
*/
int countOccurrencesOptimized(vector<int>& nums, int x) {
    auto first = lower_bound(nums.begin(), nums.end(), x);
    auto last = upper_bound(nums.begin(), nums.end(), x);
    return last - first; // difference = count
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10}; // sorted input
    int x = 8; // element to count

    cout << "Optimized Count of " << x << ": "
         << countOccurrencesOptimized(nums, x) << endl;

    return 0;
}

