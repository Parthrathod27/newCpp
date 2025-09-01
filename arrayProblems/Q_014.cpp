/*<<<<<Longest or Sortest subarray sum equal to k>>>>>*/


/*brute force approch:-1]here we will use two pointer approch by creating two For loop i and j 
2]first create the variable minLen =INT_MAX
3] start the first for loop from zero to end .
4] create a variable sum with value zero and start the second loop from i till end.
5] first increment the sum += nums[j] 
6]create the condition if the sum >= target in that condition git the minLen b min(minLen,j-i+1) and then break the loop
7]at last return then minLen if it is not equal to INT_MAX else return zero*/


code:-

int minsubArraySum(int target,vector<int>&nums){
    int n=nums.size();
    int minLen=INT_MAX;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
          sum+=nums[j];
          if(sum>=target){
            minLen=min(minLen,j-i+1);
            break;
          }
       }
    }
   return (minLen==INT_MAX)?0 : minLen;
 }


//TC=O(N^2)



/*optimize approch:-1]here we will use sliding window approch we will use two pointer as left and right 
2]first create some variable sum=0,minlen=INT_MAX,left=0,right=0.
3]then start the loop for right part to extend it till the end of the array.
4]then add sum+=nums[right] and start another while loop to check the sum>=target
5]in that condition we will first calculate the minLen be min(minLen,right-left+1)
6]then decrese the left part by sum -= nums[left] and increment left++.
7]at last return then minLen if it is not equal to INT_MAX else return zero*/






code:-

int minSubarraysum(int target,vector<int>&nums){
     int n=nums.size();
     int left=0,right=0;
     int sum=0;
     int minLen=INT_MAX;
     for(right=0;right<n;right++){
           sum += nums[right];
        
         while(sum>=target){
            minLen=min(minLen,right-left+1);
            sum -= nums[left];
            left++;
          }
       }
     return (minLen==INT_MAX)?0 : minLen;
 }

 //TC=O(N).


