#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool isin_boundary(vector<vector<int>>& island, int x, int y) {
    if (island.size() == 0 || island[0].size() == 0) return false;
    return x >= 0 && x < island.size() && y >= 0 && y < island[0].size();
}

int dfs(vector<vector<int>>& island, int x, int y, int mark) {
    island[x][y] = mark;
    int res = 1;
    for (int i = 0; i < 4; i++) {
        int next_x = x + dir[i][0];
        int next_y = y + dir[i][1];
        if (isin_boundary(island, next_x, next_y) && island[next_x][next_y] == 1) {
            res += dfs(island, x+dir[i][0], y+dir[i][1], mark);
        }
    }
    return res;
}


int main(){
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
    map<int, int> area; // 岛屿面积
    // 标记岛屿
    int mark = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 1) {
                area[mark] = dfs(island, i, j, mark);
                mark++;
            }
        }
    }

    int res = area.size() == 0 ? 0 : area.begin()->second, tmp = 0;
    bool flag = false;
    list<int> total;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (island[i][j] == 0) {
                flag = true;
                for (int k = 0; k < 4; k++) {
                    int next_x = i + dir[k][0];
                    int next_y = j + dir[k][1];
                    if (isin_boundary(island, next_x, next_y) && island[next_x][next_y] > 1 &&
                        find(total.begin(), total.end(), island[next_x][next_y]) == total.end()) {
                        total.push_back(island[next_x][next_y]);
                    }
                }
                for (int mark : total) {
                    tmp += area[mark];
                }
                res = max(res, tmp);
                tmp = 0;
                total.clear();
            }
        }
    }

    cout << res + (flag ? 1 : 0) << endl;

    return 0;
}