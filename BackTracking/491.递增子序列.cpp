#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:

    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& nums, int start) {
        if (path.size() > 1) res.push_back(path);
        unordered_set<int> used;
        for (int i = start; i < nums.size(); i++) {            
            if (path.size() > 0 && nums[i] < path[path.size() - 1] ||
            used.find(nums[i]) == used.end()) continue;
            used.insert(nums[i]);
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};


int main()
{
    vector<int> nums = {4, 6, 7, 7};
    Solution s;
    vector<vector<int>> res = s.findSubsequences(nums);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}