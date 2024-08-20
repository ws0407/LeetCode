#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp = max(dp + nums[i], nums[i]);
            res = max(res, dp);
        }
        return res;
    }
};