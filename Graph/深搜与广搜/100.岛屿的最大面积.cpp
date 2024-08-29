/**第一行包含两个整数 N, M，表示矩阵的行数和列数。
 * 后续 N 行，每行包含 M 个数字，数字为 1 或者 0，表示岛屿的单元格。
 */
#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int dfs(vector<vector<bool>>& island, int x, int y) {
    island[x][y] = false;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x >= 0 && next_x < island.size() && 
            next_y >= 0 && next_y < island[0].size() && island[next_x][next_y]) {
            res += dfs(island, x+dir[i][0], y+dir[i][1]);
        }
    }
    return res;
}
int bfs(vector<vector<bool>>& island, int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    island[x][y] = false;
    int res = 1;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_x = cur.first + dir[i][0];
            int next_y = cur.second + dir[i][1];
            if (next_x >= 0 && next_x < island.size() && 
                next_y >= 0 && next_y < island[0].size() && island[next_x][next_y]) {
                q.push({next_x, next_y});
                island[next_x][next_y] = false;
                res++;
            }
        }
    }
    return res;
}

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
            if (island[i][j]) {
                res = max(bfs(island, i, j), res);
                res = max(dfs(island, i, j), res);
            }
        }
    }
    cout << res;

    return 0;
}