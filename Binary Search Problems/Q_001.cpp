/*
    Binary Search Explanation:
    --------------------------
    - Binary Search works on a SORTED array.
    - It divides the search range into half in each step.
    - Time Complexity: O(log n)
    - Space Complexity: O(1) for iterative, O(log n) for recursive (due to call stack).
*/

// Iterative Binary Search
int binarySearchIterative(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // to prevent overflow

        if (arr[mid] == target)
            return mid; // element found at index mid
        else if (arr[mid] < target)
            low = mid + 1; // search in right half
        else
            high = mid - 1; // search in left half
    }

    return -1; // element not found
}

// Recursive Binary Search
int binarySearchRecursive(vector<int>& arr, int low, int high, int target) {
    if (low > high)
        return -1; // base case: not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid; // found
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, high, target); // right half
    else
        return binarySearchRecursive(arr, low, mid - 1, target); // left half
}
