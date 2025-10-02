// ================= Brute Force Approach =================
// Idea: Loop through the array and check for peak by comparing with neighbors
// Time Complexity: O(n)
// Space Complexity: O(1)
class SolutionBrute {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0; // Only one element → peak is itself

        for(int i = 0; i < n; i++){
            // First element
            if(i == 0 && nums[i] > nums[i+1]) return i;
            // Last element
            if(i == n-1 && nums[i] > nums[i-1]) return i;
            // Middle elements
            if(i > 0 && i < n-1 && nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        }

        return -1; // No peak found (theoretically never happens)
    }
};

// ================= Optimal Approach (Binary Search) =================
// Idea: Use binary search by checking middle element against neighbors
// Peak exists in the direction of the rising slope
// Time Complexity: O(log n)
// Space Complexity: O(1)
class SolutionOptimal {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;       // Only one element → peak
        if(nums[0] > nums[1]) return 0;     // Peak at start
        if(nums[n-1] > nums[n-2]) return n-1; // Peak at end

        int low = 1, high = n-2;  // Exclude first and last already checked
        while(low <= high){
            int mid = low + (high - low)/2;

            // Check if mid is peak
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            // If slope rising to the right, move right
            else if(nums[mid] > nums[mid-1]){
                low = mid + 1;
            }
            // Else move left
            else{
                high = mid - 1;
            }
        }
        return -1; // Should never reach here
    }
};




/*
1. Handle edge cases first:
   - If only one element, return index 0
   - If first element is peak, return 0
   - If last element is peak, return n-1

2. Initialize low=1 and high=n-2, because first and last elements are already checked

3. Perform binary search:
   - Calculate mid = low + (high-low)/2
   - If nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1], mid is peak → return mid
   - Else if nums[mid] > nums[mid-1], the slope is rising → move to right half (low=mid+1)
   - Else, slope is falling → move to left half (high=mid-1)

4. Return -1 if no peak found (theoretically unreachable)
*/

