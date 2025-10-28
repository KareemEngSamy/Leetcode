# 217. Contains Duplicate

## Problem Statement

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is **distinct**.

## Examples

* **Input:** `nums = [1,2,3,1]`
  **Output:** `true`
  

* **Input:** `nums = [1,2,3,4]`
  **Output:** `false`


* **Input:** `nums = [1,1,1,3,3,4,3,2,4,2]`
  **Output:** `true`


## 💡 Approach: Hash Set for Duplicate Detection

## Key Idea

* Use a **hash set** to track unique elements as we iterate.
* For each number `n` in `nums`:

  * If `n` already exists in the set → duplicate found → return `true`.
  * Otherwise, insert `n` into the set.
* If the loop finishes with no duplicates found, return `false`.

## Example Walkthrough (`nums = [1,2,3,1]`)

* Start: `unique = {}`
* Check `1`: not in set → add → `{1}`
* Check `2`: not in set → add → `{1,2}`
* Check `3`: not in set → add → `{1,2,3}`
* Check `1`: already in `{1,2,3}` → return `true`.

## Complexity

* **Time Complexity:** O(n)
  (Each lookup and insertion in the hash set is O(1) on average.)
* **Space Complexity:** O(n)
  (In the worst case, all elements are distinct.)

## Code (C++)

```cpp
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> unique = {};

        for (int n : nums) {
            if (unique.find(n) != unique.end())
                return true;
            unique.insert(n);
        }

        return false;
    }
};
```
