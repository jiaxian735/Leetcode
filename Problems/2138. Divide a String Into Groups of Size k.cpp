class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        ans.reserve(s.size() / k);
        for (int i = 0; i < s.size(); i += k) {
            ans.push_back(s.substr(i, k));
        }
        while (ans.back().size() < k)
            ans.back() += fill;
        return ans;
    }
};
