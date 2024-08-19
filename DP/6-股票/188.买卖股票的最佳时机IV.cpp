#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (!prices.size()) return 0;
        vector<int> dp(2 * k + 1, 0);
        for (int i = 0; i < k; i++) {
            dp[2 * i + 1] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= 2 * k; j++) {
                dp[j] = max(dp[j], dp[j - 1] + (j % 2 ? -prices[i] : prices[i]));
            }
        }
        return dp[2 * k];
    }
};