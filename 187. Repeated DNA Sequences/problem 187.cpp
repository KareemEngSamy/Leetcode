class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen , repeated;
        vector<string> result;

        for (int i = 0; i + 9 < s.size(); i++) {
            string sub = s.substr(i, 10);
            if (seen.count(sub))
                repeated.insert(sub);
            else
                seen.insert(sub);
        }

        for (const string& seq : repeated)
            result.push_back(seq);

        return result;
    }
};
