// 不一定所有的图问题都需要用DFS或者BFS
#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> island(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x) island[i][j] = true;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!island[i][j]) continue;
            for (int k = 0; k < 4; k++) {
                int next_x = i + dir[k][0];
                int next_y = j + dir[k][1];
                if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= m
                    || !island[next_x][next_y]) {
                    res++;
                }
            }
        }
    }
    
    cout << res;

    return 0;
}