#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(robRange(nums, 0, nums.size() - 1), robRange(nums, 1, nums.size()));
    }
    int robRange(vector<int>& nums, int left, int right) {
        int size = right - left;
        vector<int> dp(size, 0);
        dp[0] = nums[left];
        if (size == 1) return dp[0];
        dp[1] = max(nums[left], nums[left + 1]);
        if (size == 2) return dp[1];
        for (int i = left + 2; i < right; i++)
            dp[i - left] = max(dp[i - left - 2] + nums[i], dp[i - left - 1]);
        return dp[size - 1];
    }
};

int main() {
    vector<int> nums = {1,2,1,1};
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}