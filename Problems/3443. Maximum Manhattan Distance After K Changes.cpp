class Solution {
public:
    int maxDistance(string s, int k) {
        int x{}, y{}, ans{};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N')
                y++;
            else if (s[i] == 'S')
                y--;
            else if (s[i] == 'E')
                x++;
            else
                x--;
            int p = abs(x) + abs(y);
            ans = max(ans, p + min(i + 1 - p, 2 * k));
        }
        return ans;
    }
};
