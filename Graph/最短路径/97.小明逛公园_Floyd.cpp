/**Floyd算法
 * 求解多源最短路（多对多）的算法，即确定每个节点（起点）到其他节点（终点）的最短路
 * N 个景点（编号为 1 到 N），以及 M 条双向道路
 * Q 个观景计划，每个计划都有一个起点 start 和一个终点 end
 * 计算出每个观景计划的最短路径长度。
 */

#include <iostream>
#include <vector>
#include <climits>

#define N_MAX 1002

using namespace std;

int main() {
    int n, m, q, start, end, dis;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, N_MAX));
    while (m--) {
        cin >> start >> end >> dis;
        grid[start][end] = dis;
        grid[end][start] = dis;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
            }
        }
    }
    cin >> q;
    while (q--) {
        cin >> start >> end;
        cout << (grid[start][end] == N_MAX ? -1 : grid[start][end]) << endl;
    }
    return 0;
}