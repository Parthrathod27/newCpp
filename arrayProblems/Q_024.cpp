/*<<<<<Rotate Matrix/Image by 90 Degrees | Brute - Optimal>>>>>*/


/*brute force approch:Got it 👍 Here’s just the overview of brute force approach to rotate a matrix 90° clockwise:
Create a new matrix B of size [cols × rows] (since dimensions swap after rotation).
For each element A[i][j] in the original:
Place it in B[j][rows - 1 - i].
Copy B back to A.
Time Complexity: O(R * C)
Space Complexity: O(R * C)
👉 Works for both square and rectangular matrices.*/


code:class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n=matrix.size();
       vector<vector<int>>arr(n,vector<int>(n,0));
       for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
             arr[j][n-1-i]=matrix[i][j];
          }
       }
      matrix=arr;
   }
};




/*optimize approch:We avoid using extra space (O(1) space).
The trick is:
Transpose the matrix → Swap rows and columns.
  matrix[i][j] ↔ matrix[j][i] for all i < j.
  Turns rows into columns.
Reverse each row → Flip elements horizontally.
  This makes the matrix rotated by 90° clockwise.*/


code:class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
       int n=arr.size();
     //transpose the column
       for(int i=0;i<n-1;i++){
           for(int j=i+1;j<n;j++){
              swap(arr[i][j],arr[j][i]);
           }
       }
    //reverse the row
       for(int i=0;i<n;i++){
          reverse(arr[i].begin(),arr[i].end());
       }
    }
 };
