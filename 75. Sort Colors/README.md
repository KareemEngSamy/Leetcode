# 75. Sort Colors

## Problem Statement

Given an array `nums` containing only:

* `0` → red
* `1` → white
* `2` → blue

Sort the array in-place so that objects of the same color are adjacent, in the order:

`0 → 1 → 2`

You must solve the problem without using the built-in sort function.


**Examples:**

* Input: `nums = [2,0,2,1,1,0]` → Output: `[0,0,1,1,2,2]`

* Input: `nums = [2,0,1]` → Output: `[0,1,2]`

**Constraints:**

* `1 <= nums.length <= 300`
* `nums[i]` is either `0`, `1`, or `2`

# 💡 Approach: Dutch National Flag Algorithm

## Key Idea

We use three pointers:

* `low` → next position for `0`
* `mid` → current element being processed
* `high` → next position for `2`

The array is divided into four parts:

* `[0 ... low-1]` → all `0`s
* `[low ... mid-1]` → all `1`s
* `[mid ... high]` → unknown
* `[high+1 ... end]` → all `2`s

## Rules

While `mid <= high`:

### Case 1: `nums[mid] == 0`

* Swap `nums[mid]` with `nums[low]`
* Increment both `low` and `mid`

### Case 2: `nums[mid] == 1`

* `1` is already in the correct section
* Increment `mid`

### Case 3: `nums[mid] == 2`

* Swap `nums[mid]` with `nums[high]`
* Decrement `high`
* Do not move `mid`
* The swapped value must still be checked

## Why It Works

* `low` keeps all `0`s on the left
* `high` keeps all `2`s on the right
* `mid` scans the array once
* Every swap places elements closer to their correct position

The algorithm finishes in one pass.

## Complexity

**Time Complexity:** `O(n)`
Each element is processed at most once.

**Space Complexity:** `O(1)`
Uses only constant extra space.

## Code (C++)

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
```
