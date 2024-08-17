#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int index = 0, tmp = 0, is_sort = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (is_sort == 0) {sort(candidates.begin(), candidates.end()); is_sort = 1;}
        if (target < 0) return res;
        if (target == 0) {
            res.push_back(path);
            return res;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (target - candidates[i] < 0) break;
            index = i;
            path.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i]);
            path.pop_back();
        }
        return res;
    }
};