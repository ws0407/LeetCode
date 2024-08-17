#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int index = 0, tmp = 0, is_sort = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (is_sort == 0) {sort(candidates.begin(), candidates.end()); is_sort = 1;}
        if (target == 0) {
            res.push_back(path);
            return res;
        }
        for (int i = index; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            tmp = index;
            index = i + 1;
            path.push_back(candidates[i]);
            combinationSum2(candidates, target - candidates[i]);
            index = tmp;
            path.pop_back();
        }
        return res;
    }
};


/*
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool> used) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && target - candidates[i] >= 0; i++) {
            if (i > startIndex && candidates[i] == candidates[i - 1] && !used[i - 1]) continue;
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target - candidates[i], i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return res;
    }
};

*/