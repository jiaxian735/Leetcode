class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, a = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= a) {
                a = nums[i];
                continue;
            }
            ans = max(ans, nums[i] - a);
        }
        return ans;
    }
};
