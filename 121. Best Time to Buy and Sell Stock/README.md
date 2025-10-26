# 121. Best Time to Buy and Sell Stock

## Problem Statement

You are given an integer array `prices`, where `prices[i]` represents the price of a stock on the `i-th` day.
You need to choose one day to buy the stock and a **different future day** to sell it to maximize profit.
Return the **maximum profit** you can achieve.
If no profit is possible, return `0`.

**Examples:**

* Input: `prices = [7,1,5,3,6,4]` → Output: `5`
  Explanation: Buy on day 2 (`price = 1`) and sell on day 5 (`price = 6`), profit = `6 - 1 = 5`.
* Input: `prices = [7,6,4,3,1]` → Output: `0`
  Explanation: No profitable transaction can be made.

**Constraints:**
1 <= prices.length <= 10⁵
0 <= prices[i] <= 10⁴

## 💡 Approach: Two Pointers (Sliding Window)

## Key Idea:

We use two pointers to represent the **buy** and **sell** days.

* `l` → buy pointer
* `r` → sell pointer

1. Move `r` forward to explore future prices.
2. If `prices[r] > prices[l]`, compute profit = `prices[r] - prices[l]` and update `maxProfit`.
3. If `prices[r] <= prices[l]`, move `l` to `r` (new minimum price).

## Why It Works:

* The left pointer always tracks the **lowest buying price** seen so far.
* The right pointer checks for **profitable selling prices**.
* Every price is visited once, so the algorithm runs efficiently in linear time.

## Example Walkthrough (`prices = [7,1,5,3,6,4]`)

1. Start with `l = 0`, `r = 1`, `maxProfit = 0`.
2. Compare `prices[l]=7` and `prices[r]=1` → move `l` to `1`.
3. `prices[l]=1`, `prices[r]=5` → profit = `4`, update `maxProfit=4`.
4. `prices[r]=3` → profit = `2` (ignore).
5. `prices[r]=6` → profit = `5`, update `maxProfit=5`.
6. `prices[r]=4` → profit = `3` (ignore).

**Result:** Maximum profit = **5**.

## Complexity

**Time Complexity:** O(n)
Each price is processed once.

**Space Complexity:** O(1)
Uses constant extra variables only.

## Code (C++)

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, maxProfit = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int profit = prices[r] - prices[l];
                maxProfit = max(maxProfit, profit);
            } else {
                l = r;
            }
            r++;
        }

        return maxProfit;
    }
};
```
