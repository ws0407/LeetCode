#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int start) {
        if (k == 0) {
            res.push_back(path);
            return;
        }

        for (int i = start; i <= n-k+1; i++) {
            path.push_back(i);
            backtracking(n, k-1, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};

int main() {
    int n = 4, k = 2;
    Solution s;
    vector<vector<int>> res = s.combine(n, k);
    for (auto& r : res) {
        for (auto& e : r) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}