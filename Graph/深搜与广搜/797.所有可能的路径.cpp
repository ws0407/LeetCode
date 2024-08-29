#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int>path{0};
    void dfs(vector<vector<int>>& graph, int cur, int target) {
        if (cur == target) {
            res.push_back(path);
            return;    
        }
        for (int i: graph[cur]) {
            path.push_back(i);
            dfs(graph, i, target);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size() - 1);
        return res;
    }
};