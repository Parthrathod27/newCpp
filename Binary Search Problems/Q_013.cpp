/*
Problem: Given a non-negative integer x, return the floor value of its square root.
Example: x = 8 → sqrt(8) ≈ 2.82 → return 2
*/

/* -------------------- BRUTE FORCE APPROACH --------------------
   Idea: Start from i = 1, keep checking i*i <= x.
   The last valid i will be the answer.
   Time Complexity: O(√x)
   Space Complexity: O(1)
*/
class BruteForceSolution {
public:
    int mySqrt(int x) {
        long long ans = 0;
        for(long long i = 1; i * i <= x; i++) {
            ans = i; // store the last valid i
        }
        return (int)ans;
    }
};

/* -------------------- OPTIMIZED APPROACH (BINARY SEARCH) --------------------
   Idea: Search in range [1, x] for sqrt(x).
   If mid*mid <= x, move right, else move left.
   Time Complexity: O(log x)
   Space Complexity: O(1)
*/
class BinarySearchSolution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x; // edge cases

        long long low = 1, high = x, ans = 0;
        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(mid * mid == x) return mid;   // perfect square
            else if(mid * mid < x) {
                ans = mid;      // store as possible answer
                low = mid + 1;  // move right
            }
            else {
                high = mid - 1; // move left
            }
        }
        return (int)ans;
    }
};
