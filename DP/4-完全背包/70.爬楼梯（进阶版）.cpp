#include <bits/stdc++.h>
using namespace std;

int main() {
    // 共n，最多爬m
    int n, m;
    cin >> n >> m;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = max(0, i - m); j < i; j++) {
            dp[i] += dp[j];
        }
    }
    cout << dp[n] << endl;
    return 0;
}