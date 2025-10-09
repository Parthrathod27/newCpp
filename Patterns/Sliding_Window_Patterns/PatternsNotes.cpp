/*
---------------------------------------------
🔥 SLIDING WINDOW & TWO POINTERS — PATTERN NOTES
---------------------------------------------

🎯 Concept:
Used to optimize problems on arrays/strings (subarrays, substrings, etc.)
instead of brute-forcing all possible ranges.

---------------------------------------------
🧠 COMMON IDEA (Template)
---------------------------------------------
1. Initialize pointers:
   left = 0, right = 0  // window boundaries

2. Maintain a state (sum, count, freq map, etc.)

3. Expand window:
   - Move 'right' pointer to include new elements
   - Update the state

4. Check condition:
   - If condition is violated → shrink window from 'left'
   - If condition is satisfied → record result / update answer

5. Shrink window:
   - Move 'left' pointer to reduce window size
   - Maintain validity or optimize (e.g., find min window)

6. Continue until 'right' reaches end of array/string

---------------------------------------------
🧩 PATTERN TYPES
---------------------------------------------
1️⃣ Fixed-size Sliding Window
   → When window size is constant (e.g., subarray of size K)
   Example: Max/Min sum of subarray of size K

2️⃣ Variable-size Sliding Window
   → When you expand and shrink based on a condition
   Example: Longest substring without repeating characters

3️⃣ Minimum Window Pattern
   → Find smallest window satisfying a condition
   Example: Minimum window substring (Leetcode #76)

4️⃣ Counting Subarrays Pattern
   → Count all valid subarrays satisfying condition
   Example: Count subarrays with sum ≤ K or at most K distinct elements

---------------------------------------------
⚙️ TEMPLATE STRUCTURE (PSEUDOCODE)
---------------------------------------------
while (right < n):
    // expand window
    include arr[right] in state
    right++

    while (condition violated):
        // shrink window
        remove arr[left] from state
        left++

    // update result if needed

---------------------------------------------
💡 TIPS
---------------------------------------------
✅ Expand right → include new elements
✅ Shrink left → fix violations or optimize
✅ Maintain running sum/frequency map
✅ Update result only when condition valid
✅ Common problems: max sum subarray, longest substring, min window, etc.

---------------------------------------------
*/

