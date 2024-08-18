/**
 * 第一行包含两个整数，N，V，分别表示研究材料的种类和行李空间 
 * 接下来包含 N 行，每行两个整数 wi 和 vi，代表第 i 种研究材料的重量和价值
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, V;
    cin >> N >> V;
    vector<int> w(N, 0), v(N, 0);
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    vector<int> dp(V + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = w[i]; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[V] << endl;
    return 0;
}