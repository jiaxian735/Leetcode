class Solution {
public:
    vector<vector<int>> divideArray(const vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> v(mx + 1, 0);
        for (int x : nums)
            v[x]++;
        vector<vector<int>> ans(nums.size() / 3, vector<int>(3));
        for (int i = 1, j = 0; i <= mx; i++) {
            if (!v[i])
                continue;
            ans[j / 3][j % 3] = i;
            if (j % 3 == 2 && ans[j / 3][2] - ans[j / 3][0] > k)
                return {};
            v[i]--;
            i--;
            j++;
        }
        return ans;
    }
};
