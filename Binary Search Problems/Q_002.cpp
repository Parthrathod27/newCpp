/*
----------------------------------------------------------
LOWER BOUND & UPPER BOUND IMPLEMENTATION IN C++
----------------------------------------------------------

1. LOWER BOUND:
   - Finds the first index where element >= target.
   - If all elements are smaller, returns n (end of array).
   - Equivalent to C++ STL lower_bound().

   Example:
   arr = [1, 2, 4, 4, 5], target = 4
   lower_bound → index = 2  (first index of 4)

2. UPPER BOUND:
   - Finds the first index where element > target.
   - If all elements <= target, returns n (end of array).
   - Equivalent to C++ STL upper_bound().

   Example:
   arr = [1, 2, 4, 4, 5], target = 4
   upper_bound → index = 4  (first index greater than 4 → 5)

----------------------------------------------------------
*/

int lower_bound_custom(vector<int>& arr, int target) {
    int low = 0, high = arr.size(); // notice: high = n, not n-1
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) {
            low = mid + 1;   // go right
        } else {
            high = mid;      // possible answer, go left
        }
    }
    return low; // returns index of first element >= target
}

int upper_bound_custom(vector<int>& arr, int target) {
    int low = 0, high = arr.size(); 
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;   // go right
        } else {
            high = mid;      // possible answer, go left
        }
    }
    return low; // returns index of first element > target
}

// --------------------------------------------------------
