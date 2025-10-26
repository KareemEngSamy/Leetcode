# 187. Repeated DNA Sequences

## Problem Statement

You are given a string `s` that represents a **DNA sequence**, consisting of the characters `'A'`, `'C'`, `'G'`, and `'T'`.

Return all **10-letter-long substrings** (subsequences of consecutive characters) that occur **more than once** in the sequence.
The answer can be returned in any order.

**Examples:**

* Input: `s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"` → Output: `["AAAAACCCCC","CCCCCAAAAA"]`
* Input: `s = "AAAAAAAAAAAAA"` → Output: `["AAAAAAAAAA"]`

**Constraints:**
1 <= s.length <= 10⁵
`s[i]` is one of `'A'`, `'C'`, `'G'`, `'T'`

## 💡 Approach: Sliding Window + Hash Sets

## Key Idea:

We move a **sliding window** of length 10 along the string and track each 10-letter substring.

* Use a set `seen` to store substrings that appear once.
* Use another set `repeated` to store substrings that appear more than once.
* Convert the `repeated` set to a vector for the final answer.

## Why It Works:

* Every substring of length 10 is checked exactly once.
* Sets provide **O(1)** average time for insert and lookup.
* Duplicates are automatically filtered by moving from `seen` to `repeated`.
* The algorithm efficiently handles large strings because it uses constant extra space per unique substring.

## Example Walkthrough 
### `(s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")`

1. Scan all 10-character substrings.

   * First `"AAAAACCCCC"` → add to `seen`.
   * Next `"AAAACCCCCA"` → add to `seen`.
   * Continue until `"AAAAACCCCC"` repeats → move it to `repeated`.
   * `"CCCCCAAAAA"` also repeats later → move it to `repeated`.
2. After scanning the entire string, `repeated = {"AAAAACCCCC", "CCCCCAAAAA"}`.

**Result:** `["AAAAACCCCC", "CCCCCAAAAA"]`

## Complexity

### **Time Complexity: O(n)** 
* Each substring processed once  
* O(1) is the average lookup per set.

### **Space Complexity: O(n)** 
* At most O(n) substrings stored across both sets.

## Code (C++)

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen, repeated;
        vector<string> result;

        for (int i = 0; i + 9 < s.size(); i++) {
            string sub = s.substr(i, 10);
            if (seen.count(sub))
                repeated.insert(sub);
            else
                seen.insert(sub);
        }

        for (const string& seq : repeated)
            result.push_back(seq);

        return result;
    }
};
```
