#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp{INT_MIN, 0}; // 持有，不持有
        for (int i = 0; i < prices.size(); i++) {
            int tmp = dp[0];
            dp[0] = max(dp[0], dp[1]-prices[i]);
            dp[1] = max(dp[1], tmp + prices[i]);
        }
        return dp[1];
    }
};