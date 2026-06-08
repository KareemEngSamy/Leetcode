# 2161. Partition Array According to Given Pivot

## Problem Statement

You are given an integer array `nums` and an integer `pivot`.

Rearrange the array such that:

* All elements smaller than `pivot` appear first.
* All elements equal to `pivot` appear next.
* All elements greater than `pivot` appear last.
* The relative order of elements smaller than `pivot` is preserved.
* The relative order of elements greater than `pivot` is preserved.

Return the rearranged array.

---

## Examples

### Example 1

Input:

```text
nums = [9,12,5,10,14,3,10]
pivot = 10
```

Output:

```text
[9,5,3,10,10,12,14]
```

Explanation:

* Elements smaller than `10`: `[9,5,3]`
* Elements equal to `10`: `[10,10]`
* Elements greater than `10`: `[12,14]`

The original order inside each group remains unchanged.

### Example 2

Input:

```text
nums = [-3,4,3,2]
pivot = 2
```

Output:

```text
[-3,2,4,3]
```

Explanation:

* Elements smaller than `2`: `[-3]`
* Elements equal to `2`: `[2]`
* Elements greater than `2`: `[4,3]`

The relative order is preserved.

---

## Constraints

```text
1 <= nums.length <= 10^5
-10^6 <= nums[i] <= 10^6
pivot is guaranteed to exist in nums
```

---

## Key Idea

Since the relative order must be maintained, we cannot simply sort the array.

Instead:

* Store elements less than `pivot` in one list.
* Store elements equal to `pivot` in another list.
* Store elements greater than `pivot` in a third list.
* Concatenate the three lists.

This naturally preserves the original order inside each group.

---

## Approach 💡

### Three-Array Partition

Traverse the array once.

For each number:

* If `num < pivot`, add it to `less`.
* If `num == pivot`, add it to `equal`.
* If `num > pivot`, add it to `greater`.

Finally:

* Append all elements from `less`.
* Append all elements from `equal`.
* Append all elements from `greater`.

Return the resulting array.

---

## Why This Works

Every element belongs to exactly one of three categories:

* Less than `pivot`
* Equal to `pivot`
* Greater than `pivot`

Since elements are inserted into each list in their original order:

* Relative order of smaller elements is preserved.
* Relative order of greater elements is preserved.

Combining the three lists produces the required partition.

---

## Complexity

### Time Complexity

```text
O(n)
```

One pass to classify elements and one pass to build the answer.

### Space Complexity

```text
O(n)
```

Extra arrays store all elements.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less;
        vector<int> equal;
        vector<int> greater;

        for (int x : nums) {
            if (x < pivot) less.push_back(x);
            else if (x == pivot) equal.push_back(x);
            else greater.push_back(x);
        }

        vector<int> res;
        res.reserve(nums.size());

        for (int x : less) res.push_back(x);
        for (int x : equal) res.push_back(x);
        for (int x : greater) res.push_back(x);

        return res;
    }
};
```
