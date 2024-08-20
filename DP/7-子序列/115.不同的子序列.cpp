#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        //  s 的 子序列 中 t 出现的个数
        vector<int> dp(t.size() + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < s.size(); i++) {
            for (int j = t.size(); j > 0; j--) {
                if (s[i] == t[j-1]) {
                    long long tmp = dp[j] + dp[j - 1];
                    dp[j] = tmp % 1000000007;
                }
            }
        }
        return dp[t.size()];
    }
};