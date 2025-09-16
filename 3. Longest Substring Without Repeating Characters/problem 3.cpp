#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, res = 0;
        unordered_set<char> myset; 

        for (int r = 0; r < s.length(); r++) {
            while (myset.find(s[r]) != myset.end()) {
                myset.erase(s[l]);
                l++;
            }

            myset.insert(s[r]);
            res = max(res, r - l + 1);
        }

        return res;
    }
};
