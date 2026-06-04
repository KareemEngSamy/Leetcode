# 3751. Total Waviness of Numbers in Range I

## Problem Statement

You are given two integers `num1` and `num2` representing an inclusive range `[num1, num2]`.

The waviness of a number is defined as the total number of peaks and valleys in its digits.

A digit is:

* A peak if it is strictly greater than both adjacent digits
* A valley if it is strictly less than both adjacent digits

Notes:

* The first and last digits can never be peaks or valleys
* Numbers with fewer than 3 digits have a waviness of `0`

Return the sum of waviness values for all numbers in the range `[num1, num2]`.

## Examples

* Input: `num1 = 120, num2 = 130`

* Output: `3`

Explanation:

```text
120 → 1 peak
121 → 1 peak
130 → 1 peak
```

* Input: `num1 = 198, num2 = 202`

* Output: `3`

Explanation:

```text
198 → 1 peak
201 → 1 valley
202 → 1 valley
```

* Input: `num1 = 4848, num2 = 4848`

* Output: `2`

Explanation: The digit `8` is a peak and the digit `4` is a valley.

## Constraints

* `1 <= num1 <= num2 <= 10^5`

---

## Key Idea

Since the largest possible number is only `100000`, every number contains at most 6 digits.

We can simply:

* Iterate through every number in the range
* Convert it to a string
* Check each middle digit
* Count peaks and valleys

The constraints are small enough that a direct simulation is efficient.

---

## Approach 💡

### Calculate Waviness of One Number

For a given number:

1. Convert it to a string
2. If its length is less than 3, return `0`
3. Traverse all middle digits
4. Count:

   * Peaks:

     ```text
     digit > left digit
     digit > right digit
     ```
   * Valleys:

     ```text
     digit < left digit
     digit < right digit
     ```
5. Return the count

### Process the Entire Range

1. Iterate from `num1` to `num2`
2. Compute the waviness of each number
3. Add it to the answer
4. Return the total sum

---

## Why This Works

A digit can only contribute to waviness if it has both a left and right neighbor.

For every middle digit:

```text
left < current > right
```

means it is a peak.

Similarly:

```text
left > current < right
```

means it is a valley.

By checking every middle digit exactly once, we correctly count all peaks and valleys in a number.

Summing these values for every number in the range gives the required answer.

---

## Complexity

### Time Complexity

Let:

* `n = num2 - num1 + 1`
* `d = number of digits`

For each number we scan all digits.

```text
O(n × d)
```

Since `d ≤ 6`:

```text
O(n)
```

for the given constraints.

### Space Complexity

```text
O(d)
```

for the temporary string representation.

Since `d ≤ 6`, this is effectively:

```text
O(1)
```

---

## Code (C++)

```cpp
class Solution {
public:
    int waviness(int x){
        string s = to_string(x);
        if(s.length() < 3) return 0;

        int cnt = 0;

        for(int i = 1; i < s.length() - 1; i++){
            if(s[i] > s[i - 1] && s[i] > s[i + 1])
                cnt++;
            else if(s[i] < s[i - 1] && s[i] < s[i + 1])
                cnt++;
        }

        return cnt;
    }

    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for(int x = num1; x <= num2; x++){
            ans += waviness(x);
        }

        return ans;
    }
};
```
