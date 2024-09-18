#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
        int resj = 0, res = 1;
        for (int i = 1; i < n; i++) {   // 间隔为1：0,1; 1,2; 2,3，...
            for (int j = 0; j < n - i; j++) {
                dp[j][j+i] = (s[j] == s[j+i] && (i == 1 || dp[j+1][j+i-1]));
                if (dp[j][j+i] && i + 1 > res) {
                    res = i + 1;
                    resj = j;
                }
            }
        }
        return s.substr(resj, res);
    }
};


int main() {
    string s = "babad";
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
    return 0;
}