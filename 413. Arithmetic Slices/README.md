# 413. Arithmetic Slices

## Problem Statement
An integer array is called **arithmetic** if:  
- It has **at least 3 elements**.  
- The difference between consecutive elements is the same.  

Given an integer array `nums`, return the **number of arithmetic subarrays**.  
A subarray is a **contiguous subsequence** of the array.


## Examples
- **Input:** `nums = [1,2,3,4]`  
  **Output:** `3`  
  Explanation: `[1,2,3]`, `[2,3,4]`, and `[1,2,3,4]`.  

- **Input:** `nums = [1]`  
  **Output:** `0`  



## 💡 Approach: Sliding Window over Arithmetic Runs

### Key Idea
- We scan the array from left to right, maintaining the **longest arithmetic window** that ends at index `r`.  
- If `nums[r] - nums[r-1] == nums[r-1] - nums[r-2]`, the arithmetic streak continues.  
- Otherwise, the streak is broken, and we reset the left pointer `l` to `r-1`.  
- For each index `r`, if the current window length `len = r - l + 1` is at least 3:  
  - We add `(len - 2)` to the result.  
  - Why `(len - 2)`? → Because a window of length `k` contributes `(k - 2)` new arithmetic slices ending at `r`.  



## Example Walkthrough (`nums = [1,2,3,4]`)
- Start: `l = 0`.  
- `r = 2`: `[1,2,3]` is arithmetic → `len = 3`, add `(3-2) = 1`.  
- `r = 3`: `[1,2,3,4]` is arithmetic → `len = 4`, add `(4-2) = 2`.  
- Total = `3`.  



## Complexity
- **Time Complexity:** O(n)  
  (Single pass through array, each element checked once.)  
- **Space Complexity:** O(1)  
  (Only a few pointers and counters used.)  



## Code (C++)
```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        int res = 0;
        int n = nums.size();
        int l = 0;  // left pointer of current arithmetic window

        for (int r = 2; r < n; r++) {

            // check if nums[l→r] is still arithmetic
            if (nums[r] - nums[r-1] != nums[r-1] - nums[r-2]) {
                // streak breaks → reset left pointer
                l = r - 1;
            }

            int len = r - l + 1;
            if (len >= 3) {
                res += (len - 2); 
            }
        }

        return res;
    }
};
