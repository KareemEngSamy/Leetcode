# 2144. Minimum Cost of Buying Candies With Discount

## Problem Statement

A shop offers the following discount:

* For every 2 candies you buy, you can get 1 additional candy for free
* The free candy must have a cost less than or equal to the cheaper of the two purchased candies

You are given an integer array `cost` where `cost[i]` is the price of the i-th candy.

Return The minimum cost required to buy all candies.

## Examples

Input: `cost = [1,2,3]`
Output: `5`

Input: `cost = [6,5,7,9,2,2]`
Output: `23`

Input: `cost = [5,5]`
Output: `10`

## Constraints

* `1 <= cost.length <= 100`
* `1 <= cost[i] <= 100`

---

## Key Idea

To minimize the amount paid, we want the free candies to be as expensive as possible.

The best strategy is:

* Sort candies in descending order
* For every group of 3 candies:

  * Pay for the first two
  * Take the third one for free

This guarantees that the free candy is the most expensive candy that can legally be free.

---

## Approach 💡

### Greedy Strategy

1. Sort the array in descending order
2. Traverse the sorted array
3. Add every candy to the answer except every third candy
4. Return the total cost

---

## Why This Works

After sorting in descending order:

```text
9 7 6 5 2 2
```

We can form groups:

```text
(9, 7, 6)
(5, 2, 2)
```

In each group:

* The first two candies are purchased
* The third candy is free

Since the array is sorted, the third candy is always less than or equal to the first two candies, satisfying the discount rule.

Making every third candy free maximizes the total discount.

This is a classic greedy sorting problem.

---

## Complexity

### Time Complexity

* Sorting: `O(n log n)`
* Traversal: `O(n)`
* Total: `O(n log n)`

### Space Complexity

* `O(1)` extra space (ignoring sorting)

---

## Code (C++)

```cpp
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.rbegin(), cost.rend());

        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) {
                ans += cost[i];
            }
        }

        return ans;
    }
};
```
