class Solution {
public:
    int partitionArray(const vector<int>& nums, int k) {
        bool n[100001] = {};
        int ans = 1, i = 1e5 + 1, j = 0;
        for (int x : nums) {
            n[x] = 1;
            i = min(i, x);
            j = max(j, x);
        }
        i += k + 1;
        while (i <= j) {
            if (n[i]) {
                ans++, i += k + 1;
            } else
                i++;
        }
        return ans;
    }
};
