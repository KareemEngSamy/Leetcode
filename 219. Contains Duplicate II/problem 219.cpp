class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int l = 0, r = 0;

        while (r < nums.size()) {
            // If duplicate found in the current window
            if (window.find(nums[r]) != window.end())
                return true;

            // Add current element to the window
            window.insert(nums[r]);

            // Maintain window size of at most k
            if (r - l >= k) {
                window.erase(nums[l]);
                l++;
            }

            r++;
        }

        return false;
    }
};