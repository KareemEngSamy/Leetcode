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