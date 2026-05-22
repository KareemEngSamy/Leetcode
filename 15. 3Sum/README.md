# 15. 3Sum

## Problem Statement

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that:

* `i != j`
* `i != k`
* `j != k`
* `nums[i] + nums[j] + nums[k] == 0`

The solution set must not contain duplicate triplets.

**Examples:**

* Input: `nums = [-1,0,1,2,-1,-4]`
  Output: `[[-1,-1,2],[-1,0,1]]`

* Input: `nums = [0,1,1]`
  Output: `[]`

* Input: `nums = [0,0,0]`
  Output: `[[0,0,0]]`

**Constraints:**

* `3 <= nums.length <= 3000`
* `-10^5 <= nums[i] <= 10^5`

# 💡 Approach: Sorting + Two Pointers

## Key Idea

We sort the array first.

Then for every element:

* Fix it as the first number
* Use two pointers to find the other two numbers

The pointers work like this:

* If the sum is too small → move `left`
* If the sum is too large → move `right`
* If the sum is `0` → store the triplet

We also skip duplicates to avoid repeated answers.

## Why It Works

After sorting:

* Moving `left` increases the sum
* Moving `right` decreases the sum

This allows us to search efficiently in linear time for every fixed element.

Skipping duplicates ensures:

* No repeated triplets appear in the final answer

Instead of checking all triplets with `O(n³)`, we reduce it to `O(n²)`.


## Complexity

**Time Complexity:** `O(n²)`
Sorting takes `O(n log n)` and the two-pointer traversal takes `O(n²)`.

**Space Complexity:** `O(1)`
Ignoring the output array.

## Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i=0; i<n; i++) {
            //skip duplicate first elements
            if(i>0 && nums[i]==nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                    // Skip duplicates
                    while(left<right && nums[left]==nums[left-1]) left++;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }
                else if(sum<0) left++;
                else right--;
            }
        }
        
        return ans;
    }
};
```
