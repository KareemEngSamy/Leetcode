
# 1331. Rank Transform of an Array

## Problem Statement

Given an integer array `arr`, replace each element with its rank.

The rank follows these rules:

* Rank starts from `1`.
* The larger the element, the larger the rank.
* Equal elements must have the same rank.
* Ranks should be as small as possible.

Return the transformed array.

---

## Examples

### Example 1

Input:

```text
arr = [40,10,20,30]
```

Output:

```text
[4,1,2,3]
```

Explanation:

* `10` is the smallest element → rank `1`
* `20` is the second smallest → rank `2`
* `30` is the third smallest → rank `3`
* `40` is the largest → rank `4`

---

### Example 2

Input:

```text
arr = [100,100,100]
```

Output:

```text
[1,1,1]
```

Explanation:

All elements are equal, so they share the same rank.

---

### Example 3

Input:

```text
arr = [37,12,28,9,100,56,80,5,12]
```

Output:

```text
[5,3,4,2,8,6,7,1,3]
```

---

## Constraints

```text
0 <= arr.length <= 10^5
-10^9 <= arr[i] <= 10^9
```

---

## Key Idea

The rank of a number depends only on its position among the **unique sorted values**.

Instead of comparing every element with every other element:

1. Create a sorted copy of the array.
2. Assign ranks only to unique values.
3. Replace each original value with its assigned rank using a hash map.

This avoids repeated comparisons and efficiently handles duplicate values.

---

## Approach 💡

### Sorting + Hash Map

1. Make a copy of the original array.
2. Sort the copied array.
3. Traverse the sorted array:
   * If the current value hasn't been assigned a rank yet, assign the next available rank.
4. Traverse the original array:
   * Replace each element with its corresponding rank from the hash map.
5. Return the transformed array.

---

## Why This Works

Sorting places all values in increasing order.

Since duplicates appear consecutively in the sorted array, assigning a rank only the **first time** a value is encountered ensures:

* Equal values receive the same rank.
* Smaller values receive smaller ranks.
* Ranks remain consecutive with no gaps.

Finally, looking up each original value in the hash map produces the required rank transformation.

---

## Complexity

### Time Complexity

```text
O(n log n)
```

* Sorting the copied array takes `O(n log n)`.
* Building the hash map takes `O(n)`.
* Transforming the original array takes `O(n)`.

Overall complexity is dominated by sorting.

### Space Complexity

```text
O(n)
```

* The sorted copy requires `O(n)` space.
* The hash map storing ranks also requires up to `O(n)` space.

---

## Code (C++)

```cpp
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int r = 1;

        for (int x : sorted) {
            if (rank.find(x) == rank.end()) {
                rank[x] = r++;
            }
        }

        for (int &x : arr) {
            x = rank[x];
        }

        return arr;
    }
};
```