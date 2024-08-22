#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void bfs(vector<vector<int>>& island, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    island[x][y] = 2;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = cur.first + dir[i][0];
            int next_y = cur.second + dir[i][1];
            if (next_x >= 0 && next_x < island.size() && 
                next_y >= 0 && next_y < island[0].size() && 
                island[next_x][next_y] == 1) {
                q.push({next_x, next_y});
                island[next_x][next_y] = 2;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> island(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            if (x) island[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        if (island[i][0] == 1) bfs(island, i, 0);
        if (island[i][m - 1] == 1) bfs(island, i, m - 1);
    }
    for (int i = 0; i < m; i++) {
        if (island[0][i] == 1) bfs(island, 0, i);
        if (island[n - 1][i] == 1) bfs(island, n - 1, i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            cout << (island[i][j] == 2 ? 1 : 0) << " ";
        }
        cout << (island[i][m-1] == 2 ? 1 : 0) << endl;
    }
    return 0;
}