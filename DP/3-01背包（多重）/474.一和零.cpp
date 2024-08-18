#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

using namespace std;


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> nums;
        for (auto str : strs) {
            int zero = count(str.begin(), str.end(), '0');
            int one = str.size() - zero;
            nums.push_back({zero, one});
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto num : nums)
            for (int i = m; i >= num[0]; i--)
                for (int j = n; j >= num[1]; j--)
                    dp[i][j] = max(dp[i][j], dp[i - num[0]][j - num[1]] + 1);
        return dp[m][n];
    }
};