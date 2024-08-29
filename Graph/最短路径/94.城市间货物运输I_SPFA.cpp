/**
 * 一共有 n 个城市，共有 m 条道路。 
 * s、t 和 v，表示 s 号城市运输货物到达 t 号城市，道路权值为 v
 * 城市 1 到城市 n 之间可能会出现没有路径的情况，同时保证道路网络中不存在任何负权回路。
 * 输出一个整数，表示运输成本。如果从城市 1 没有路径可达城市 n，输出 "unconnected"。
 * Bellman-Ford算法的队列优化版本，Spfa算法，
 * SPFA 在最坏的情况下是 O(N * E)，但一般情况下时间复杂度为 O(K * N)
 * 空间复杂度 O(n)
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

    que.push(start);
    
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
                }
            }
        }
    }
    
    cout << (minDist[end] == INT_MAX ? "unconnected" : to_string(minDist[end])) << endl;

    return 0;
}