// ------------------------------------------------------------
// Problem: Merge Overlapping Intervals
// Given an array of intervals where intervals[i] = [start, end],
// merge all overlapping intervals and return an array of the
// non-overlapping intervals that cover all the intervals in input.
// ------------------------------------------------------------


// -------------------- Brute Force ----------------------------
// 1. Sort the intervals by starting time.
// 2. For each interval, compare with every other interval to check overlap.
// 3. If intervals overlap, merge them into one.
// 4. Use an extra data structure (like a visited array) to mark merged intervals.
// 5. Collect all merged intervals in the result.
//
// Time Complexity: O(n^2)   (nested comparisons)
// Space Complexity: O(n)    (for storing merged results / visited array)
// ------------------------------------------------------------

class SolutionBrute {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        vector<bool> merged(n, false);

        // Step 1: sort by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: check overlaps
        for (int i = 0; i < n; i++) {
            if (merged[i]) continue;  // already merged

            int start = intervals[i][0];
            int end = intervals[i][1];

            for (int j = i + 1; j < n; j++) {
                // If intervals[j] overlaps with [start, end]
                if (intervals[j][0] <= end) {
                    end = max(end, intervals[j][1]);
                    merged[j] = true; // mark as merged
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
};


// -------------------- Optimal Approach -----------------------
// 1. Sort the intervals by starting time.
// 2. Traverse the intervals in order:
//    - If current interval overlaps with the last added interval in ans
//      → merge them by updating the end.
//    - Else → push the current interval as new entry in ans.
// 3. This works because sorting ensures all overlapping intervals are adjacent.
//
// Time Complexity: O(n log n)   (sorting dominates)
// Space Complexity: O(n)        (for output list)
// ------------------------------------------------------------

class SolutionOptimal {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        // Step 1: sort by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: process intervals
        for (auto interval : intervals) {
            // if ans is empty OR no overlap
            if (ans.empty() || ans.back()[1] < interval[0]) {
                ans.push_back(interval);
            } else {
                // overlap → merge by extending end
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};

