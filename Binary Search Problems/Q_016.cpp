/*
💡 Problem: Minimum Number of Days to Make m Bouquets (LeetCode 1482)

We are given an array bloomDay[] where bloomDay[i] = the day the ith flower blooms.
We want to make m bouquets, each with k adjacent flowers.
Return the minimum day when it is possible, else -1.
*/

// ✅ Brute Force Approach
/*
1. Find the maximum bloom day (say maxDay).
2. For each day from 1 to maxDay:
   - Count how many bouquets can be formed on that day.
   - If >= m, return that day.
3. Time complexity: O(maxDay * n) → Too slow if maxDay is large.
*/

class BruteForceSolution {
public:
    // Check how many bouquets can be made on a given day
    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
        int count = 0, bouquets = 0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                count++;
                if(count == k) {   // one bouquet formed
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0; // reset if not bloomed
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m * k > bloomDay.size()) return -1; // not enough flowers
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        for(int day=1; day<=maxDay; day++) {
            if(canMake(bloomDay, day, m, k)) return day;
        }
        return -1;
    }
};


// ✅ Optimized Approach (Binary Search)
/*
1. Instead of checking every day → apply Binary Search between [minDay, maxDay].
2. For mid = (low+high)/2 → check if we can make m bouquets.
3. If yes, try smaller days → move left.
4. Else, move right.
5. Time complexity: O(n log(maxDay))
*/

class Solution {
public:
    // Find minimum bloom day
    int minR(vector<int>& bloomDay){
        int n = bloomDay.size();
        int count = INT_MAX;
        for(int i=0; i<n; i++){
            count = min(count, bloomDay[i]);
        }
        return count;
    }

    // Find maximum bloom day
    int maxR(vector<int>& bloomDay){
        int n = bloomDay.size();
        int count = INT_MIN;
        for(int i=0; i<n; i++){
            count = max(count, bloomDay[i]);
        }
        return count;
    }

    // Check if possible to make m bouquets in "day"
    bool result(vector<int>& bloomDay, int day, int m, int k){
        int count = 0, noDay = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= day){
                count++;
            }
            else{
                noDay += (count / k); // count full bouquets
                count = 0;
            }
        }
        noDay += (count / k); // last group
        return noDay >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int low = minR(bloomDay), high = maxR(bloomDay);
        while(low <= high){
            int mid = low + (high - low) / 2;
            bool canMake = result(bloomDay, mid, m, k);

            if(!canMake){
                low = mid + 1; // need more days
            }
            else{
                high = mid - 1; // possible, try smaller days
            }
        }
        return low;
    }
};
