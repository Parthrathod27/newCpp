/*<<<<<pascal's problem>>>>>*/

//there are three type of pascal's problem :-

// Type:1] we get the location in the pascal's trangle and we have to find what element is present at that location

/*approch:we know that nCr formula = n!/r! x (n-r)!
Understand indexing
  If indexing starts from 0:
  Row r has r+1 elements.
  The element at column c is C(r, c).
  If indexing starts from 1: adjust by subtracting 1.
Direct Formula
  Instead of computing factorials (which may cause overflow and TLE), we compute using a loop 
  C(r, c) = (r * (r-1) * (r-2) * ... * (r-c+1)) / (1 * 2 * 3 * ... * c)*/

code:

   long long nCr(int n, int r) {
    long long res = 1;
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}


// Type:2]we have to return a entire row where we have given the row which we have to print

/*
Pascal's Triangle Row (rowIndex = n)

Each element in row n is given by the Binomial Coefficient:

   C(n, r) = n! / (r! * (n-r)!)

We can compute row n iteratively without factorials:

Start with ans = 1
For each r from 1 → n:
    ans = ans * (n - r + 1) / r
    push ans into row

Example: n = 4
Row = [1, 4, 6, 4, 1]

Time Complexity: O(n)
Space Complexity: O(1) extra
*/


code:

vector<int>generateRow(int num){
        vector<int>ansRow;
        long long ans=1;
        ansRow.push_back(ans);
        for(int i=1;i<num;i++){
            ans=(ans*(num-i))/i;
            ansRow.push_back(ans);
        }
       return ansRow;
    }


// Type 3:here we will return the list in which the entire pascl's trangle is stored in form of list 

/*
approch:

Pascal's Triangle (numRows)

We need to return the entire triangle as a list of lists.

Rule:
  - First and last element of every row is always 1.
  - Any inner element is the sum of two elements just above it:
        row[i][j] = row[i-1][j-1] + row[i-1][j]

Example: numRows = 5
Triangle =
[
   [1],
   [1, 1],
   [1, 2, 1],
   [1, 3, 3, 1],
   [1, 4, 6, 4, 1]
]

Time Complexity: O(n^2)   (we build all rows)
Space Complexity: O(n^2)  (we store entire triangle)
*/


code:
class Solution {
public:
    vector<int>generateRow(int num){
        vector<int>ansRow;
        long long ans=1;
        ansRow.push_back(ans);
        for(int i=1;i<num;i++){
            ans=(ans*(num-i))/i;
            ansRow.push_back(ans);
        }
       return ansRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};

