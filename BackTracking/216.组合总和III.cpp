#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtracking(int targetSum, int k, int sum, int start) {
        if (k == 0) {
            if (sum == targetSum) result.push_back(path);
            return;
        }
        for (int i = start; i <= 9-k+1; i++) {
            if (sum + i > targetSum) break;
            path.push_back(i);
            backtracking(targetSum, k-1, sum + i, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(n, k, 0, 1);
        return result;
    }
};