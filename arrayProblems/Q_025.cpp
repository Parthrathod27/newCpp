/*<<<<<Print Spiral Matrix>>>>>*/


/*approch:We traverse the matrix layer by layer in four directions:
  Left → Right (top row)
  Top → Bottom (right column)
  Right → Left (bottom row)
  Bottom → Top (left column)
After completing one "layer", move inward and repeat until all elements are covered.*/

/*steps:Initialize boundaries:
   top = 0, bottom = m - 1
   left = 0, right = n - 1
While top <= bottom && left <= right:
   Traverse top row: left → right, then top++
   Traverse right column: top → bottom, then right--
   If still valid, traverse bottom row: right → left, then bottom--
   If still valid, traverse left column: bottom → top, then left++*/

code:class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // Left -> Right
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};


//Time: O(m × n) → we visit each element onc,Space: O(1) (excluding output). 
