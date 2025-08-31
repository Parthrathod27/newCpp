//<<<<<Maximum Subarray>>>>>


//Given an integer array nums, find the subarray with the largest sum, and return its sum.

//Example 1:

/*Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6*/


/*approch:- here we will use Kadane's algorithm-O(n) which use linear timecomplexity.
            we will first create 2 variable 1] int currentSum .
                                            2]int maxSum
            initilize both the variable with the nums[0]
            start a for loop i from 1 to n where we will first get the maximum value int the currentSum by comparing nums[i] and currentSum+nums[i]
            then we will get the maximum value by comparision between maxSum and currentSum
            at last we return maxSum*/






code:-


int maxsubarray(vector<int>&arr){
 int n=arr.size();
 int currentSum=nums[0];
 int maxSum=nums[0];
  for(int i=1;i<n;i++){
     currentSum=max(nums[i],currentSum+nums[i]);
     maxSum=max(maxSum,currentSum);
   }
  return maxSum;
}
