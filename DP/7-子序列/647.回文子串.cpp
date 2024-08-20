#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for (int i = 0; i < s.size(); i++) dp[i][i] = true;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j + i < s.size(); j++) {
                if (s[j] == s[j+i] && (i <= 1 || dp[j+1][j+i-1])) {
                    dp[j][j+i] = true;
                    res++;
                }
            }
        }
        return res;
    }
};