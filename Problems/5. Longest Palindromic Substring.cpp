class Solution {
public:
    string longestPalindrome(string s) {
        int x = 0, y = 1;
        for (int i = 1; i < s.size(); i++) {
            for (int j = 0; i - j >= 0 && i + j < s.size(); j++) {
                if (s[i - j] == s[i + j]) {
                    if (2 * j + 1 > y)
                        x = i - j, y = 2 * j + 1;
                } else
                    break;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; i - j >= 0 && i + 1 + j < s.size(); j++) {
                if (s[i - j] == s[i + 1 + j]) {
                    if (2 * j + 2 > y)
                        x = i - j, y = 2 * j + 2;
                } else
                    break;
            }
        }
        return s.substr(x, y);
    }
};
