#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int pre = 0;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] == 0) continue;
            int cur = nums[i] - nums[i - 1] > 0 ? 1 : -1;
            if (pre != cur) res++;
            pre = cur;
        }
        return res + 1;
    }
};