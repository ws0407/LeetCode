/**第一行包含两个整数 N, M，表示矩阵的行数和列数。
 * 后续 N 行，每行包含 M 个数字，数字为 1 或者 0。
 * 输出一个整数，表示岛屿的数量。如果不存在岛屿，则输出 0。
 */

#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void dfs(vector<vector<bool>>& island, int x, int y) {
    island[x][y] = false;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x < island.size() && next_y < island[0].size() && island[next_x][next_y]) {
            dfs(island, x+dir[i][0], y+dir[i][1]);
        }
    }
}


int main(){
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
                res++;
                dfs(island, i, j);
            }
        }
    }

    cout << res;

    return 0;
}