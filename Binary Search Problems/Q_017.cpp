class Solution {
public:
    int maxi(vector<int>& nums){
        int n=nums.size();
        int count=INT_MIN;
        for(int i=0;i<n;i++){
            count=max(count,nums[i]);
        }
        return count;
    }

    int result(vector<int>& nums,int x){
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            count += (nums[i] + x - 1) / x;
        }
        return count;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold)return -1;
        int low=1,high=maxi(nums);
        while(low<=high){
            int mid=low+(high-low)/2;
            int val=result(nums,mid);
            if(val<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
