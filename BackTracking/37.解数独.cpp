#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isValid(vector<vector<char>>& board, int line, int col, char k) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == k) return false;
            if (board[line][i] == k) return false;
            if (board[3 * (line / 3) + i / 3][3 * (col / 3) + i % 3] == k) return false;
        }
        return true;
    }
    bool dfs(vector<vector<char>>& board, int line) {
        if (line == 9) return true;
        for (int i = line; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') continue;
                for (char k = '1'; k <= '9'; k++) {
                    if (!isValid(board, i, j, k)) continue;
                    board[i][j] = k;
                    if (dfs(board, j < 8 ? i : i + 1)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0);
    }
};