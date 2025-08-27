                           //<<<<<TWO SUM >>>>>


/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/


/*Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].*/


//psudo code:


/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==t){
                return{i,j};
            }
        }
    }
    return{};
    }
};*/



/*using two pointer approch to find the sum which will be equal to the target
 in this approch we use first for loop as i and second for loop as j and start comparing them and putting a if condition where if the sum of the 2 number is 
 equal to target then return the index of that 2 number hence we are using two for loop ,
  the Time complixity is O(N^2),Space complixity is O(1),hence we are not using extra space */