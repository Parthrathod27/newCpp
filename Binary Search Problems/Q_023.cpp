class Solution {
public:
    // 🧩 sumArr(): returns the sum of all board lengths
    int sumArr(vector<int>& boards) {
        int total = 0;
        for (int i = 0; i < boards.size(); i++) {
            total += boards[i];
        }
        return total;
    }

    // 🧩 countPainters(): given a time limit, returns how many painters are needed
    int countPainters(vector<int>& boards, int limit) {
        int painters = 1;     // we start with 1 painter
        int painted = 0;      // how much this painter has painted

        // loop through all boards
        for (int i = 0; i < boards.size(); i++) {
            // if adding this board stays within the time limit
            if (boards[i] + painted <= limit) {
                painted += boards[i];   // same painter continues
            } 
            // otherwise assign a new painter
            else {
                painters++;
                painted = boards[i];    // start fresh for next painter
            }
        }
        return painters;
    }

    // -------------------------------------------------------
    // 🔹 BRUTE FORCE APPROACH
    // -------------------------------------------------------
    int minTimeBrute(vector<int>& boards, int k) {
        // ❗ if there are fewer boards than painters — not possible
        if (boards.size() < k) return -1;

        // lowest possible time = largest board (since at least one board must be painted fully)
        int low = *max_element(boards.begin(), boards.end());

        // highest possible time = sum of all boards (one painter does all)
        int high = sumArr(boards);

        int ans = -1;

        // 🧠 try all possible times from low → high
        for (int time = low; time <= high; time++) {
            // check how many painters needed if each can paint 'time' units
            int neededPainters = countPainters(boards, time);

            // if possible with ≤ k painters, this is a valid answer
            if (neededPainters <= k) {
                ans = time;   // store and break (first valid is minimum)
                break;
            }
        }
        return ans;
    }

    // -------------------------------------------------------
    // 🔹 OPTIMIZED APPROACH — BINARY SEARCH
    // -------------------------------------------------------
    int minTimeOptimized(vector<int>& boards, int k) {
        // ❗ same edge case check
        if (boards.size() < k) return -1;

        int low = *max_element(boards.begin(), boards.end());
        int high = sumArr(boards);

        // 🧠 binary search for smallest valid max-time
        while (low <= high) {
            int mid = (low + high) / 2;      // mid = possible max time
            int neededPainters = countPainters(boards, mid);

            // if painters needed are within k → try to reduce time
            if (neededPainters <= k) {
                high = mid - 1;
            } 
            // else → we need more time
            else {
                low = mid + 1;
            }
        }

        return low;   // smallest possible max-time to paint all boards
    }
};
