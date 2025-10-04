

/*
🧠 PROBLEM:
Given a sorted array 'arr' of positive integers (without duplicates),
and an integer 'k', find the k-th missing positive number.

Example:
arr = [2, 3, 4, 7, 11], k = 5
→ Missing numbers = [1, 5, 6, 8, 9, 10, ...]
→ The 5th missing number is 9
*/

/*----------------------------------------------------------
🚀 APPROACH: SINGLE PASS (O(n))
------------------------------------------------------------
💡 Intuition:
If no elements were missing, the i-th element in array
should be equal to i+1.

→ Whenever arr[i] <= k, it means till that point,
  there are fewer missing numbers than k.
  So we increase k because one extra number is present in the array.

Example Dry Run:
arr = [2,3,4,7,11], k = 5

i=0 → arr[i]=2 <= 5 → k=6
i=1 → arr[i]=3 <= 6 → k=7
i=2 → arr[i]=4 <= 7 → k=8
i=3 → arr[i]=7 <= 8 → k=9
i=4 → arr[i]=11 > 9 → stop

✅ Answer = k = 9
------------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------------------------*/
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();

    // iterate over all elements
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            // if arr[i] is smaller or equal to k,
            // it means that number is not missing,
            // so next missing number will be pushed further → increase k
            k++;
        } else {
            // once arr[i] > k, stop because kth missing number lies before this
            break;
        }
    }

    // return final value of k which is kth missing number
    return k;
}


/*-----------------------------------------------------------
 ⚡ OPTIMAL BINARY SEARCH APPROACH
 Idea:
 1. For each index 'mid', count how many numbers are missing till arr[mid].
    → missing = arr[mid] - (mid + 1)
    (because if no numbers were missing, arr[mid] would equal mid+1)
 2. If missing < k → search on right (we need more missing numbers)
    Else → search left.
 3. Finally, low points to the position where the kth missing would be.
 4. Formula for answer: low + k

 Example: arr=[2,3,4,7,11], k=5
 Step-by-step:
   mid=2 → arr[mid]=4 → missing=4-(2+1)=1 (<5) → low=3
   mid=3 → arr[mid]=7 → missing=7-(3+1)=3 (<5) → low=4
   mid=4 → arr[mid]=11 → missing=11-(4+1)=6 (>5) → high=3
   loop ends → low=4
   answer = low + k = 4 + 5 = 9 ✅

 Time Complexity: O(log n)
 Space Complexity: O(1)
-----------------------------------------------------------*/
int findKthPositiveBinary(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            low = mid + 1;  // need to look on right side
        else
            high = mid - 1; // look on left
    }

    return low + k; // formula derived from binary search pattern
}

