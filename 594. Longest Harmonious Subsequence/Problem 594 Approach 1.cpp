class Solution {
public:
    int findLHS(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        sort(nums.begin(), nums.end());
        int l = 0, ans = 0;

        for (int r = 0; r < nums.size(); ++r) {
            // shrink while difference > 1
            while (l < r && nums[r] - nums[l] > 1) l++;
            // if difference == 1, window [l..r] is valid
            if (nums[r] - nums[l] == 1)
                ans = max(ans, r - l + 1);
        }
        return ans;
    }
};