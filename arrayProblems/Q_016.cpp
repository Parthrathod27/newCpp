/*<<<<<Majority element>>>>>*/

/*Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:
Input: nums = [3,2,3]
Output: 3*/

/*bruteforce approch: apply 2 pointer approch where we are using 2 loop i and j.
                      start the loop from i and then create the variable count=0 and then start the second loop j.
                      put a condition if the nums[i]==nums[j] count++ and at last check if count >n/2 if it is return nums[i].
                      TC:(n^2)*/


code:

   int majorityElement(vector<int>&nums){
         int n=nums.size();
         for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
               if(nums[i]==nums[j])count++;
            }
            if(count>n/2)return nums[i];
         }
       return {};
     }
 


/*better approch:We create an unordered_map (hash table) to store the frequency of each element.
Key = element, Value = count of occurrences.
Loop through the array and increment the count of each element in the map.
After counting, we check the map:
If any element’s frequency is greater than n/2, we return that element as the majority element.
This works in O(n) time (one pass to count, one pass to check) and uses O(n) space for the hash table.*/


code:
     int majorityElement(vector<int>&nums){
       int n=nums.size();
       unordered_map<int,int>freq;
       for(int num :nums){
        freq[num]++;
       }
       
       for(int it: freq){
         if(it.second>n/2){
            return it.first;
         }
       }
      return -1;
    }


/*optmized approch:Moore’s Voting Algorithm finds the majority element in linear time with constant space by maintaining
                  a candidate and a count while scanning the array.
                  The idea is that whenever we encounter the same number as the candidate, we increase the count, and whenever we see a different number,
                  we decrease it—effectively “canceling out” pairs of different elements.
                  If the count drops to zero, we pick the current number as the new candidate.
                  Since the majority element appears more than half the time, it cannot be fully canceled out, and thus the candidate at the end
                  of the scan is guaranteed to be the majority element.
                  This works in O(n) time and O(1) space, making it more efficient than hashing.*/


code:

   int majorityelement(vector<int>&nums){
      int n=nums.size();
      int elm=-1,count=0;
      for(int i=0;i<n;i++){
         if(count==0){
            elm=nums[i];
         }
         if(elm==nums[i]){
           count++;
         }
         else{
           count--;
         }
      }
    return elm;
  }
