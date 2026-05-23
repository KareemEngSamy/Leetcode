class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }
        
        int pairs=0;
        int leftover=0;

        for(auto it:freq){
            pairs+=it.second/2;
            leftover+=it.second%2;
        }

        return {pairs,leftover};
    }
};