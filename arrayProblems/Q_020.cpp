/*<<<<<Next Permutation>>>>>*/


/*A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer.
 More formally, if all the permutations of the array are sorted in one container according to their lexicographical order,
 then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible,
 the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).*/

/*1]Scan from the right to find the pivot index idx — the first position where nums[i] < nums[i+1].
    If none exists, the array is the highest permutation; reverse the whole array and return.
   2]Scan from the right to find the first element nums[j] that is greater than nums[idx] 
    (this will be the smallest element greater than the pivot because the suffix is non-increasing).
   3]Swap nums[idx] and nums[j].
    4]Reverse the subarray after idx (i.e. nums[idx+1 .. end]) to turn the suffix into its lowest possible order (ascending). 
      That yields the next lexicographic permutation.*/

/*Concrete example: nums = [1, 2, 3, 6, 5, 4]
Step 1 — find pivot: scan from right: compare 5<4? no, 6<5? no, 3<6? yes → idx = 2 (value 3).
Step 2 — find successor from right: scan rightwards finds 4 at index 5 (4 > 3) — because the suffix 6,5,4 is descending, the first >3 from the right is the smallest >3.
Step 3 — swap nums[2] and nums[5] → array becomes [1,2,4,6,5,3].
Step 4 — reverse suffix after index 2 ([6,5,3] → [3,5,6]) → final result [1,2,4,3,5,6], which is the immediate next permutation.
Descending-case example: nums = [3,2,1]
No i satisfies nums[i] < nums[i+1], so idx = -1. Reverse whole array → [1,2,3] (the first/lowest permutation).
Complexity: single pass(s) from both ends, so O(n) time and O(1) extra space.*/

code:

 void nextPermutation(vector<int>& nums) {
  int n=nums.size();
  int idx=-1;
  for(int i=n-2;i>=0;i--){
     if(nums[i]<nums[i+1]){
        idx=i;
       break;
      }
  }
  
  if(idx==-1){
    reverse(nums.begin(),nums.end());
    return;
  }
  
  for(int i=n-1;i>idx;i--){
     if(nums[i]>nums[idx]){
       swap(nums[i],nums[idx]);
       break;
     }
  }
  
  reverse(nums.begin()+idx+1,nums.end());
 }
};
