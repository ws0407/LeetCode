/**bellman_ford之判断负权回路
 * 如果没有发现负权回路，则输出一个整数，表示从城市 1 到城市 n 的最低运输成本（包括政府补贴）。
 * 如果发现了负权回路的存在，则输出 "circle"。
 * 如果从城市 1 无法到达城市 n，则输出 "unconnected"。
 */

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <list>

using namespace std;

struct Edge {
    int to;
    int val;
};


int main() {
    int n, m, s, t, v;
    cin >> n >> m;

    vector<list<Edge>> graph(n + 1);
    while (m--) {
        cin >> s >> t >> v;
        graph[s].push_back({t, v});
    }

    int start = 1, end = n;
    vector<int> minDist(n + 1, INT_MAX);    // 记录最短路径的数组
    minDist[start] = 0;
    queue<int> que;                         // 松弛队列
    vector<bool> isInQueue(n + 1, false);   // 记录节点是否在队列中
    vector<int> cnt(n + 1, 0);              // 记录每个节点加入队列的次数
    que.push(start);
    cnt[start]++;
    
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        isInQueue[cur] = false;
        for (auto edge : graph[cur]) {
            if (minDist[edge.to] > minDist[cur] + edge.val) {
                minDist[edge.to] = minDist[cur] + edge.val;
                if (!isInQueue[edge.to]) {
                    que.push(edge.to);
                    isInQueue[edge.to] = true;
                    cnt[edge.to]++;
                    if (cnt[edge.to] >= n) {
                        cout << "circle" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << (minDist[end] == INT_MAX ? "unconnected" : to_string(minDist[end])) << endl;

    return 0;
}