/**小顶堆优化
 * 邻接表存储
 * 时间复杂度 O(E * logE)，空间复杂度 O(V + E)，其中 E 为边数，V 为顶点数
 */
#include <iostream>
#include <vector>
#include <climits>
#include <list>
#include <queue>

using namespace std;

class myCmp {
public:
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

struct Edge {
    int to;     // 邻接点
    int val; // 权重/距离

    Edge(int to, int val) : to(to), val(val) {}
};

int main() {
    int n, m, l, r, v;
    cin >> n >> m;
    vector<list<Edge>> graph(n + 1);
    while (m--) {
        cin >> l >> r >> v;
        graph[l].push_back(Edge(r, v));
    }

    int start = 1, end = n;
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;
    vector<bool> visited(n + 1, false);

    // 小顶堆优化
    priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq;

    pq.push({start, 0});
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        for (auto edge : graph[cur.first]) {
            if (!visited[edge.to] && dist[edge.to] > dist[cur.first] + edge.val) {
                dist[edge.to] = dist[cur.first] + edge.val;
                pq.push({edge.to, dist[edge.to]});
            }
        }
        visited[cur.first] = true;
    }

    cout << (dist[end] == INT_MAX ? -1 : dist[end]) << endl;

    return 0;
}