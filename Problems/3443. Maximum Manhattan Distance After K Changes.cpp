class Solution {
public:
    int maxDistance(string s, int k) {
        int x{}, y{}, ans{}, t = k;
        for (char c : s) {
            if (c == 'N') {
                if (t)
                    y++, t--;
                else
                    y--;
            } else if (c == 'N' || c == 'S')
                y++;
            if (c == 'W') {
                if (t)
                    x++, t--;
                else
                    x--;
            } else if (c == 'W' || c == 'E')
                x++;
            ans = max(ans, abs(x) + abs(y));
        }
        x = 0, y = 0, t = k;
        for (char c : s) {
            if (c == 'N') {
                if (t)
                    y++, t--;
                else
                    y--;
            } else if (c == 'N' || c == 'S')
                y++;
            if (c == 'E') {
                if (t)
                    x++, t--;
                else
                    x--;
            } else if (c == 'W' || c == 'E')
                x++;
            ans = max(ans, abs(x) + abs(y));
        }
        x = 0, y = 0, t = k;
        for (char c : s) {
            if (c == 'S') {
                if (t)
                    y++, t--;
                else
                    y--;
            } else if (c == 'N' || c == 'S')
                y++;
            if (c == 'W') {
                if (t)
                    x++, t--;
                else
                    x--;
            } else if (c == 'W' || c == 'E')
                x++;
            ans = max(ans, abs(x) + abs(y));
        }
        x = 0, y = 0, t = k;
        for (char c : s) {
            if (c == 'S') {
                if (t)
                    y++, t--;
                else
                    y--;
            } else if (c == 'N' || c == 'S')
                y++;
            if (c == 'E') {
                if (t)
                    x++, t--;
                else
                    x--;
            } else if (c == 'W' || c == 'E')
                x++;
            ans = max(ans, abs(x) + abs(y));
        }
        return ans;
    }
};
