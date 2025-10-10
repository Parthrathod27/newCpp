/*
=========================================================
🔥 STRING PATTERNS — COMPLETE CHEAT SHEET
=========================================================

1️⃣ SLIDING WINDOW / TWO POINTERS
---------------------------------------------------------
🧠 Use When:
  - You need to find a substring that meets some condition
  - You expand and shrink a window based on constraints

📘 Examples:
  - Longest substring without repeating characters
  - Minimum window substring
  - Longest substring with at most K distinct chars

💻 Template (variable size):
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
        include s[right];
        while (condition violated) {
            remove s[left];
            left++;
        }
        update result if valid;
    }

---------------------------------------------------------

2️⃣ PREFIX / SUFFIX PATTERN
---------------------------------------------------------
🧠 Use When:
  - Substring info depends on prefix/suffix
  - You want quick range queries or prefix relationships

📘 Examples:
  - Longest prefix = suffix (KMP preprocessing)
  - Prefix sums, prefix hash, or suffix arrays

💻 Template:
    prefix[i] = prefix[i-1] + value;
    // substring info: prefix[j] - prefix[i]

---------------------------------------------------------

3️⃣ COUNTING / FREQUENCY MAP PATTERN
---------------------------------------------------------
🧠 Use When:
  - You care about character frequencies
  - Compare two strings or check if valid

📘 Examples:
  - Valid Anagram
  - Group Anagrams
  - Find all anagram substrings

💻 Template:
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;
    for (char c : t) freq[c]--;
    check if all freq == 0;

---------------------------------------------------------

4️⃣ STRING MATCHING (PATTERN SEARCH)
---------------------------------------------------------
🧠 Use When:
  - You need to find pattern `p` inside text `t`

📘 Algorithms:
  - KMP (Knuth-Morris-Pratt)
  - Rabin-Karp (Rolling Hash)
  - Z Algorithm (Prefix function)

💻 Template (KMP idea):
    Build LPS array for pattern
    Traverse text + pattern using two pointers

---------------------------------------------------------

5️⃣ PALINDROME PATTERN
---------------------------------------------------------
🧠 Use When:
  - You check if substring reads same forward/backward

📘 Examples:
  - Longest Palindromic Substring
  - Palindrome Partitioning

💻 Template (Expand Around Center):
    for (int i = 0; i < n; i++) {
        expand(i, i);       // odd length
        expand(i, i + 1);   // even length
    }

    void expand(int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) {
            update answer;
            l--; r++;
        }
    }

---------------------------------------------------------

6️⃣ DYNAMIC PROGRAMMING ON STRINGS
---------------------------------------------------------
🧠 Use When:
  - Subproblems depend on smaller substrings
  - Typically for subsequences or edit operations

📘 Examples:
  - Longest Common Subsequence
  - Edit Distance
  - Palindromic Subsequence

💻 Template (LCS example):
    dp[i][j] = dp[i-1][j-1] + 1  if s1[i-1] == s2[j-1]
             = max(dp[i-1][j], dp[i][j-1]) otherwise;

---------------------------------------------------------

7️⃣ STACK / EXPRESSION PATTERN
---------------------------------------------------------
🧠 Use When:
  - String represents expression or decoding
  - You need to track open/close structure

📘 Examples:
  - Valid Parentheses
  - Decode String ("3[a2[c]]")
  - Simplify Path

💻 Template:
    stack<char> st;
    for (char c : s) {
        if (condition) st.push(c);
        else process(st);
    }
    return final stack-based result;

---------------------------------------------------------

8️⃣ TRIE / HASHING BASED PATTERN
---------------------------------------------------------
🧠 Use When:
  - You handle multiple words / prefixes efficiently

📘 Examples:
  - Word Search
  - Prefix Search (Autocomplete)
  - Replace Words

💻 Template:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
    };

---------------------------------------------------------

🧠 BONUS PATTERN: MANACHER’S ALGORITHM
---------------------------------------------------------
Use When:
  - Need longest palindromic substring in O(n)
  - Advanced but powerful for competitive coding

---------------------------------------------------------

✅ REMEMBER:
  - These patterns repeat in 90% of string interview questions.
  - The logic remains the same for arrays or other data types.
  - Focus on identifying *which pattern fits* the question.
=========================================================
*/
