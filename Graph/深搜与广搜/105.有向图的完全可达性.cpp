/**
 * N 个节点，节点编号分别为 1，2，...，N
 * 节点数量 N 和边的数量 K
 * 后续 K 行，每行两个正整数 s 和 t，表示从 s 节点有一条边单向连接到 t 节点。
 * 如果可以从 1 号节点的边可以到达任何节点，则输出 1，否则输出 -1。
 */

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, unordered_map<int, bool>& reach, int start) {
    reach[start] = true;
    for (int i = 0; i < graph[start].size(); i++) {
        if (!reach[graph[start][i]]) {
            dfs(graph, reach, graph[start][i]);
        }
    }
}

int main() {
    int n, k, s, t;
    cin >> n >> k;
    vector<vector<int>> graph(n + 1);
    while (k--) {
        cin >> s >> t;
        graph[s].push_back(t);
    }
    unordered_map<int, bool> reach;
    for(int i = 1; i <= n; i++) reach[i] = false;

    dfs(graph, reach, 1);
    
    for (int i = 1; i <= n; i++) {
        if (!reach[i]) {
            cout << -1;
            return 0;
        }
    }
    cout << 1;
    return 0;
}