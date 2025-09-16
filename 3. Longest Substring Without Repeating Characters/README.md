# 3. Longest Substring Without Repeating chars

## Problem Statement
Given a string `s`, find the length of the **longest substring** without repeating characters.  
A substring is a contiguous sequence of characters within a string.

**Examples:**
- Input: `s = "abcabcbb"` → Output: `3`  
  Explanation: The answer is `"abc"`.
- Input: `s = "bbbbb"` → Output: `1`  
  Explanation: The answer is `"b"`.
- Input: `s = "pwwkew"` → Output: `3`  
  Explanation: The answer is `"wke"`.  
  Note: `"pwke"` is a subsequence, not a substring.



## 💡 Approach: Sliding Window + Unordered Set

## Key Idea:
We maintain a **sliding window** (two pointers `l` and `r`) over the string:
- `unordered_set<char>` stores the characters currently inside the window.
- Expand the window by moving the right pointer `r`.
- If we encounter a duplicate character:
  - Shrink the window by moving the left pointer `l` until the duplicate is removed.
- At each step, update the maximum window length.



## Why It Works:
- Each character is inserted and removed from the set **at most once**.
- This ensures **linear time complexity** on average.
- Using `unordered_set` makes lookup, insert, and erase operations **O(1) average**.


## Example Walkthrough (`s = "pwwkew"`)
1. Start with empty window: `l = 0, r = 0`.
2. Add `'p'` → window = `"p"`, size = 1.
3. Add `'w'` → window = `"pw"`, size = 2.
4. Next `'w'` is a duplicate → remove `'p'`, then remove `'w'` until unique → window = `"w"`.
5. Add `'k'` → window = `"wk"`, size = 2.
6. Add `'e'` → window = `"wke"`, size = 3 (max so far).
7. Add `'w'` (duplicate) → shrink from left → window = `"ew"`, size = 2.

**Result:** Maximum substring length = **3** (`"wke"`).



## ⏱️ Complexity
- **Time Complexity:** O(n) average  
  (Each character processed at most twice: once when added, once when removed.)  
- **Space Complexity:** O(min(n, charset))  
  (For ASCII, at most 128 or 256 characters in the set.)



## Code (C++)
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, res = 0;
        unordered_set<char> myset;

        for (int r = 0; r < s.length(); r++) {
            while (myset.find(s[r]) != myset.end()) {
                myset.erase(s[l]);
                l++;
            }
            myset.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
