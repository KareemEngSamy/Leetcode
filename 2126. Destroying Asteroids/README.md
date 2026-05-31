# 2126. Destroying Asteroids

## Problem Statement

You are given:

* An integer `mass` representing the initial mass of a planet
* An integer array `asteroids`, where `asteroids[i]` is the mass of the i-th asteroid

You can choose the order in which the planet collides with the asteroids.

Rules:

* If `planet mass >= asteroid mass` → asteroid is destroyed and the planet gains that mass
* Otherwise → the planet is destroyed and the process stops immediately

Return:

* `true` if the planet can destroy all asteroids
* `false` otherwise

---

## Examples

### Example 1

Input:

* `mass = 10`
* `asteroids = [3, 9, 19, 5, 21]`

Output:

* `true`

Explanation:
One valid order:

* 10 → 19 → 38 → 43 → 46 → 67
  All asteroids are destroyed.

---

### Example 2

Input:

* `mass = 5`
* `asteroids = [4, 9, 23, 4]`

Output:

* `false`

Explanation:
After consuming smaller asteroids:

* Final mass = 22
* Cannot destroy asteroid with mass 23

---

## Constraints

* `1 <= mass <= 10^5`
* `1 <= asteroids.length <= 10^5`
* `1 <= asteroids[i] <= 10^5`

---

## Key Idea

You want to maximize your growth as early as possible.

Smaller asteroids are easier to absorb, and every successful absorption increases your mass, allowing you to handle larger ones later.

So the optimal strategy is:

* Always destroy asteroids in increasing order of mass

---

## Approach

### Greedy Strategy

1. Sort the asteroid array in ascending order
2. Start with `current_mass = mass`
3. Iterate through asteroids:

   * If `current_mass < asteroid[i]`, return `false`
   * Otherwise, add asteroid mass to `current_mass`
4. If all asteroids are processed, return `true`

---

## Why This Works

* If you cannot destroy a small asteroid, you will never be able to destroy a larger one
* Sorting ensures you always grow your mass in the most efficient way
* Any other ordering can only delay growth or cause earlier failure

This is a classic greedy ordering problem.

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
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long current_mass = mass;

        sort(asteroids.begin(), asteroids.end());

        for (int x : asteroids) {
            if (current_mass < x) return false;
            current_mass += x;
        }

        return true;
    }
};
```
