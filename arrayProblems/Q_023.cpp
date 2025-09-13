/*<<<<<Set Matrix to Zero>>>>>*/

/*brute force approch:1]const int MARK = INT_MIN + 1;
   Defines a constant marker value used to temporarily mark cells that should become 0.
  (Idea: use a value different from 0 so we can distinguish original zeros from marked cells.)
2]void markRow(int i, vector<vector<int>>& nums, int m)
    Purpose: mark every element in row i (except actual 0 cells) with MARK.
    Loop: for (int j = 0; j < m; j++)
    If nums[i][j] != 0 → set nums[i][j] = MARK.
    Important: original 0 cells in the row are left as 0.
3]void markColm(int j, vector<vector<int>>& nums, int n)
    Purpose: the column version of markRow. Mark every element in column j (except actual zeros) with MARK.
    Loop over rows and set nums[i][j] = MARK if it is not already 0.
4]void setZeroes(vector<vector<int>>& nums) — main function:
    int n = nums.size(); int m = nums[0].size();
    Get matrix dimensions. (Note: code assumes nums is non-empty.)
    bool hasZero = false;
    Scans the whole matrix once to check if there is at least one zero.
    if (!hasZero) return;
    If no zeros, do nothing and return early (fast path).
Step 1 — marking pass:
Double loop for (i ... ) for (j ... ):
When nums[i][j] == 0 is found, call markRow(i, nums, m) and markColm(j, nums, n).
These calls mark all nonzero elements in row i and column j with MARK.
Because markRow/markColm skip existing 0s, original zeros remain 0.
Marking is idempotent: repeatedly marking a cell that is already MARK does nothing harmful.
Step 2 — conversion pass:
Another double loop converts every MARK to 0:
if (nums[i][j] == MARK) nums[i][j] = 0;
End: matrix is updated in place.*/

code:
 class Solution {
public:
    const int MARK = INT_MIN + 1;  // special marker, unlikely to exist in input

    void markRow(int i, vector<vector<int>>& nums, int m) {
        for (int j = 0; j < m; j++) {
            if (nums[i][j] != 0) {
                nums[i][j] = MARK;
            }
        }
    }

    void markColm(int j, vector<vector<int>>& nums, int n) {
        for (int i = 0; i < n; i++) {
            if (nums[i][j] != 0) {
                nums[i][j] = MARK;
            }
        }
    }

    void setZeroes(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        
        bool hasZero = false;   // check if there is at least one zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 0) {
                    hasZero = true;
                    break;
                }
            }
            if (hasZero) break;
        }

        if (!hasZero) return;  // no zeros, nothing to do

        // Step 1: mark
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 0) {
                    markRow(i, nums, m);
                    markColm(j, nums, n);
                }
            }
        }

        // Step 2: convert MARK to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == MARK) {
                    nums[i][j] = 0;
                }
            }
        }
    }
};


/*better approch:Idea of the solution
Instead of directly modifying the matrix when we see a 0 (which would cause problems because one change may create new zeros), we use a two-step process:
   Marking step → find which rows and columns need to be zeroed.
   Updating step → actually set those rows and columns to zero.
How to store marks
We use:
    An array row[n] where row[i] = 1 means row i must be zeroed.
    An array col[m] where col[j] = 1 means column j must be zeroed.
    This avoids modifying the matrix until we’re sure which rows/cols must be zero.
Algorithm in words
   Scan the matrix.
   For every nums[i][j] == 0, mark row[i] = 1 and col[j] = 1.
   Update the matrix.
   For every cell (i, j), if row[i] == 1 or col[j] == 1, set nums[i][j] = 0.*/

code:class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        bool hasZero = false;   // flag

        // check if at least one zero exists
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 0) {
                    hasZero = true;
                    break;
                }
            }
            if (hasZero) break;
        }

        if (!hasZero) return;

        // mark rows and cols
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // update matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    nums[i][j] = 0;
                }
            }
        }
    }
};



/*optimize approch:Problem
If we use extra arrays row[] and col[], it takes O(n + m) space.
But we can reuse the matrix itself as markers instead of extra arrays.
Key insight
We can use:
  The first row of the matrix to mark which columns should be zeroed.
  The first column of the matrix to mark which rows should be zeroed.
  But there’s a catch: what if the first row/column themselves contain zeros?
👉 We need two extra flags:
  firstRowZero → whether the first row should be zeroed.
  firstColZero → whether the first column should be zeroed.
Step-by-step algorithm:-
Check first row & first column
  Scan them separately to set firstRowZero and firstColZero.
Mark the rest of the matrix
  For every cell (i, j) (except first row/col),
  if nums[i][j] == 0, mark it by setting:
  nums[i][0] = 0 → mark row i.
  nums[0][j] = 0 → mark column j.
Zero out the inner matrix
  For every cell (i, j) (except first row/col),
  if nums[i][0] == 0 or nums[0][j] == 0, set nums[i][j] = 0.
Finally, handle first row & first column
  If firstRowZero == true, set the whole first row to 0.
  If firstColZero == true, set the whole first column to 0.*/

code:-class Solution {
public:
    void setZeroes(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();

        bool firstRowZero = false, firstColZero = false;

        // Step 1: check first row
        for (int j = 0; j < m; j++) {
            if (nums[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Step 1: check first column
        for (int i = 0; i < n; i++) {
            if (nums[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Step 2: mark rows & columns using first row/col
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (nums[i][j] == 0) {
                    nums[i][0] = 0;
                    nums[0][j] = 0;
                }
            }
        }

        // Step 3: zero out cells based on marks
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (nums[i][0] == 0 || nums[0][j] == 0) {
                    nums[i][j] = 0;
                }
            }
        }

        // Step 4: handle first row
        if (firstRowZero) {
            for (int j = 0; j < m; j++) nums[0][j] = 0;
        }

        // Step 4: handle first column
        if (firstColZero) {
            for (int i = 0; i < n; i++) nums[i][0] = 0;
        }
    }
};

