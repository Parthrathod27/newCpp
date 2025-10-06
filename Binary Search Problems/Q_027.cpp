 std;

/*
------------------------------------------------------------
🧩 PROBLEM:
Given a boolean matrix (only 0s and 1s) where each row is sorted
(i.e., all 0s come before 1s), find the index of the row 
with the maximum number of 1s.

If there are multiple rows with the same number of 1s,
return the index of the first such row.

------------------------------------------------------------
🔹 EXAMPLE:
Input:
mat = {
    {0, 1, 1, 1},
    {0, 0, 1, 1},
    {1, 1, 1, 1},
    {0, 0, 0, 0}
}
✅ Output: 2
(Row index 2 has 4 ones)

------------------------------------------------------------
APPROACH 1️⃣: BRUTE FORCE
------------------------------------------------------------
🧠 IDEA:
- Traverse every element in every row.
- Count the number of 1s for each row.
- Keep track of the row having the maximum 1s.
- Time: O(N*M)
- Space: O(1)
------------------------------------------------------------
*/
int rowWithMax1s_Brute(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int maxCount = 0;
    int ans = -1;
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            ans = i;
        }
    }
    return ans;
}

/*
------------------------------------------------------------
APPROACH 2️⃣: BINARY SEARCH (Using sorted row property)
------------------------------------------------------------
🧠 IDEA:
- Each row is sorted: all 0s then all 1s.
- Use binary search in each row to find the first 1.
- Number of 1s = (m - indexOfFirst1)
- Keep track of row with max 1s.
- Time: O(N * log M)
- Space: O(1)
------------------------------------------------------------
*/
int rowWithMax1s_BinarySearch(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int ans = -1;
    int maxOnes = 0;
    
    for (int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        int firstOneIdx = m; // default = no 1s found
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mat[i][mid] == 1) {
                firstOneIdx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        int countOnes = m - firstOneIdx;
        if (countOnes > maxOnes) {
            maxOnes = countOnes;
            ans = i;
        }
    }
    return ans;
}

/*
------------------------------------------------------------
APPROACH 3️⃣: OPTIMAL (Top-Right Corner Traversal)
------------------------------------------------------------
🧠 IDEA:
- Start from top-right corner (row = 0, col = m-1)
- If you find a 1 → move left (since all elements below also have 1s in this column)
- If you find a 0 → move down (since this row cannot have more 1s)
- Keep track of row index where you moved left (means more 1s).
- Time: O(N + M)
- Space: O(1)

🧩 INTUITION:
Because the matrix rows are sorted, moving left decreases 1 count
and moving down goes to a potentially better row.

------------------------------------------------------------
*/
int rowWithMax1s_Optimal(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    int j = m - 1;
    int ans = -1;
    
    for (int i = 0; i < n; i++) {
        while (j >= 0 && mat[i][j] == 1) {
            ans = i;
            j--;
        }
    }
    return ans;
}

