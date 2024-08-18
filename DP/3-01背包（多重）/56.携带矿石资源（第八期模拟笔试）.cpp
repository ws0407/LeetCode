// 多重背包问题
/**
 * 最大容量为 C。
 * 有 N 种不同类型的矿石，
 * 每种矿石有一个重量 w[i]，
 * 一个价值 v[i]，
 * 以及最多 k[i] 个可用。
 */
#include <bits/stdc++.h>
using namespace std;

int main() {

    int C, N;
    cin >> C >> N;

    vector<int> w(N, 0), v(N, 0), k(N, 0);
    for (int i = 0; i < N; i++) cin >> w[i];
    for (int i = 0; i < N; i++) cin >> v[i];
    for (int i = 0; i < N; i++) cin >> k[i];

    vector<int> dp(C + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int j = C; j >= w[i]; j--) {
            for (int n = 1; n <= k[i] && n * w[i] <= j; n++) {
                dp[j] = max(dp[j], dp[j - n * w[i]] + n * v[i]);
            }
        }
    }
    cout << dp[C] << endl;
    return 0;
}   