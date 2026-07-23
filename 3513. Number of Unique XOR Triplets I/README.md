# 3513. Number of Unique XOR Triplets I

## Problem Statement

You are given an integer array `nums` of length `n`, where `nums` is a permutation of the integers in the range `[1, n]`.

A XOR triplet is defined as:

```text
nums[i] ^ nums[j] ^ nums[k]
```

where:

```text
i <= j <= k
```

Return the number of **unique** XOR values that can be obtained from all possible triplets.

---

## Examples

### Example 1

Input:

```text
nums = [1,2]
```

Output:

```text
2
```

Explanation:

The possible XOR values are:

```text
1 ^ 1 ^ 1 = 1
1 ^ 1 ^ 2 = 2
1 ^ 2 ^ 2 = 1
2 ^ 2 ^ 2 = 2
```

Unique values are:

```text
{1, 2}
```

---

### Example 2

Input:

```text
nums = [3,1,2]
```

Output:

```text
4
```

Explanation:

Some possible XOR values are:

```text
3 ^ 3 ^ 3 = 3
3 ^ 3 ^ 1 = 1
3 ^ 3 ^ 2 = 2
3 ^ 1 ^ 2 = 0
```

Unique values are:

```text
{0,1,2,3}
```

---

## Key Observation

Since `nums` is a permutation of `[1, n]`, the order of elements does not matter.

The only thing that matters is the value of `n`.

After analyzing the XOR values for different sizes, we observe:

* If `n <= 2`, every number is the only possible unique XOR value.
* If `n >= 3`, the number of unique XOR values is always equal to the **smallest power of two greater than `n`**.

For example:

```text
n = 1 → 1
n = 2 → 2
n = 3 → 4
n = 4 → 8
n = 5 → 8
n = 6 → 8
n = 7 → 8
n = 8 → 16
```

---

## Approach 💡

### Mathematical Observation

1. Let `n` be the size of `nums`.
2. If `n <= 2`, return `n`.
3. Otherwise, repeatedly double a value starting from `1` until it becomes greater than `n`.
4. Return that value.

---

## Why This Works

The permutation already contains every integer from `1` to `n`.

For `n >= 3`, the set of achievable XOR values always fills the entire range represented by the next power of two.

Therefore, the answer depends only on `n` and is simply the smallest power of two greater than `n`.

---

## Complexity

### Time Complexity

```text
O(log n)
```

The loop doubles the value until it exceeds `n`, requiring at most `log₂(n)` iterations.

### Space Complexity

```text
O(1)
```

Only a few integer variables are used.

---

## Code (C++)

```cpp
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // If n <= 2, the answer is n.
        if (n <= 2) return n;

        // If n >= 3, the answer is the smallest power of two greater than n.
        int ans = 1;
        while (ans <= n) ans <<= 1;

        return ans;
    }
};
```
