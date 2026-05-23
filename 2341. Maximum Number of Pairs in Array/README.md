# 2341. Maximum Number of Pairs in Array

## Problem Statement

You are given a `0-indexed` integer array `nums`.

In one operation:

* Choose two equal integers from `nums`
* Remove both integers
* Form one pair

Repeat the operation as many times as possible.

Return an integer array `answer` of size `2` where:

* `answer[0]` = number of pairs formed
* `answer[1]` = number of leftover integers

**Examples:**

* Input: `nums = [1,3,2,1,3,2,2]`
  Output: `[3,1]`

* Input: `nums = [1,1]`
  Output: `[1,0]`

* Input: `nums = [0]`
  Output: `[0,1]`


**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 100`

# 💡 Approach: Frequency Counting

## Key Idea

We count how many times each number appears using a hash map.

For every number:

* `count / 2` gives how many pairs can be formed
* `count % 2` gives how many elements are left

Add all pairs together.

Add all leftovers together.


## Why It Works

A pair requires exactly two equal numbers.

If a number appears:

* `2` times → `1` pair
* `3` times → `1` pair and `1` leftover
* `4` times → `2` pairs

Using frequency counting lets us process every number once efficiently.


## Complexity

**Time Complexity:** `O(n)`
We traverse the array once to count frequencies and once more to calculate pairs and leftovers.

**Space Complexity:** `O(n)`
The hash map stores frequencies of elements.

## Code (C++)

```cpp
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> freq;

        for(int x:nums){
            freq[x]++;
        }

        int pairs = 0;
        int leftover = 0;

        for(auto it:freq){
            pairs += it.second / 2;
            leftover += it.second % 2;
        }

        return {pairs, leftover};
    }
};
```
