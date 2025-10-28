# 219. Contains Duplicate II

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if there are two distinct indices `i` and `j` in the array such that `nums[i] == nums[j]` and `abs(i - j) <= k`.

## Examples

* **Input:** `nums = [1,2,3,1], k = 3`
  **Output:** `true`

* **Input:** `nums = [1,0,1,1], k = 1`
  **Output:** `true`

* **Input:** `nums = [1,2,3,1,2,3], k = 2`
  **Output:** `false`

## 💡 Approach: Sliding Window with Hash Set

## Key Idea

* Keep a sliding window of size at most `k`.
* Use a hash set to store the elements in the current window.
* For each new element `nums[r]`:
  * If it already exists in the set → duplicate found → return `true`.
  * Otherwise, insert it into the set.
* When the window exceeds size `k`, remove the oldest element `nums[l]`.

## Example Walkthrough (`nums = [1,2,3,1], k = 3`)

* Start: window = `{}`
* `r = 0`: add `1` → `{1}`
* `r = 1`: add `2` → `{1,2}`
* `r = 2`: add `3` → `{1,2,3}`
* `r = 3`: `nums[3] = 1` already exists in `{1,2,3}` → return `true`.

## Complexity

* **Time Complexity:** O(n)
  (Each element is inserted and erased at most once.)
* **Space Complexity:** O(k)
  (The hash set holds at most `k` elements.)

## Code (C++)

```cpp
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int l = 0, r = 0;

        while (r < nums.size()) {
            if (window.find(nums[r]) != window.end())
                return true;

            window.insert(nums[r]);

            if (r - l >= k) {
                window.erase(nums[l]);
                l++;
            }

            r++;
        }

        return false;
    }
};
```
