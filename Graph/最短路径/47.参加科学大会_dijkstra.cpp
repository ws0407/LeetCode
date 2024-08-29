/**第一行包含两个正整数，
 *      第一个正整数 N 表示一共有 N 个公共汽车站，
 *      第二个正整数 M 表示有 M 条公路。
 * 接下来为 M 行，每行包括三个整数，S、E 和 V
 *      代表了从 S 车站可以单向直达 E 车站，并且需要花费 V 单位的时间。
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n, m, l, r, v;
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INT_MAX));
    while (m--) {
        cin >> l >> r >> v;
        graph[l][r] = v;
    }
    
    int start = 1, end = n;

    // 记录最短路径的数组
    vector<int> dist(n+1, INT_MAX);
    dist[start] = 0;
    // 记录节点是否被访问
    vector<bool> visited(n+1, false);

    // // 记录路径
    // vector<int> path(n+1, -1);

    for (int i = 0; i < n; i++) {
        // 找到当前最短路径的节点
        int cur = -1;
        int minDist = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                cur = j;
            }
        }
        if(cur == -1) break;
        visited[cur] = true;    // 标记节点已经被访问

        // 更新最短路径
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && graph[cur][j] != INT_MAX) {
                dist[j] = min(dist[j], dist[cur] + graph[cur][j]);
                // path[j] = cur;   // 记录路径的边
            }
        }
    }
    cout << (dist[end] == INT_MAX ? -1 : dist[end]) << endl;

    // // 打印路径
    // for (int i = 1; i <= n; i++) {
    //     cout << path[i] << " -> " << i << endl;
    // }

    return 0;
}