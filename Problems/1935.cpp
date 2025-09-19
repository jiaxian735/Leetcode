class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream s(text);
        unordered_set<char> letter;
        for (char x : brokenLetters) {
            letter.insert(x);
        }
        string word;
        int ans{};
        while (s >> word) {
            bool r{};
            for (char c : word) {
                if (letter.find(c) != letter.end()) {
                    r = 1;
                    break;
                }
            }
            if (r)
                continue;
            ans++;
        }
        return ans;
    }
};