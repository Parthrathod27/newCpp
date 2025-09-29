/*
-------------------------------------------------------
Floor and Ceil in a Sorted Array
-------------------------------------------------------

Definitions:
- Floor of x: Largest element <= x
- Ceil of x: Smallest element >= x

Given a sorted array, we want to find floor and ceil of a target number.

Approach (Optimal - Binary Search):
1. Initialize floor = -1 (if no element <= target)
2. Initialize ceil = -1 (if no element >= target)
3. Use binary search:
   - mid = (low + high) / 2
   - If arr[mid] == target → floor = ceil = arr[mid]
   - If arr[mid] < target → update floor = arr[mid], move right (low = mid+1)
   - If arr[mid] > target → update ceil = arr[mid], move left (high = mid-1)
4. At the end, return floor and ceil.

Time Complexity: O(log n)
Space Complexity: O(1)
-------------------------------------------------------
*/

pair<int,int> floorAndCeil(vector<int>& arr, int target) {
    int n = arr.size();
    int low = 0, high = n-1;
    int floor_val = -1; // default if no element <= target
    int ceil_val = -1;  // default if no element >= target

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(arr[mid] == target){
            floor_val = arr[mid];
            ceil_val = arr[mid];
            break;
        }
        else if(arr[mid] < target){
            floor_val = arr[mid];  // possible floor
            low = mid + 1;
        }
        else{
            ceil_val = arr[mid];   // possible ceil
            high = mid - 1;
        }
    }

    return {floor_val, ceil_val};
}

