class Solution {
public:

    // ---------------------------------------------------
    // 🟢 Helper Function
    // ---------------------------------------------------
    // Given a speed "mid" (bananas/hour), this function 
    // calculates the total hours Koko will take to eat all bananas.
    // If pile[i] = 30 and mid = 7 --> ceil(30/7) = 5 hours.
    long long totalHours(vector<int>& piles, int speed) {
        long long hours = 0;
        for(int bananas : piles) {
            hours += (bananas + speed - 1) / speed; // ceil(bananas/speed)
        }
        return hours;
    }

    // ---------------------------------------------------
    // 🟢 Brute Force Approach
    // ---------------------------------------------------
    // 1. The slowest speed = 1 (1 banana per hour).
    // 2. The fastest speed = max(piles) (eat biggest pile in 1 hour).
    // 3. Try every speed from 1 to maxPile.
    // 4. For each speed, calculate total hours taken.
    // 5. If hours <= h, return that speed (minimum valid speed).
    // Time Complexity: O(maxPile * n)
    // Space Complexity: O(1).
    int minEatingSpeedBrute(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        for(int speed = 1; speed <= maxPile; speed++) {
            long long hours = totalHours(piles, speed);
            if(hours <= h) return speed; // found min speed
        }
        return maxPile;
    }

    // ---------------------------------------------------
    // 🟢 Optimal Approach (Binary Search)
    // ---------------------------------------------------
    // Idea:
    // 1. Answer lies between [1, maxPile].
    // 2. Use Binary Search to minimize speed.
    // 3. For mid = (low+high)/2:
    //    - If hours(mid) <= h --> possible answer, shrink right (high = mid-1).
    //    - Else if hours(mid) > h --> need faster speed, move left (low = mid+1).
    // 4. Return the smallest valid speed.
    // Time Complexity: O(n * log(maxPile))
    // Space Complexity: O(1).
    int minEatingSpeedOptimal(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            long long hours = totalHours(piles, mid);

            if(hours <= h) {
                ans = mid;       // candidate answer
                high = mid - 1;  // try smaller speed
            } else {
                low = mid + 1;   // need bigger speed
            }
        }
        return ans;
    }
};

