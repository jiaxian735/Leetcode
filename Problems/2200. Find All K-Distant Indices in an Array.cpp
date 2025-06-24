class Solution {
public:
    vector<int> findKDistantIndices(const vector<int>& nums, int key, int k) {
        vector<int> ans;
        int l = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != key)
                continue;
            l = max(l, i - k);
            int r = min(i + k + 1, n);
            while (l < r) {
                ans.push_back(l);
                l++;
            }
        }
        return ans;
    }
};
