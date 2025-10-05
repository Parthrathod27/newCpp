/*
-------------------------------------------
APPROACH 1: BRUTE FORCE (O(K × N))
-------------------------------------------

🧠 EXPLANATION:
1. We are given existing gas station positions (sorted) and K new stations to add.
2. We maintain a vector `hasP` where hasP[i] = number of new stations added between nums[i] and nums[i+1].
3. For each new station (K times):
   → Find the interval with the largest current segment length.
   → Add one new station in that interval (i.e., increase hasP[index] by 1).
4. Finally, calculate the maximum distance after placing all K stations.

This approach simulates the process step-by-step.
It’s simple but slow when K or N is large.

🕒 Time Complexity:  O(K × N)
⚙️ Space Complexity: O(N)
-------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minMaxDist(vector<int>& nums, int K) {
        int n = nums.size();
        vector<int> hasP(n - 1, 0);

        for (int k = 0; k < K; k++) {
            long double maxDist = -1;
            int maxIdx = -1;

            // Find interval with largest gap
            for (int j = 0; j < n - 1; j++) {
                long double diff = nums[j + 1] - nums[j];
                long double segment = diff / (long double)(hasP[j] + 1);
                if (segment > maxDist) {
                    maxDist = segment;
                    maxIdx = j;
                }
            }

            // Add one station to that interval
            hasP[maxIdx]++;
        }

        // Calculate final max distance
        long double maxAns = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = nums[i + 1] - nums[i];
            long double segment = diff / (long double)(hasP[i] + 1);
            maxAns = max(maxAns, segment);
        }

        return (double)maxAns;
    }
};


/*
-------------------------------------------
APPROACH 2: GREEDY USING MAX HEAP (O(K log N))
-------------------------------------------

🧠 EXPLANATION:
1. The idea is similar to Brute Force but optimized using a max heap.
2. Each interval between two stations has an initial length = nums[i+1] - nums[i].
3. Push all intervals into a max heap (priority queue).
   The heap keeps track of the current *largest segment length*.
4. Each time we add a new station:
   → Pop the largest segment from the heap.
   → Divide it into (count + 1) smaller parts.
   → Push the new smaller segment back into the heap.
5. After adding all K stations, the top of the heap gives the minimized maximum distance.

🕒 Time Complexity:  O(K × log N)
⚙️ Space Complexity: O(N)
-------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minMaxDist(vector<int>& nums, int K) {
        int n = nums.size();
        vector<int> hasP(n - 1, 0);

        // Max heap: pair = {segment length, index}
        priority_queue<pair<long double, int>> pq;

        // Push all initial segments
        for (int i = 0; i < n - 1; i++) {
            long double diff = nums[i + 1] - nums[i];
            pq.push({diff, i});
        }

        // Add K new stations
        for (int k = 0; k < K; k++) {
            auto [dist, idx] = pq.top();
            pq.pop();

            hasP[idx]++; // add one station in that interval

            long double diff = nums[idx + 1] - nums[idx];
            long double newDist = diff / (hasP[idx] + 1);

            pq.push({newDist, idx});
        }

        // The maximum distance left in heap is our answer
        return pq.top().first;
    }
};


/*
-------------------------------------------
APPROACH 3: BINARY SEARCH ON ANSWER (O(N log M))
-------------------------------------------

🧠 EXPLANATION:
1. Instead of simulating placement, we "guess" the minimum possible max distance.
   Let’s call it `mid`.
2. For each interval (nums[i+1] - nums[i]):
   → We can calculate how many extra stations are needed to make all segments ≤ mid.
     i.e., count += floor((nums[i+1] - nums[i]) / mid)
3. If total count <= K → It’s possible with this distance → try smaller distance.
   Else → need larger distance.
4. Continue binary search until precision (1e-6) is reached.

🕒 Time Complexity:  O(N × log(MaxDist / Precision))
⚙️ Space Complexity: O(1)
✅ Most efficient & used in LeetCode #774
-------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function: check if we can achieve 'dist' with ≤ K stations
    bool canPlace(vector<int>& nums, int K, long double dist) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            long double gap = nums[i + 1] - nums[i];
            count += floor(gap / dist);
        }

        return count <= K;
    }

    double minMaxDist(vector<int>& nums, int K) {
        long double left = 0, right = nums.back() - nums.front();
        long double eps = 1e-6;

        // Binary Search
        while (right - left > eps) {
            long double mid = (left + right) / 2.0;
            if (canPlace(nums, K, mid))
                right = mid; // possible → try smaller
            else
                left = mid;  // not possible → try larger
        }

        return (double)right;
    }
};
