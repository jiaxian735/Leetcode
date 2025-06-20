class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 1, t = nums[0];
        for (int x : nums) {
            if (x - t > k)
                ans++, t = x;
        }
        return ans;
    }
};
