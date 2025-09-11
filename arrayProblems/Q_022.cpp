/*<<<<<Longest Consecutive Sequence>>>>>*/

/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
Example 1:
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.*/

/*better approch:Sort the array so potential consecutive numbers are next to each other.
Walk once through the sorted array, building a currentStreak whenever numbers are consecutive.
Skip duplicates (they neither start nor break a streak).
Keep the maximum streak seen (longest). Return it at the end.*/


code:
if (nums.empty()) return 0;
sort(nums.begin(), nums.end());
int longest = 1, currentStreak = 1;
for (int i = 1; i < n; ++i) {
    if (nums[i] == nums[i-1]) {
        // duplicate, ignore
        continue;
    } else if (nums[i] == nums[i-1] + 1) {
        // consecutive -> extend streak
        currentStreak++;
    } else {
        // gap -> finalize previous streak and reset
        longest = max(longest, currentStreak);
        currentStreak = 1;
    }
}
return max(longest, currentStreak);

/*optimal approch:This is the standard O(n) solution for LeetCode 128: Longest Consecutive Sequence.
Handle empty input
If nums is empty return 0.
Put all elements into a hash set (unordered_set<int> s) so lookups (s.count(x) / s.find(x)) are average O(1). This also removes duplicates.
Find sequence starts only
For each number x in the set, check whether x-1 is not in the set. If x-1 is missing,
  x is the start of a consecutive sequence (otherwise x is inside some earlier sequence and can be skipped).
Grow the sequence
From each start x, repeatedly test x+1, x+2, ... in the set and count how long the run is.
Track the maximum length seen and continue until all set elements are considered.
Return the maximum after checking all starts.
This ensures each element is expanded at most once (because we only start expansion at sequence starts), giving O(n) time.*/

code:class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int x : s) {
            // only start if x is the beginning of a sequence
            if (s.find(x - 1) == s.end()) {
                int length = 1;
                int curr = x;
                while (s.find(curr + 1) != s.end()) {
                    curr++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};

