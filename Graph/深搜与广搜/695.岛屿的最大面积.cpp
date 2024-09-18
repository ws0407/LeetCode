#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dir[4][2] = {1,0, 0,1, -1,0, 0,-1};
    int maxy, maxx;
    int dfs(vector<vector<int>>& grid, int x, int y) {
        grid[x][y] = 0;
        int res = 1;
        for (int i = 0; i < 4; i++) {
            int xnext = x + dir[i][0];
            int ynext = y + dir[i][1];
            if (xnext >= 0 && ynext >= 0 && xnext < maxx && ynext < maxy && grid[xnext][ynext]) {
                res += dfs(grid, xnext, ynext);
            }
        }
        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxy = grid[0].size();
        maxx = grid.size();
        int res = 0;
        for (int x = 0; x < maxx; x++) {
            for (int y = 0; y < maxy; y++) {
                if (grid[x][y]) {
                    res = max(res, dfs(grid, x, y));
                }
            }
        }
        return res;
    }
};