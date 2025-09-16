/*
MAJORITY ELEMENT II (LeetCode 229)

Problem:
---------
Given an integer array nums of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
At most 2 elements can satisfy this condition.

----------------------------------------------------
1️⃣ Brute Force Approach
----------------------------------------------------
- For each element, count its frequency by looping entire array.
- If frequency > n/3 and element not already in answer → add to result.
- Time: O(n^2), Space: O(1)

Steps:
- Loop i=0→n-1
- Count frequency of nums[i] by looping j=0→n-1
- If count > n/3 and nums[i] not already in answer → push_back
- Return answer list
/*

code:
// 1️⃣ Brute Force Approach (O(n^2), O(1))
class SolutionBrute {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) count++;
            }
            if (count > n/3 && find(ans.begin(), ans.end(), nums[i]) == ans.end()) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

/*
----------------------------------------------------
2️⃣ Better Approach (Hash Map / Frequency Count)
----------------------------------------------------
- Use unordered_map to store frequencies of all elements.
- Traverse array once and update map[element]++.
- Traverse map and collect elements with count > n/3.
- Time: O(n), Space: O(n)

Steps:
- Create unordered_map<int,int>
- For each element in nums → map[element]++
- Traverse map:
    - If map[element] > n/3 → add element to answer
- Return answer list
/*


code:
// 2️⃣ Better Approach (Hash Map) (O(n), O(n))
class SolutionBetter {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        vector<int> ans;
        for (auto it : freq) {
            if (it.second > n/3) {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};


/*
----------------------------------------------------
3️⃣ Optimal Approach (Extended Moore’s Voting Algorithm)
----------------------------------------------------
- At most 2 majority elements possible (since > n/3).
- Maintain 2 candidates and 2 counters.
- First Pass: Find potential candidates
    - If nums[i] == candidate1 → count1++
    - Else if nums[i] == candidate2 → count2++
    - Else if count1 == 0 → candidate1 = nums[i], count1 = 1
    - Else if count2 == 0 → candidate2 = nums[i], count2 = 1
    - Else → count1--, count2--
- Second Pass: Verify counts of candidate1 and candidate2
- Collect candidates with count > n/3
- Time: O(n), Space: O(1)

Steps:
- Initialize candidate1, candidate2, count1=0, count2=0
- First pass → find potential candidates
- Second pass → reset count1, count2 = 0, recount occurrences
- If count1 > n/3 → add candidate1
- If count2 > n/3 → add candidate2
- Return answer list
*/


code:
// 3️⃣ Optimal Approach (Extended Moore’s Voting Algorithm) (O(n), O(1))
class SolutionOptimal {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        // First pass: find potential candidates
        int count1 = 0, count2 = 0;
        int candidate1 = 0, candidate2 = 1; // pick different initial values

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        // Second pass: verify candidates
        count1 = count2 = 0;
        for (int num : nums) {
            if (num == candidate1) count1++;
            else if (num == candidate2) count2++;
        }

        vector<int> ans;
        if (count1 > n/3) ans.push_back(candidate1);
        if (count2 > n/3) ans.push_back(candidate2);

        return ans;
    }
};

