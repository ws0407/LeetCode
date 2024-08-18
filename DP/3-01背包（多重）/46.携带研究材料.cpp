#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // M 代表种类，N 代表容量
    int m, n;
    cin >> m >> n;
    vector<int> w(m, 0), v(m, 0);

    for (int i = 0; i < m; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++)
        cin >> v[i];
    vector<int> dp(n + 1, 0);

    for (int i = 0; i < m; i++) 
        for (int j = n; j >= w[i]; j--) 
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout << dp[n] << endl;    
    return 0;
}