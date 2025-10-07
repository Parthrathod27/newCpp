 std;

/*
------------------------------------------------------------
🧩 PROBLEM:
Given an m x n matrix, where each row is sorted in ascending order,
and the first element of each row is greater than the last element 
of the previous row.

You need to determine if a given target value exists in the matrix.

------------------------------------------------------------
🔹 EXAMPLE:
Input:
matrix = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
}
target = 3

✅ Output: true (since 3 exists in matrix)
------------------------------------------------------------

Now let's explore **all approaches** from brute force to optimal.

------------------------------------------------------------
APPROACH 1️⃣: BRUTE FORCE
------------------------------------------------------------
🧠 IDEA:
- Traverse every element in the matrix and check if it matches target.
- If found, return true.
- Else, after traversal, return false.

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
APPROACH 2️⃣: BINARY SEARCH (Row-wise + Column-wise)
------------------------------------------------------------
🧠 IDEA:
- Since each row is sorted and the first element of each row
  is greater than the last element of the previous row:
  ✅ The matrix behaves like a sorted 1D array.

Steps:
1️⃣ First, find which row could contain the target.
   (Compare target with first and last elements of rows)
2️⃣ Once the row is identified, do binary search in that row.

🕒 Time Complexity: O(logN + logM)
🧠 Space Complexity: O(1)
------------------------------------------------------------
*/
bool searchMatrix_BinaryRow(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int top = 0, bottom = n - 1, row = -1;

    // Step 1: Identify the row
    while (top <= bottom) {
        int mid = (top + bottom) / 2;
        if (target >= mat[mid][0] && target <= mat[mid][m - 1]) {
            row = mid;
            break;
        } else if (target < mat[mid][0]) {
            bottom = mid - 1;
        } else {
            top = mid + 1;
        }
    }

    if (row == -1) return false; // target out of matrix range

    // Step 2: Binary search within the found row
    int l = 0, r = m - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mat[row][mid] == target)
            return true;
        else if (mat[row][mid] < target)
            l = mid + 1;
        else
            r = mid - 1;
    }

    return false;
}

/*
------------------------------------------------------------
APPROACH 3️⃣: OPTIMAL (Treat Matrix as a Flattened 1D Array)
------------------------------------------------------------
🧠 IDEA:
- The matrix is sorted both row-wise and column-wise (as per given property).
- We can **treat the entire matrix as a single sorted array** of length (N*M).
- Perform a normal binary search from index 0 → N*M - 1.
- Convert the 1D index into (row, col) as:
  row = mid / M
  col = mid % M

🕒 Time Complexity: O(log(N*M))
🧠 Space Complexity: O(1)

⚡ Fastest method for this problem.
------------------------------------------------------------
*/
bool searchMatrix_Optimal(vector<vector<int>>& mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = n * m - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;

        if (mat[row][col] == target)
            return true;
        else if (mat[row][col] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

