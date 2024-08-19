#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = -prices[0], sell = 0, free = 0;
        for (int i = 1; i < prices.size(); i++) {
            int t_h = hold, t_s = sell, t_f = free;
            hold = max(t_h, t_f - prices[i]);
            sell = t_h + prices[i];
            free = max(t_s, t_f);
        }
        return max(sell, free);
    }
};