# 881. Boats to Save People

## Problem Statement

You are given an array `people` where `people[i]` represents the weight of the `i-th` person.

You are also given an integer `limit` representing the maximum weight a boat can carry.

Rules:

* Each boat can carry at most two people
* The total weight on a boat cannot exceed `limit`

Return the minimum number of boats needed to carry everyone.


**Examples:**

* Input: `people = [1,2]`, `limit = 3`
  Output: `1`

* Input: `people = [3,2,2,1]`, `limit = 3`
  Output: `3`

* Input: `people = [3,5,3,4]`, `limit = 5`
  Output: `4`

**Constraints:**

* `1 <= people.length <= 5 * 10^4`
* `1 <= people[i] <= limit <= 3 * 10^4`

# 💡 Approach: Sorting + Two Pointers

## Key Idea

We sort the array first.

Then we use two pointers:

* `l` points to the lightest person
* `r` points to the heaviest person

For every boat:

* If the lightest and heaviest together fit within the limit:

  * Put them together
  * Move both pointers
* Otherwise:

  * The heaviest person must go alone
  * Move only `r`

Each operation uses exactly one boat.


## Why It Works

The heaviest person is the hardest to place.

To minimize boats:

* Try pairing the heaviest person with the lightest possible person
* If they cannot fit together, the heaviest person cannot pair with anyone

Sorting allows us to make this greedy decision efficiently.

This guarantees the minimum number of boats.


## Complexity

**Time Complexity:** `O(n log n)`
Sorting dominates the complexity.

**Space Complexity:** `O(1)`
Ignoring the sorting space used internally.


## Code (C++)

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int ans = 0;
        int l = 0;
        int r = people.size() - 1;

        while(l <= r){
            if(people[r] + people[l] > limit){
                r--;
                ans++;
            }
            else{
                r--;
                l++;
                ans++;
            }
        }

        return ans;
    }
};
```
