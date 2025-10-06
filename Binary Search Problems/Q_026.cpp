 std;

/*
---------------------------------------------
🧩 PROBLEM:
Given two sorted arrays `arr1` and `arr2` and an integer `k`,
find the K-th smallest element in the merged sorted array.

---------------------------------------------
🔹 EXAMPLE:
arr1 = [2, 3, 4, 10, 15]
arr2 = [1, 5, 8, 12, 14, 18]
k = 5
✅ Output → 5
(Because merged = [1,2,3,4,5,8,10,12,14,15,18])

---------------------------------------------
APPROACH 1️⃣: BRUTE FORCE
---------------------------------------------
🧠 IDEA:
- Merge both arrays into a single sorted array.
- Return the element at index k-1 (0-based).
- Time: O((n+m) log(n+m)), Space: O(n+m)
---------------------------------------------
*/
int kthElement_Brute(vector<int>& arr1, vector<int>& arr2, int k) {
    vector<int> merged;
    merged.reserve(arr1.size() + arr2.size());
    merged.insert(merged.end(), arr1.begin(), arr1.end());
    merged.insert(merged.end(), arr2.begin(), arr2.end());
    sort(merged.begin(), merged.end());
    return merged[k - 1];
}

/*
---------------------------------------------
APPROACH 2️⃣: MERGE LIKE MERGE SORT
---------------------------------------------
🧠 IDEA:
- Use two pointers (i, j) to merge arrays up to the k-th element.
- No need to store full merged array.
- Time: O(k), Space: O(1)
---------------------------------------------
*/
int kthElement_Merge(vector<int>& arr1, vector<int>& arr2, int k) {
    int n1 = arr1.size(), n2 = arr2.size();
    int i = 0, j = 0, count = 0;
    int ans = -1;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            count++;
            if (count == k) return arr1[i];
            i++;
        } else {
            count++;
            if (count == k) return arr2[j];
            j++;
        }
    }
    // if elements left in arr1
    while (i < n1) {
        count++;
        if (count == k) return arr1[i];
        i++;
    }
    // if elements left in arr2
    while (j < n2) {
        count++;
        if (count == k) return arr2[j];
        j++;
    }
    return ans;
}

/*
---------------------------------------------
APPROACH 3️⃣: BINARY SEARCH (OPTIMAL)
---------------------------------------------
🧠 IDEA:
- Similar to "Median of Two Sorted Arrays".
- Partition both arrays such that:
  left part has exactly k elements in total.
- Use binary search on the smaller array.
- Time: O(log(min(n, m))), Space: O(1)

🧩 EXPLANATION:
1️⃣ Choose cut1 in arr1 → elements in left part = cut1
2️⃣ Then cut2 = k - cut1 in arr2
3️⃣ Check:
   left1 ≤ right2 and left2 ≤ right1
   → If true, found partition.
4️⃣ Otherwise, adjust binary search accordingly.

---------------------------------------------
*/
int kthElement_BinarySearch(vector<int>& arr1, vector<int>& arr2, int k) {
    int n1 = arr1.size(), n2 = arr2.size();
    if (n1 > n2) return kthElement_BinarySearch(arr2, arr1, k); // ensure smaller array first
    
    int low = max(0, k - n2), high = min(k, n1);

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = k - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int right1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            return max(left1, left2);
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }
    return -1;
}
