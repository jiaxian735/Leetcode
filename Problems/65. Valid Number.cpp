class Solution {
public:
    bool isNumber(string s) {
        bool e{}, dot{}, n{};
        if (isalpha(s[0]))
            return 0;
        if (s.size() == 1) {
            if (s[0] == '+' || s[0] == '-' || s[0] == '.')
                return 0;
            return 1;
        }
        if (s.back() == 'e' || s.back() == 'E' || s.back() == '+' ||
            s.back() == '-')
            return 0;
        if (s.back() == '.')
            if (s[s.size() - 2] == '+' || s[s.size() - 2] == '-')
                return 0;
        if (s[0] == '.')
            dot = 1;
        if (isdigit(s[0]))
            n = 1;
        for (int i = 1; i < s.size(); i++) {
            if (isdigit(s[i]))
                n = 1;
            if (s[i] == '+' || s[i] == '-') {
                if (s[i - 1] == 'e' || s[i - 1] == 'E')
                    continue;
                return 0;
            }
            if (s[i] == '.') {
                if (dot)
                    return 0;
                dot = 1;
                if (e)
                    return 0;
                if (isdigit(s[i - 1]) || s[i - 1] == '+' || s[i - 1] == '-')
                    continue;
                return 0;
            }
            if (s[i] == 'e' || s[i] == 'E') {
                if (!n)
                    return 0;
                if (!e) {
                    e = 1;
                    continue;
                }
            }
            if (isalpha(s[i]))
                return 0;
        }
        return 1;
    }
};
