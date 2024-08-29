#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

void change_flag(vector<vector<int>>& flag, int x, int y, int from) {
    if (flag[x][y] == 0) flag[x][y] = from;
    else if (flag[x][y] != from) flag[x][y] = 3;
}

void dfs(vector<vector<int>>& grid, vector<vector<int>>& flag, int x, int y, int from) {
    change_flag(flag, x, y, from);
    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (next_x >= 0 && next_x < grid.size() && 
            next_y >= 0 && next_y < grid[0].size() &&
            flag[next_x][next_y] != from && flag[next_x][next_y] != 3 && 
            grid[next_x][next_y] >= grid[x][y]) {
            dfs(grid, flag, x+dir[i][0], y+dir[i][1], from);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> flag(n, vector<int>(m, 0));    // 0: 未达到，1: 左上达到，2: 右下达到, 3: 均可达到
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        dfs(grid, flag, i, 0, 1);
        dfs(grid, flag, i, m - 1, 2);
    }
    for (int i = 0; i < m; i++) {
        dfs(grid, flag, 0, i, 1);
        dfs(grid, flag, n - 1, i, 2);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (flag[i][j] == 3) cout << i << " " << j << endl;
        }
    }

    return 0;
}