 std;

/*
🧠 PROBLEM: Aggressive Cows
You are given N stalls, each having a position. You need to place K cows such that 
the minimum distance between any two cows is as large as possible.

We must return the largest minimum distance possible between any two cows.

Example:
Input:
stalls = [1, 2, 8, 4, 9]
k = 3

Output:
3

Explanation:
We can place cows at positions [1, 4, 8] or [1, 4, 9].
The minimum distance between any two cows = 3.
*/

// ==========================================================
// 🧩 Helper Function
// Checks if we can place `k` cows such that minimum distance
// between any two cows is at least `distance`
// ==========================================================
bool cowPlaceN(vector<int>& arr, int distance, int cow) {
    int n = arr.size();
    int noCow = 1;          // First cow placed at first stall
    int lastCow = arr[0];   // Position of last cow placed
    
    // Traverse the stalls to place remaining cows
    for (int i = 1; i < n; i++) {
        // Check if current stall is far enough from last placed cow
        if (arr[i] - lastCow >= distance) {
            noCow++;               // Place a new cow
            lastCow = arr[i];      // Update position of last placed cow
        }
        // If we successfully placed all cows, return true
        if (noCow >= cow) return true;
    }
    // Couldn’t place all cows with at least `distance` apart
    return false;
}

// ==========================================================
// 🐮 Brute Force Approach
// Try every possible distance from 1 to (max - min) of stalls
// ==========================================================
int aggressiveCows(vector<int> &stalls, int k) {
    // Step 1️⃣ — Sort the stall positions
    sort(stalls.begin(), stalls.end());

    // Step 2️⃣ — Find the smallest and largest stall positions
    int maxi = *max_element(stalls.begin(), stalls.end());
    int mini = *min_element(stalls.begin(), stalls.end());

    int ans = 0;

    // Step 3️⃣ — Try all possible distances from 1 to (max - min)
    for (int i = 1; i <= (maxi - mini); i++) {
        // Check if cows can be placed with at least `i` distance
        bool canPlace = cowPlaceN(stalls, i, k);

        if (canPlace)
            ans = i; // store this distance (it’s valid)
        else
            break;   // stop if cows cannot be placed further apart
    }
    return ans; // Return the largest valid distance
}


// ✅ Binary Search Function

    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(),stalls.end());
        int maxi=*max_element(stalls.begin(), stalls.end());
        int mini=*min_element(stalls.begin(),stalls.end());
        int low=1,high=(maxi-mini);
        while(low<=high){
            int mid=(low+high)/2;
            int cowNo=cowPlaceN(stalls,mid,k);
            if(!cowNo)high=mid-1;
            else low=mid+1;
        }
        return high;
    }
};
