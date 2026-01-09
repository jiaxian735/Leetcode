class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int ans{}, x{}, y{};
        for (char c : s) {
            x++;
            ans = max(ans, x - (y = max(y, m[c])));
            m[c] = x;
        }
        return ans;
    }
};
