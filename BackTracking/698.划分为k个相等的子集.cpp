/**
 * 给定一个整数数组 nums 和一个正整数 k，
 * 找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool dfs(vector<int>& obtains, vector<int>& nums, int idx, int n, int avg) {
        if (idx == n) return true;
        // 遍历每个桶，看能否装得下
        for (int i = 0; i < obtains.size(); i++) {
            if (obtains[i] + nums[idx] > avg) continue;
            if (i > 0 && obtains[i] == obtains[i - 1]) continue;
            obtains[i] += nums[idx];
            if (dfs(obtains, nums, idx + 1, n, avg)) return true;
            obtains[i] -= nums[idx];
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int avg = accumulate(nums.begin(), nums.end(), 0);
        if (avg % k) return false;
        avg /= k;
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> obtains(k, 0);
        return dfs(obtains, nums, 0, n, avg);
    }
};
