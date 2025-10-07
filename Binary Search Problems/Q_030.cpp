/*
------------------------------------------------------------
🧩 PROBLEM:
You are given a 2D grid 'mat' of integers, where you must 
find the position of a "peak element".

A peak element in a 2D matrix is one that is **strictly greater**
than all of its adjacent cells (top, bottom, left, right).

You can return the index (row, col) of any one peak element.

------------------------------------------------------------
🔹 Example:
Input:
mat = {
  {10, 20, 15},
  {21, 30, 14},
  {7, 16, 32}
}

✅ Output: [1, 1]  (since 30 is greater than its top, bottom, left, right)

------------------------------------------------------------
APPROACH 1️⃣: BRUTE FORCE
------------------------------------------------------------
🧠 IDEA:
- Traverse every element of the matrix.
- For each element (i, j), compare it with its 4 neighbors:
  (up, down, left, right).
- If it’s greater than all neighbors, return (i, j).

🕒 Time Complexity: O(N*M)
🧠 Space Complexity: O(1)
------------------------------------------------------------
*/
pair<int, int> findPeak2D_Brute(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    auto isPeak = [&](int i, int j) -> bool {
        int val = mat[i][j];
        if (i > 0 && mat[i - 1][j] >= val) return false;
        if (i < n - 1 && mat[i + 1][j] >= val) return false;
        if (j > 0 && mat[i][j - 1] >= val) return false;
        if (j < m - 1 && mat[i][j + 1] >= val) return false;
        return true;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (isPeak(i, j))
                return {i, j};
        }
    }
    return {-1, -1};
}

/*
------------------------------------------------------------
APPROACH 2️⃣: ROW-WISE MAX ELEMENT METHOD
------------------------------------------------------------
🧠 IDEA:
- For every row:
  → Find the column index of the **maximum element** in that row.
- Check whether this element is greater than its top and bottom neighbor.
  If yes, that’s our peak.
- If not, move to next row.

🕒 Time Complexity: O(N*M)
🧠 Space Complexity: O(1)
⚡ Faster than brute because we check fewer cells (one per row).
------------------------------------------------------------
*/
pair<int, int> findPeak2D_RowMax(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++) {
        // Find index of maximum element in this row
        int colMax = max_element(mat[i].begin(), mat[i].end()) - mat[i].begin();

        int top = (i > 0) ? mat[i - 1][colMax] : -1;
        int bottom = (i < n - 1) ? mat[i + 1][colMax] : -1;
        int curr = mat[i][colMax];

        if (curr > top && curr > bottom)
            return {i, colMax};
    }
    return {-1, -1};
}

/*
------------------------------------------------------------
APPROACH 3️⃣: OPTIMAL BINARY SEARCH ON COLUMNS
------------------------------------------------------------
🧠 IDEA:
- Apply **binary search on columns**.
- For each mid column:
   → Find the row having the **maximum value** in that column.
   → Check if this element is a peak:
        * Compare with left and right neighbors.
   → If left neighbor > current → move search to LEFT half.
   → If right neighbor > current → move search to RIGHT half.
   → Else → current element is the peak.

🧮 WHY IT WORKS:
- Because at each step, we eliminate one half of the columns.
- This guarantees logarithmic reduction in search space.

🕒 Time Complexity: O(N * log M)
🧠 Space Complexity: O(1)
⚡ Most efficient approach for large matrices.

------------------------------------------------------------
*/
pair<int, int> findPeak2D_BinarySearch(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int left = 0, right = m - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // Find row with maximum element in this column
        int maxRow = 0;
        for (int i = 0; i < n; i++) {
            if (mat[i][mid] > mat[maxRow][mid])
                maxRow = i;
        }

        int curr = mat[maxRow][mid];
        int leftVal = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
        int rightVal = (mid + 1 < m) ? mat[maxRow][mid + 1] : -1;

        // Check if peak
        if (curr > leftVal && curr > rightVal)
            return {maxRow, mid};
        else if (leftVal > curr)
            right = mid - 1;  // search left half
        else
            left = mid + 1;   // search right half
    }

    return {-1, -1};
}

