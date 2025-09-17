class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() < 3) return 0;

        int res = 0;
        int n = nums.size();
        int l = 0;  // left pointer of current arithmetic window

        for (int r = 2; r < n; r++) {

            // check if nums[l→r] is still arithmetic
            if (nums[r] - nums[r-1] != nums[r-1] - nums[r-2]) {
                // streak breaks → reset left pointer
                l = r - 1;
            }

            int len = r - l + 1;
            if (len >= 3) {
                res += (len - 2); 
            }
        }

        return res;
    }
};
