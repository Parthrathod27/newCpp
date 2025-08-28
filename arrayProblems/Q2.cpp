/*Remove the Duplicate element from sorted array*/

/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-
place such that each unique element appears only once. The relative order of the
elements should be kept the same. Then return the number of unique elements in nums*/

/*Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int k = 1; // first element is always unique
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k - 1]) {  // found new unique element
                nums[k] = nums[i];        // move it to the next position
                k++;
            }
        }
        return k; // number of unique elements
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};

    int k = sol.removeDuplicates(nums);

    cout << "k = " << k << endl;
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

/* here we are using a variable which is at index 1 beacuse the first number is always unique 
so using only one for loop for  the itteration which start from index 1 and run till the end of the array 
and in that for loop we are initilizing the condition where if the nums[i]!=nums[k-1] then the nums[k]=nums[i]
due to which all the duplicates element will be removed */
