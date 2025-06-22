class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[26] = {}, pre{}, ans = 1e5;
        for (char c : word)
            freq[c - 'a']++;
        sort(freq, freq + 26);
        for (int i = 0; i < 26; i++) {
            if (!freq[i])
                continue;
            int temp = pre;
            for (int j = i; j < 26; j++) {
                if (freq[j] - freq[i] > k) {
                    temp += freq[j] - freq[i] - k;
                }
            }
            ans = min(ans, temp);
            pre += freq[i];
        }
        return ans;
    }
};
