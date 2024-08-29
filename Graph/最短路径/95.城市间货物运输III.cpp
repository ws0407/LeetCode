/**bellman_ford之单源有限最短路
 * 最多经过k个城市的条件下，从城市src到城市dst的最低运输成本。
 * 最后一行包含三个正整数，src和dst为城市编号，k是从src到dst经过的城市数量限制。
 * 
 * 输出一个整数，表示从城市 src 到城市 dst 的最低运输成本
 * 如果无法在给定经过城市数量限制下找到从 src 到 dst 的路径，
 * 则输出 "unreachable"，表示不存在符合条件的运输方案。
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
    cin >> s >> t >> v;
    int start = s, end = t, k = v + 1;

    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;
    vector<int> preDist;

    while (k--) {
        preDist = minDist;
        for (auto edge : edges) {
            if (preDist[edge[0]] != INT_MAX && minDist[edge[1]] > preDist[edge[0]] + edge[2]) {
                minDist[edge[1]] = preDist[edge[0]] + edge[2];
            }
        }
    }
    cout << (minDist[end] == INT_MAX ? "unreachable" : to_string(minDist[end])) << endl;

    return 0;
}