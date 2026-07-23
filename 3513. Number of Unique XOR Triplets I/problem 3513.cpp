class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        // If n <= 2, the answer is n.
        if (n <= 2) return n;

        // If n >= 3, the answer is the smallest power of two greater than n
        int ans = 1;
        while (ans <= n) ans <<= 1;

        return ans;
    }
};
