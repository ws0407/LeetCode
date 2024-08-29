/**两个整数V 和 E，V代表顶点数，E代表边数 。
 * 顶点编号是从1到V。
 * v1 和 v2 为边的起点和终点，val代表边的权值。
 * 2 <= V <= 10000;
 * 1 <= E <= 100000;
 * 0 <= val <= 10000;
 * 
 * Prim算法，时间复杂度O(V^2)，空间复杂度O(V)
 */

#include <iostream>
#include <vector>
#include <climits>
#include <numeric>

#define MAX_V 10001

using namespace std;

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V + 1, vector<int>(V + 1, MAX_V));
    while (E--)
    {
        int v1, v2, val;
        cin >> v1 >> v2 >> val;
        G[v1][v2] = val;
        G[v2][v1] = val;
    }

    // 初始化最短路径数组，节点到最小生成树的最小距离
    vector<int> minDist(V + 1, MAX_V);

    // 判断节点是否在树中
    vector<bool> inTree(V + 1, false);

    // 记录最短路径
    // vector<int> parent(v + 1, -1);

    // 循环n-1次，找到最短路径，从1开始，到n结束
    for (int i = 1; i <= V - 1; i++) {
        // 1.选择距离生成树最近的节点
        int v = -1, minVal = INT_MAX;
        for (int j = 1; j <= V; j++) {
            if (!inTree[j] && minDist[j] < minVal) {
                v = j;
                minVal = minDist[j];
            }
        }
        // 2.将该节点标记为已经在生成树中
        inTree[v] = true;
        // 3.更新最短路径
        for (int j = 1; j <= V; j++) {
            if (!inTree[j] && G[v][j] < minDist[j]) {
                minDist[j] = G[v][j];
                // parent[j] = v;   // 更新/记录最短路径
            }
        }
    }
    // 输出最短路径
    cout << accumulate(minDist.begin() + 2, minDist.end(), 0) << endl;

    // 打印最短路径
    // for (int i = 1; i <= V; i++) {
    //     cout << i << " " << parent[i] << endl;
    // }

    return 0;
}