# 3300. Minimum Element After Replacement With Digit Sum

## Problem Statement

You are given an integer array `nums`.

Replace each element with the sum of its digits.

Return the minimum element in the array after all replacements.



**Examples:**

* Input: `nums = [10,12,13,14]`
  Output: `1`

* Input: `nums = [1,2,3,4]`
  Output: `1`

* Input: `nums = [999,19,199]`
  Output: `10`

## Constraints

* `1 <= nums.length <= 100`
* `1 <= nums[i] <= 10^4`

# 💡 Approach

## Key Idea

For every number in the array:

1. Extract each digit
2. Compute the digit sum
3. Keep track of the minimum digit sum found

We do not need:

* An extra array
* Sorting

We only maintain a running minimum.


## How Digit Sum Works

To get the sum of digits of a number:

### Last Digit

```
num % 10
```

### Remove Last Digit

```
num /= 10
```

Repeat until the number becomes `0`.

Example for `199`:

```text
199 % 10 = 9
19 % 10 = 9
1 % 10 = 1

Sum = 19
```

## Why It Works

* Every number is converted into its digit sum
* `mn` always stores the smallest digit sum seen so far
* After processing all elements, `mn` is the answer

## Complexity

### Time Complexity

`O(n * d)`

* `n` = number of elements
* `d` = number of digits

Each digit is processed once.

### Space Complexity

`O(1)`

Only constant extra space is used.


## Code (C++)

```cpp
class Solution {
public:
    int minElement(vector<int>& nums) {
        int mn = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            int temp = 0;

            while(nums[i] > 0){
                temp += nums[i] % 10;
                nums[i] /= 10;
            }

            mn = min(mn, temp);
        }

        return mn;
    }
};
```
