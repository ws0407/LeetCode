#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1]) return 0;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i]) break;
            v[i] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    v[j] = 0;
                } else {
                    if (j > 0)
                        v[j] += v[j - 1];
                }
            }
        }
        return v[n - 1];
    }
};