//<<<<< 3 Sum problem >>>>>

/*
-----------------------------------------
🔹 Approach 1: Brute Force (O(n^3))
- Use 3 nested loops to generate all triplets.
- If their sum == 0, store in a set (to avoid duplicates).
- Convert set into vector.
-----------------------------------------
*/
vector<vector<int>> threeSumBrute(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

/*
-----------------------------------------
🔹 Approach 2: Better (O(n^2 * log n))
- Fix first element with a loop.
- Use a hash set for the other two elements.
- If (target - nums[j]) exists, store triplet.
- Use set to avoid duplicates.
-----------------------------------------
*/
vector<vector<int>> threeSumBetter(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++) {
        unordered_set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                s.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

/*
-----------------------------------------
🔹 Approach 3: Optimal (Two Pointers, O(n^2))
- Sort the array.
- Fix one element (i loop).
- Use two pointers (j = i+1, k = n-1).
- Move j/k based on sum until j < k.
- Skip duplicates for i, j, k.
-----------------------------------------
*/
vector<vector<int>> threeSumOptimal(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates for i
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) j++;
            else if (sum > 0) k--;
            else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++; // skip duplicates for j
                while (j < k && nums[k] == nums[k + 1]) k--; // skip duplicates for k
            }
        }
    }
    return ans;
}

