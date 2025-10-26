class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> count;
        vector<string> result;

        for (int i = 0; i + 9 < s.size(); i++) {
            string sub = s.substr(i, 10);
            count[sub]++;
        }

        for (auto& [sub, freq] : count) {
            if (freq > 1)
                result.push_back(sub);
        }

        return result;
    }
};
