#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int dp = 1, dp_max = 1;
        for (int i = 1; i < nums.size(); i++) {
            dp = nums[i] > nums[i-1] ? dp + 1 : 1;
            dp_max = max(dp, dp_max);
        }
        return dp_max;
    }
};