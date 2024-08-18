#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (string word : wordDict) {
                if (i >= word.size() && dp[i - word.size()] && s.substr(i - word.size(), word.size()) == word) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};