class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans=0;
        int l=0 , r=people.size()-1;
        while(l<=r){
            if(people[r]+people[l]>limit){
                r--;
                ans++;
            }
            else{
                r--;
                l++;
                ans++;
            }
        }
        return ans;
    }
};
