/*
------------------------------------------------------------
🧩 PROBLEM:
Given a row-wise sorted matrix of size N x M (each row is sorted in non-decreasing order),
find the median of the matrix.

------------------------------------------------------------
🔹 Example:
Input:
mat = {
  {1, 3, 5},
  {2, 6, 9},
  {3, 6, 9}
}

✅ Output: 5
Explanation: The elements in sorted order are:
[1, 2, 3, 3, 5, 6, 6, 9, 9]
Median = 5 (middle element)

------------------------------------------------------------
APPROACH 1️⃣: BRUTE FORCE
------------------------------------------------------------
🧠 IDEA:
- Traverse through all matrix elements.
- Store them in a single vector.
- Sort the vector.
- Return the middle element.

🕒 Time Complexity: O(N*M * log(N*M))
🧠 Space Complexity: O(N*M)
⚠️ Simple but inefficient for large matrices.
------------------------------------------------------------
*/
int medianBrute(vector<vector<int>> &mat) {
    vector<int> vals;
    int n = mat.size(), m = mat[0].size();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vals.push_back(mat[i][j]);

    sort(vals.begin(), vals.end());
    int total = n * m;
    return vals[total / 2];
}

/*
------------------------------------------------------------
APPROACH 2️⃣: MERGE ROWS (BETTER APPROACH)
------------------------------------------------------------
🧠 IDEA:
- Each row is sorted.
- Merge all rows into one sorted array using a min-heap (similar to merging K sorted lists).
- Stop once we reach the median position.

🕒 Time Complexity: O(N*M * log(N))
🧠 Space Complexity: O(N)
⚡ Better than brute force, avoids sorting the entire array manually.
------------------------------------------------------------
*/
int medianMergeRows(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    // Min heap storing {value, row, col}
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({mat[i][0], i, 0});
    }

    int medianPos = (n * m) / 2;
    int count = 0, val = -1;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        val = top[0];
        int r = top[1], c = top[2];

        if (++count > medianPos) break;

        if (c + 1 < m)
            pq.push({mat[r][c + 1], r, c + 1});
    }

    return val;
}

/*
------------------------------------------------------------
APPROACH 3️⃣: OPTIMAL (BINARY SEARCH ON VALUE RANGE)
------------------------------------------------------------
🧠 IDEA:
- The matrix rows are sorted.
- The median lies between the smallest element and the largest element.
- Apply binary search on this value range.
- For each mid value:
  → Count how many numbers in the matrix are ≤ mid.
  → Use upper_bound() for each row to count efficiently.
- If count <= half of total elements → move right.
  Else → move left.

🧮 Median = smallest number such that at least half of the elements ≤ it.

🕒 Time Complexity: O(32 * N * log M)
🧠 Space Complexity: O(1)
⚡ Most efficient and standard solution for interview problems.
------------------------------------------------------------
*/
int countLessEqual(vector<int>& row, int x) {
    return upper_bound(row.begin(), row.end(), x) - row.begin();
}

int medianBinarySearch(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();

    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++) {
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m - 1]);
    }

    int desired = (n * m + 1) / 2;

    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        for (int i = 0; i < n; i++) {
            count += countLessEqual(mat[i], mid);
        }

        if (count < desired)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

