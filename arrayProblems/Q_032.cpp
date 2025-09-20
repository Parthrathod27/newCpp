// ------------------------------------------------------------
// Problem: Find the Missing and Repeating Number
// You are given an array of size n containing numbers from 1 to n.
// One number is missing and one number is repeating.
// Task: Find both numbers.
// ------------------------------------------------------------
//
// Example: arr = {4, 3, 6, 2, 1, 1}
// Output: Repeating = 1, Missing = 5
//
// ------------------------------------------------------------


#include <bits/stdc++.h>
using namespace std;


// ---------------- Approach 1: Brute Force -------------------
// Check each number from 1 to n, count its frequency.
// If freq == 2 → repeating, if freq == 0 → missing.
// Time: O(n^2), Space: O(1) (if no extra array used)
// ------------------------------------------------------------
pair<int,int> findMissingRepeating_Brute(vector<int>& arr) {
    int n = arr.size();
    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) count++;
        }
        if (count == 2) repeating = i;
        else if (count == 0) missing = i;
    }
    return {repeating, missing};
}


// ---------------- Approach 2: Hashing / Frequency Array ------
// Use an extra array (size n+1) to count frequencies.
// Time: O(n), Space: O(n)
// ------------------------------------------------------------
pair<int,int> findMissingRepeating_Hash(vector<int>& arr) {
    int n = arr.size();
    vector<int> freq(n+1, 0);
    int repeating = -1, missing = -1;

    for (int x : arr) freq[x]++;

    for (int i = 1; i <= n; i++) {
        if (freq[i] == 2) repeating = i;
        else if (freq[i] == 0) missing = i;
    }
    return {repeating, missing};
}


// ---------------- Approach 3: Math (Sum & Sum of Squares) ---
// Let sumN = n(n+1)/2 and sumSqN = n(n+1)(2n+1)/6
// Let S = actual sum of array, Sq = actual sum of squares.
// Then:
//   (repeating - missing) = S - sumN
//   (repeating^2 - missing^2) = Sq - sumSqN
// Solve equations to get repeating and missing.
// Time: O(n), Space: O(1)
// ------------------------------------------------------------
pair<int,int> findMissingRepeating_Math(vector<int>& arr) {
    int n = arr.size();
    long long sumN = (1LL * n * (n+1)) / 2;
    long long sumSqN = (1LL * n * (n+1) * (2*n+1)) / 6;

    long long S = 0, Sq = 0;
    for (int x : arr) {
        S += x;
        Sq += 1LL * x * x;
    }

    long long diff = S - sumN;            // repeating - missing
    long long sqDiff = Sq - sumSqN;       // repeating^2 - missing^2
    long long sum = sqDiff / diff;        // repeating + missing

    int repeating = (diff + sum) / 2;
    int missing = repeating - diff;

    return {repeating, missing};
}


// ---------------- Approach 4: XOR Method --------------------
// 1. XOR all elements of array and numbers from 1 to n.
//    This gives xor = missing ^ repeating.
// 2. Find rightmost set bit → divide numbers into 2 buckets.
// 3. XOR separately → get two numbers (one is missing, one repeating).
// 4. Check array to decide which is missing & which is repeating.
// Time: O(n), Space: O(1)
// ------------------------------------------------------------
pair<int,int> findMissingRepeating_XOR(vector<int>& arr) {
    int n = arr.size();
    int xorAll = 0;

    for (int x : arr) xorAll ^= x;
    for (int i = 1; i <= n; i++) xorAll ^= i;

    // rightmost set bit
    int setBit = xorAll & ~(xorAll - 1);

    int x = 0, y = 0;
    for (int num : arr) {
        if (num & setBit) x ^= num;
        else y ^= num;
    }
    for (int i = 1; i <= n; i++) {
        if (i & setBit) x ^= i;
        else y ^= i;
    }

    // Check which is repeating
    int repeating = -1, missing = -1;
    for (int num : arr) {
        if (num == x) {
            repeating = x; missing = y; break;
        }
        if (num == y) {
            repeating = y; missing = x; break;
        }
    }

    return {repeating, missing};
}


// ---------------- Main Function for Testing ----------------
int main() {
    vector<int> arr = {4, 3, 6, 2, 1, 1};

    auto ans1 = findMissingRepeating_Brute(arr);
    cout << "Brute Force -> Repeating: " << ans1.first << ", Missing: " << ans1.second << endl;

    auto ans2 = findMissingRepeating_Hash(arr);
    cout << "Hashing    -> Repeating: " << ans2.first << ", Missing: " << ans2.second << endl;

    auto ans3 = findMissingRepeating_Math(arr);
    cout << "Math       -> Repeating: " << ans3.first << ", Missing: " << ans3.second << endl;

    auto ans4 = findMissingRepeating_XOR(arr);
    cout << "XOR        -> Repeating: " << ans4.first << ", Missing: " << ans4.second << endl;

    return 0;
}

