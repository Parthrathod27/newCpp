/*<<<<<<Leader of array>>>>>*/



/*You are given an array arr of positive integers.
  Your task is to find all the leaders in the array. An element is considered a leader if it is greater than or equal to all elements to its right.
  The rightmost element is always a leader.
Examples:
Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]
Explanation: Note that there is nothing greater on the right side of 17, 5 and, 2.*/

/*brute approch:For each element in the array, check if it is greater than or equal to all elements on its right side.
If yes → it’s a leader.
🔹 Steps
Loop through each element nums[i].
For each i, loop through all elements to its right (nums[j] where j > i).
If you find any element greater than nums[i], then nums[i] is not a leader → break.
Otherwise, if none are greater, mark nums[i] as a leader.
The last element is always a leader (since nothing is to its right).*/

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            bool isLeader = true;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[i]) {
                    isLeader = false;
                    break;
                }
            }
            if (isLeader) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};


/*optimal approch:A leader is an element that is greater than or equal to all elements to its right.
Instead of checking every element’s right side (brute force O(n²)), we can do one pass from right to left.
While going from right → left, keep track of the maximum element seen so far (maxRight).
If the current element ≥ maxRight, it’s a leader.*/

/*Steps:Initialize maxRight = -∞ (or INT_MIN).
Traverse the array from right to left.
For each element:
If it’s ≥ maxRight, it’s a leader → add it to the result.
Update maxRight = current element if needed.
At the end, reverse the result (since we collected leaders from right to left).*/


code:

vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int elm=INT_MIN;
        for(int i=n-1;i>=0;i--){
           if(nums[i]>elm){
              ans.push_back(nums[i]);
              elm=max(elm,nums[i]);
           }
        }
        reverse(ans.begin(),ans.end());
        return ans;
     }
 
