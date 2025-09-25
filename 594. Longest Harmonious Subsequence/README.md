# 594. Longest Harmonious Subsequence

## Problem Statement

We define a **harmonious array** as an array where the **difference between the maximum and minimum value is exactly `1`**.
Given an integer array `nums`, return the length of the **longest harmonious subsequence** (not necessarily contiguous) among all possible subsequences.

### Examples

* **Input:** `nums = [1,3,2,2,5,2,3,7]`
  **Output:** `5`
  **Explanation:** The longest harmonious subsequence is `[3,2,2,2,3]`.

* **Input:** `nums = [1,2,3,4]`
  **Output:** `2`
  **Explanation:** The longest harmonious subsequences are `[1,2]`, `[2,3]`, or `[3,4]`.

* **Input:** `nums = [1,1,1,1]`
  **Output:** `0`
  **Explanation:** No subsequence exists with max–min = 1.



## 💡 Approach 1: Sliding Window (Two Pointers)

### Key Idea

If the array is **sorted**, the max/min difference of any contiguous window is `nums[r] - nums[l]`.

* Expand the right pointer `r` while maintaining a window `[l..r]`.
* Shrink the left pointer `l` whenever the difference exceeds 1.
* Whenever the difference equals 1, update the answer with the current window size.

### Steps

1. Sort the array.
2. Initialize two pointers `l = 0`, `r = 0`.
3. For each `r`:

   * While `nums[r] - nums[l] > 1`, increment `l`.
   * If `nums[r] - nums[l] == 1`, update the maximum window length.

### Complexity

* **Time Complexity:** `O(n log n)` (sorting dominates)
* **Space Complexity:** `O(1)` (in place sorting)

### Code (C++)

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        sort(nums.begin(), nums.end());
        int l = 0, ans = 0;

        for (int r = 0; r < nums.size(); ++r) {
            while (l < r && nums[r] - nums[l] > 1) l++;
            if (nums[r] - nums[l] == 1)
                ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
```

## 💡 Approach 2: Hash Map Frequency

### Key Idea

For each unique number `x`, the best harmonious subsequence containing `x` is formed by **all occurrences of `x` and `x+1`**.

* Count frequencies of all numbers.
* For each key `x`, if `x+1` exists, compute `freq[x] + freq[x+1]` and track the maximum.

### Complexity

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)` (hash map storage)

### Code (C++)

```cpp
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;

        int ans = 0;
        for (auto &p : freq) {
            int val = p.first;
            if (freq.count(val + 1))
                ans = max(ans, p.second + freq[val + 1]);
        }
        return ans;
    }
};
```


## Summary of Approaches

* Sliding Window

  * Time Complexity: **O(n log n)** (sorting dominates)
  * Space Complexity: **O(1)**
  * Requires sorting but no extra data structure.

* Hash Map Count

  * Time Complexity: **O(n)**
  * Space Complexity: **O(n)**
  * Faster overall but needs additional memory for the frequency map.

