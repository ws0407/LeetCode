/**
 * 一共有 n 个城市，共有 m 条道路。 
 * s、t 和 v，表示 s 号城市运输货物到达 t 号城市，道路权值为 v
 * 城市 1 到城市 n 之间可能会出现没有路径的情况，同时保证道路网络中不存在任何负权回路。
 * 输出一个整数，表示运输成本。如果从城市 1 没有路径可达城市 n，输出 "unconnected"。
 * 时间复杂度 O(n * m)，空间复杂度 O(n)
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m, s, t, v;
    cin >> n >> m;
    vector<vector<int>> edges;

    while (m--) {
        cin >> s >> t >> v;
        edges.push_back({s, t, v});
    }

    int start = 1, end = n;
    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;

    while (n--) {
        bool flag = false;
        for (auto edge : edges) {
            if (minDist[edge[0]] != INT_MAX && minDist[edge[1]] > minDist[edge[0]] + edge[2]) {
                minDist[edge[1]] = minDist[edge[0]] + edge[2];
                flag = true;
            }
        }
        if (!flag) break;
    }
    cout << (minDist[end] == INT_MAX ? "unconnected" : to_string(minDist[end])) << endl;

    return 0;
}