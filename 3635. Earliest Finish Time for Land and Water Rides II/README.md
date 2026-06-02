# 3635. Earliest Finish Time for Land and Water Rides II

## Problem Statement

You are given two categories of theme park attractions:

* Land rides
* Water rides

Each ride has:

* an earliest start time (`landStartTime`, `waterStartTime`)
* a duration (`landDuration`, `waterDuration`)

A tourist must take exactly one land ride and one water ride in any order.

Rules:

* You may start a ride at its opening time or any later moment.
* If you arrive early for a ride, you wait until it opens.
* Immediately after finishing the first ride, the tourist may board the second (if it is open) or wait until it opens.

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

## Constraints (The "Version II" Catch)

* `1 <= n, m <= 5 * 10^4` *(Version I was up to 100 only!)*
* `landStartTime.length == landDuration.length == n`
* `waterStartTime.length == waterDuration.length == m`
* `1 <= landStartTime[i], landDuration[i], waterStartTime[j], waterDuration[j] <= 10^5`

**Why Version I approach fails here?** 
* `N, M <= 100` meant a brute-force `O(N * M)` approach took at most 10,000 operations. 
* Now `50,000 * 50,000 = 2.5 billion` operations, which will result in a **TLE** error.

---

## Key Idea

Instead of checking every single pair, we can mathematically decouple the loops.

Look at the wait-time formula for taking a Land ride first, then a Water ride:
`finishTime = max(landEnd[i], waterStartTime[j]) + waterDuration[j]`

For any specific water ride `j`, its start time and duration are fixed constants. The only way to minimize this formula is to provide the **smallest possible `landEnd` time** from the first ride. We don't need to check every land ride against every water ride; we only need to pair the single *fastest finishing* land ride with every water ride (and vice versa).

---

## Approach 💡

### Optimized Greedy (Decoupled Loops)

**Find Best First Rides:**
* Iterate through all land rides to find the earliest absolute finish time (`minLandEnd`).
* Iterate through all water rides to find the earliest absolute finish time (`minWaterEnd`).


**Test Scenarios:**
* **Land → Water:** Pair the `minLandEnd` with every water ride `j` to find the earliest overall finish.
* **Water → Land:** Pair the `minWaterEnd` with every land ride `i` to find the earliest overall finish.


Return the minimum of all these scenarios.

---

## Complexity

### Time Complexity

* `O(n + m)`
* We process the `land` array twice (once for the min, once for the pairing) and the `water` array twice. This reduces operations from ~2.5 billion to ~200,000, easily passing the constraints.

### Space Complexity

* `O(1)`

---

## Code (C++)

```cpp
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Earliest possible time we can finish any land ride
        int minLandEnd = INT_MAX;
        for (int i = 0; i < n; i++) {
            minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
        }

        // Earliest possible time we can finish any water ride
        int minWaterEnd = INT_MAX;
        for (int j = 0; j < m; j++) {
            minWaterEnd = min(minWaterEnd, waterStartTime[j] + waterDuration[j]);
        }

        int ans = INT_MAX;

        // Land -> Water
        // Take the fastest land ride, then iterate through water rides to find the best finish.
        for (int j = 0; j < m; j++) {
            int finishTime = max(minLandEnd, waterStartTime[j]) + waterDuration[j];
            ans = min(ans, finishTime);
        }

        // Water -> Land
        // Take the fastest water ride, then iterate through land rides to find the best finish.
        for (int i = 0; i < n; i++) {
            int finishTime = max(minWaterEnd, landStartTime[i]) + landDuration[i];
            ans = min(ans, finishTime);
        }

        return ans;
    }
};

```