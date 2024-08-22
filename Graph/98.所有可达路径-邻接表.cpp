#include<bits/stdc++.h>
using namespace std;

bool res = false;

void dfs(vector<list<int>>& graph, int cur, int target, vector<int>& path) {
    if (cur == target) {
        for (int i = 0; i < path.size() - 1; i++) cout << path[i] << " ";
        cout << path[path.size() - 1] << endl;
        res = true;
    }

    for (int i : graph[cur]) {
        path.push_back(i);
        dfs(graph, i, target, path);
        path.pop_back();
    }
}

int main() {
    // N 个节点，M 条边
    int n, m;
    cin >> n >> m;
    // 邻接矩阵
    vector<list<int>> graph(n+1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    // 路径
    vector<int> path{1};
    dfs(graph, 1, n, path);
    if (!res) cout << "-1";
    return 0;
}