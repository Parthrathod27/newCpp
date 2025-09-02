/*<<<<<Sort the Array having only 0s,1s,2s.>>>>>*/


/*brute force approch: using a normal sorting algo to sort the array which take TC=O(NlogN)*/

code:
      void sortColors(vector<int>& nums){
          sort(nums.begin(),nums.end());
       }




//*better approch:using three variable,count0,count1,count2 and using a for loop to itterate all over the array and taking number of 0,1  and 2
                 every time finding the number just increse that three variable.
                 then itterate every variable using for loop and rewite the numbers
                 but this approch will take two passes which is not best approch*/




code:-

    void sortColors(vector<int>& nums){
    int n-nums.size();
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
      if(nums[i]==0)count0++;
      else if(nums[i]==1)count1++;
      else count2++;

    int idx=0;
    for(int i=0;i<n;i++){
       nums(idx++)==0;
     }
    for(int i=0;i<n;i++){
       nums(idx++)==1;
     }
    for(int i=0;i<n;i++){
       nums(idx++)==2;
     }
  }


/*optmized approch:The most efficient approach is the Dutch National Flag algorithm (three-way partitioning)
                  , which sorts the array in a single pass using constant extra space
                   We maintain three regions: all 0’s (red) at the start, all 2’s (blue) at the end, and 1’s (white) in the middle
                   Using three pointers (low, mid, and high), we iterate with mid through the array: if nums[mid] == 0,
                   swap it with nums[low] and increment both; if nums[mid] == 1, just move mid forward; if nums[mid] == 2,
                   swap it with nums[high] and decrement high (but don’t increment mid immediately, since the swapped element needs to be checked)
                   This guarantees sorting in O(n) time and O(1) space, without extra passes or library functions.*/


code:

      void sortColors(vector<int>& nums){
      int n=nums.size();
      int low=0,mid=0,high=n-1;
      while(mid<=high){
        if(nums[mid]==0){
           swap(nums[low],nums[mid]);
             mid++;
             low++;
        }
        else if(nums[mid]==1){
             mid++;
        }
        else{
           swap(nums[high],nums[mid]);
           high--;
        }
     }
  }
             
