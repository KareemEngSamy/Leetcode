# 209. Minimum Size Subarray Sum

## Problem Statement
Given an array of positive integers `nums` and a positive integer `target`, return the **minimal length** of a contiguous subarray such that the sum is **greater than or equal to** `target`.  
If there is no such subarray, return `0`.

### Examples
- **Input:** `target = 7, nums = [2,3,1,2,4,3]`  
  **Output:** `2`  
  Explanation: The subarray `[4,3]` has the minimal length.
  
- **Input:** `target = 4, nums = [1,4,4]`  
  **Output:** `1`  

- **Input:** `target = 11, nums = [1,1,1,1,1,1,1,1]`  
  **Output:** `0`  


## 💡 Approach: Sliding Window (Two Pointers)

## Key Idea
We use two pointers (`l` and `r`) to create a **sliding window** over the array:
- Expand the window by moving the right pointer `r`, adding `nums[r]` to the current sum.
- While the sum is **greater than or equal to target**, try shrinking the window from the left (`l`) to minimize its size.
- Track the minimum length of all valid windows found.



## Example Walkthrough (`target = 7, nums = [2,3,1,2,4,3]`)
1. Start with empty window: `l = 0, sum = 0`.
2. Expand window:
   - Add `2` → sum = 2.
   - Add `3` → sum = 5.
   - Add `1` → sum = 6.
   - Add `2` → sum = 8 ≥ target → window = `[2,3,1,2]` (length = 4).
3. Shrink from left:
   - Remove `2` → sum = 6.
   - Add `4` → sum = 10 ≥ target → window = `[3,1,2,4]` (length = 4).
   - Shrink left → `[1,2,4]` sum = 7 → length = 3.
   - Shrink left → `[2,4]` sum = 6 (< target).
4. Continue → next valid window `[4,3]` with length = 2.
5. Result = **2**.


## Complexity
- **Time Complexity:** O(n)  
  (Each element added once and removed once at most.)  
- **Space Complexity:** O(1)  
  (Only a few variables are used, no extra data structures.)


## Code (C++)
```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, sum = 0, res = INT_MAX;

        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                res = min(res, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};
