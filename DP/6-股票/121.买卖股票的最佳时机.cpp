#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX, profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < low) low = prices[i];
            else if (prices[i] - low > profit) profit = prices[i] - low;
        }
        return profit;
    }

    int maxProfit_dp(vector<int>& prices) {
        vector<int> dp{INT_MIN, 0}; // 持有，不持有
        for (int i = 0; i < prices.size(); i++) {
            dp[0] = max(dp[0], -prices[i]);
            dp[1] = max(dp[1], dp[0] + prices[i]);
        }
        return dp[1];
    }
};