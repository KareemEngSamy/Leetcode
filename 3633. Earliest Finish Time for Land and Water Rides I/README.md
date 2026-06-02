# 3633. Earliest Finish Time for Land and Water Rides I

## Problem Statement

You are given two categories of theme park attractions:

* Land rides
* Water rides

Each ride has:

* an earliest start time
* a duration

A tourist must take exactly one land ride and one water ride in any order.

Rules:

* You may start a ride at its opening time or later
* If you arrive early, you wait
* After finishing the first ride, you immediately move to the second (or wait until it opens)

Return the earliest possible time to finish both rides.

---

## Examples

### Example 1

Input:

```text
landStartTime = [2,8]
landDuration = [4,1]
waterStartTime = [6]
waterDuration = [3]
```

Output:

```text
9
```
--- 

### Example 2

Input:

```text
landStartTime = [5]
landDuration = [3]
waterStartTime = [1]
waterDuration = [10]
```

Output:

```text
14
```

---

## Constraints

* `1 <= n, m <= 100`
* `landStartTime.length == landDuration.length == n`
* `waterStartTime.length == waterDuration.length == m`
* `1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 1000`

---

## Key Idea

Try all pairs of land and water rides.

For each pair, simulate both orders:

* Land → Water
* Water → Land

Use the correct waiting rule:

```text
finish = max(first_end, second_start) + second_duration
```

---

## Approach 💡

### Brute Force

1. Iterate over all land rides
2. Iterate over all water rides
3. Compute both orders:

   * Land → Water
   * Water → Land
4. Track the minimum finish time

---

## Why This Works

The second ride may start later than:

* the first ride finish time
* its own opening time

So we always take:

```text
max(first_finish, second_start_time)
```

This correctly models waiting time and scheduling constraints.

---

## Complexity

### Time Complexity

* `O(n * m)`
* At most `100 * 100 = 10,000` operations

### Space Complexity

* `O(1)`

---

## Code (C++)

```cpp
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int landEnd = landStartTime[i] + landDuration[i];
                int waterEnd = waterStartTime[j] + waterDuration[j];
                // Land -> Water
                ans = min(ans, waterDuration[j] + max(landEnd, waterStartTime[j]));
                // Water -> Land
                ans = min(ans, landDuration[i] + max(waterEnd, landStartTime[i]));
            }
        }

        return ans;
    }
};
```
