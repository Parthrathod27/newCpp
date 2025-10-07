/*
------------------------------------------------------------
🧩 PROBLEM:
You are given an m x n matrix where each row and column 
is sorted in ascending order. 

Find whether the target value exists in the matrix.

------------------------------------------------------------
🔹 EXAMPLE:
Input:
matrix = {
  {1, 4, 7, 11, 15},
  {2, 5, 8, 12, 19},
  {3, 6, 9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
}
target = 5

✅ Output: true

target = 20
✅ Output: false

------------------------------------------------------------
APPROACH 1️⃣: BRUTE FORCE
------------------------------------------------------------
🧠 IDEA:
- Simply traverse all elements in the matrix.
- Check if any element equals the target.
- If found → return true
- If loop ends → return false

🕒 Time Complexity: O(N*M)
🧠 Space Complexity: O(1)
------------------------------------------------------------
*/
bool searchMatrix_Brute(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == target)
                return true;
        }
    }
    return false;
}

/*
------------------------------------------------------------
APPROACH 2️⃣: BINARY SEARCH ON EACH ROW
------------------------------------------------------------
🧠 IDEA:
- Each row is sorted in ascending order.
- So, for every row, we can perform a binary search.

STEPS:
1️⃣ For each row:
    - If target lies between row[0] and row[m-1]
      → Perform binary search on that row.
    - Else skip that row.
2️⃣ If found, return true.

🕒 Time Complexity: O(N * logM)
🧠 Space Complexity: O(1)
------------------------------------------------------------
*/
bool searchMatrix_BinaryRow(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++) {
        if (target < mat[i][0] || target > mat[i][m - 1])
            continue; // skip this row

        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mat[i][mid] == target)
                return true;
            else if (mat[i][mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    return false;
}

/*
------------------------------------------------------------
APPROACH 3️⃣: OPTIMAL STAIRCASE SEARCH
------------------------------------------------------------
🧠 IDEA:
Since the matrix is sorted both row-wise and column-wise:
  → elements increase left → right
  → elements increase top → bottom

We can start from the **top-right corner**:
  - If current element == target → return true
  - If current element > target → move LEFT (since all elements below are even bigger)
  - If current element < target → move DOWN (since elements on left are smaller)

We "walk down the stairs" eliminating a row or column each time.

🕒 Time Complexity: O(N + M)
🧠 Space Complexity: O(1)
------------------------------------------------------------
*/
bool searchMatrix_Optimal(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int row = 0, col = m - 1;

    while (row < n && col >= 0) {
        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] > target)
            col--; // move left
        else
            row++; // move down
    }
    return false;
}
