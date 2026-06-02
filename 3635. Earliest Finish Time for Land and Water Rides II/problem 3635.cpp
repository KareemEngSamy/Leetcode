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