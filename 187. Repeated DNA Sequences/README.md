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

## 💡 Approach: Sliding Window + Hash Map

## Key Idea:

We use a **hash map** to store and count all 10-letter substrings.

* The key is the substring itself.
* The value is the number of times it appears.
  After counting, any substring that appears **more than once** is added to the result vector.

## Why It Works:

* Each substring of length 10 is processed exactly once.
* Hash maps provide **O(1)** average time for insert and lookup operations.
* Counting occurrences ensures we detect all repeated sequences precisely.
* Efficient for long DNA strings due to single linear traversal.

## Example Walkthrough

### `(s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT")`

1. Traverse the string using a sliding window of length 10.
2. `"AAAAACCCCC"` appears twice.
3. `"CCCCCAAAAA"` appears twice.
4. All other substrings appear once.

**Result:** `["AAAAACCCCC", "CCCCCAAAAA"]`

## Complexity

### **Time Complexity: O(n)**

Each 10-letter substring is processed once and stored or updated in O(1) average time.

### **Space Complexity: O(n)**

Up to O(n) unique substrings stored in the hash map.

## Code (C++)

```cpp
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        vector<string> result;

        for (int i = 0; i + 9 < s.size(); i++) {
            string sub = s.substr(i, 10);
            count[sub]++;
        }

        for (auto& [sub, freq] : count) {
            if (freq > 1)
                result.push_back(sub);
        }

        return result;
    }
};
```
