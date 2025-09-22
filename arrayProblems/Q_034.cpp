#include <bits/stdc++.h>
using namespace std;

/*
============================================
🔥 Problem: Reverse Pairs
Given an integer array nums, return the number of reverse pairs.
A reverse pair is a pair (i, j) such that:
    i < j  and  nums[i] > 2*nums[j]

--------------------------------------------
Approach 1: Brute Force (O(n^2))
--------------------------------------------
1. Iterate over all pairs (i, j) with i < j.
2. Check if nums[i] > 2*nums[j].
3. Count such pairs.
Time Complexity: O(n^2)
Space Complexity: O(1)
*/

int reversePairsBrute(vector<int>& nums) {
    int n = nums.size();
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if((long long)nums[i] > 2LL * nums[j]) {
                count++;
            }
        }
    }
    return count;
}

/*
--------------------------------------------
Approach 2: Optimal using Modified Merge Sort (O(n log n))
--------------------------------------------
Key idea:
1. During merge sort, both halves are sorted.
2. For each element in left half, we can efficiently count how many
   elements in right half satisfy nums[i] > 2*nums[j].
3. This counting can be done in O(n) during merge step.
4. Continue with normal merge sort after counting.
Time Complexity: O(n log n)
Space Complexity: O(n) (for temp array in merge)
*/

int countPairs(vector<int>& nums, int low, int mid, int high) {
    int count = 0;
    int right = mid+1;
    for(int i=low; i<=mid; i++) {
        while(right<=high && (long long)nums[i] > 2LL*nums[right]) {
            right++;
        }
        count += (right - (mid+1));
    }
    return count;
}

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left=low, right=mid+1;
    while(left<=mid && right<=high) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left++]);
        } else {
            temp.push_back(nums[right++]);
        }
    }
    while(left<=mid) temp.push_back(nums[left++]);
    while(right<=high) temp.push_back(nums[right++]);

    for(int i=low; i<=high; i++) {
        nums[i] = temp[i-low];
    }
}

int mergeSort(vector<int>& nums, int low, int high) {
    if(low >= high) return 0;
    int mid = (low+high)/2;
    int count = 0;
    count += mergeSort(nums, low, mid);
    count += mergeSort(nums, mid+1, high);
    count += countPairs(nums, low, mid, high);
    merge(nums, low, mid, high);
    return count;
}

int reversePairsOptimal(vector<int>& nums) {
    return mergeSort(nums, 0, nums.size()-1);
}

/*
============================================
👉 Driver code to test
============================================
*/

int main() {
    vector<int> nums = {1,3,2,3,1};

    cout << "Brute Force Count = " << reversePairsBrute(nums) << endl;

    vector<int> nums2 = {1,3,2,3,1};
    cout << "Optimal Count = " << reversePairsOptimal(nums2) << endl;

    return 0;
}

