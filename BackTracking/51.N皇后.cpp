#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<string>> res;

    bool isValid(vector<string>& path, int line, int col, int n) {
        for (int j = 0; j < line; j++) {
            if (path[j][col] == 'Q') return false;
            if (j + col >= line && path[j][j+col-line] == 'Q') return false;
            if (line+col-j < n && path[j][line+col-j] == 'Q') return false;
        }
        return true;
    }
    
    void dfs(vector<string>& path, int n, int line) {
        if (line == n) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!isValid(path, line, i, n)) continue;
            path[line][i] = 'Q';
            dfs(path, n, line+1);
            path[line][i] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path(n, string(n, '.'));
        dfs(path, n, 0);
        return res;
    }
};


int main() {
    int n = 4;
    vector<vector<string>> vec = Solution().solveNQueens(n);
    for (auto& it: vec) {
        for (auto& s: it) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}