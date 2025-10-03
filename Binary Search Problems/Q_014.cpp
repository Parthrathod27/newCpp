
class Solution {
public:
    // ---------------------------------------------------
    // 🟢 Brute Force Approach
    // ---------------------------------------------------
    // 1. Loop from x = 1 to m.
    // 2. For each x, calculate x^n.
    // 3. If x^n == m, return x.
    // 4. If no such x exists, return -1.
    // Time Complexity: O(m * n)  --> very slow for large inputs.
    // Space Complexity: O(1).
    int nthRootBrute(int n, int m) {
        for(int x = 1; x <= m; x++) {
            long long ans = 1;
            for(int i = 1; i <= n; i++) {
                ans = ans * x;
                if(ans > m) break;  // stop if already greater than m
            }
            if(ans == m) return x; // found the integer root
        }
        return -1; // no integer root exists
    }

    // ---------------------------------------------------
    // 🟢 Optimal Approach (Binary Search)
    // ---------------------------------------------------
    // Idea:
    // 1. The nth root of m lies between [1, m].
    // 2. Apply Binary Search on this range.
    // 3. For mid = (low+high)/2, calculate mid^n.
    //    - If mid^n == m --> return mid.
    //    - If mid^n < m  --> move to right half (low = mid+1).
    //    - If mid^n > m  --> move to left half (high = mid-1).
    // 4. If no exact root found, return -1.
    // Time Complexity: O(log m * n)
    // Space Complexity: O(1).
    int powerCheck(long long base, int n, int m) {
        long long ans = 1;
        for(int i = 1; i <= n; i++) {
            ans *= base;
            if(ans > m) return 2; // base^n > m
        }
        if(ans == m) return 1;   // base^n == m
        return 0;                // base^n < m
    }

    int nthRootOptimal(int n, int m) {
        int low = 1, high = m;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            int check = powerCheck(mid, n, m);

            if(check == 1) return mid;   // found exact root
            else if(check == 0) low = mid + 1; // move right
            else high = mid - 1; // move left
        }
        return -1; // no integer root
    }
};

