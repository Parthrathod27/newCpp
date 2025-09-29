/*
------------------------------------------------------
LeetCode 35: Search Insert Position
------------------------------------------------------

Problem:
- You are given a sorted array of distinct integers 
  and a target value.
- Return the index if the target is found.
- If not, return the index where it would be if inserted in order.

Example:
arr = [1, 3, 5, 6], target = 5 → output = 2
arr = [1, 3, 5, 6], target = 2 → output = 1
arr = [1, 3, 5, 6], target = 7 → output = 4
arr = [1, 3, 5, 6], target = 0 → output = 0

------------------------------------------------------
Approach (Binary Search):
1. Maintain two pointers: low = 0, high = n - 1.
2. Perform binary search:
   - If arr[mid] == target → return mid.
   - If arr[mid] < target → move right (low = mid + 1).
   - If arr[mid] > target → move left (high = mid - 1).
3. If target not found:
   - The correct insert position is stored in `low`.
   - Because after binary search, `low` will be pointing
     to the first index >= target.
4. Return low.

Time Complexity: O(log n)
Space Complexity: O(1)

------------------------------------------------------
*/

int searchInsert(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;   // found target
        }
        else if (arr[mid] < target) {
            low = mid + 1; // go right
        }
        else {
            high = mid - 1; // go left
        }
    }
    return low; // insert position
}
