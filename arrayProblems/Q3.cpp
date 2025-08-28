                           /*<<<<< Remove elements>>>>> */


/*Given an integer array nums and an integer val, remove all occurrences of val in nums
in-place. The order of the elements may be changed. Then return the number of elements
in nums which are not equal to val.*/


//Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
     int i=0;
     for(int j=0;j<nums.size();j++){
        if(nums[j]!=val){
            nums[i]=nums[j];
            i++;
        }
     }
     return i;
    }
};
