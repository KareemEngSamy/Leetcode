# 334. Increasing Triplet Subsequence

## Problem Statement

Given an integer array `nums`, return `true` if there exists a triplet of indices `(i, j, k)` such that:

* `i < j < k`
* `nums[i] < nums[j] < nums[k]`

Otherwise, return `false`.

**Examples:**

* Input: `nums = [1,2,3,4,5]` → Output: `true`

* Input: `nums = [5,4,3,2,1]` → Output: `false`

* Input: `nums = [2,1,5,0,4,6]` → Output: `true`

**Constraints:**

* 1 <= nums.length <= 5 × 10⁵
* -2³¹ <= nums[i] <= 2³¹ - 1


## 💡 Approach: Greedy Tracking

## Key Idea

We maintain two variables:

* `first` → smallest number seen so far
* `second` → smallest number greater than `first`

While traversing the array:

1. If the current number is smaller than or equal to `first`, update `first`.
2. Else if the current number is smaller than or equal to `second`, update `second`.
3. Else, we found a number greater than both `first` and `second`.

That means:

`first < second < current`

So an increasing triplet exists.


## Why It Works

* `first` always stores the minimum value seen so far.
* `second` stores the best possible middle value.
* If a number becomes larger than both, we successfully form an increasing subsequence of length 3.

The algorithm only scans the array once.

## Complexity

**Time Complexity:** `O(n)`
Each element is processed once.

**Space Complexity:** `O(1)`
Only two extra variables are used.



## Code (C++)

```cpp
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;

        for (int x : nums) {
            if (x <= first) {
                first = x;
            }
            else if (x <= second) {
                second = x;
            }
            else {
                return true;
            }
        }

        return false;
    }
};
```
