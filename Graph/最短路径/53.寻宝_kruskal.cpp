/**两个整数V 和 E，V代表顶点数，E代表边数 。
 * 顶点编号是从1到V。
 * v1 和 v2 为边的起点和终点，val代表边的权值。
 * 2 <= V <= 10000;
 * 1 <= E <= 100000;
 * 0 <= val <= 10000;
 * 
 * Kruskal算法，时间复杂度O(ElogE)，空间复杂度O(E)
 * 
 * 在 稀疏图中，用Kruskal更优。 在稠密图中，用prim算法更优。
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define MAX_V 10001

using namespace std;

struct Edge {
    int l, r, val;
};

// 并查集相关方法
void init(int n, vector<int>& fa) {
    for (int i = 1; i <= n; i++) fa[i] = i;
}

int find(int x, vector<int>& fa) {
    return x == fa[x] ? x : fa[x] = find(fa[x], fa);
}

void join(int x, int y, vector<int>& fa) {
    x = find(x, fa);
    y = find(y, fa);
    if (x != y) fa[x] = y;
}

bool isSame(int x, int y, vector<int>& fa) {
    x = find(x, fa);
    y = find(y, fa);
    return x == y;
}

bool cmp(Edge a, Edge b) {
    return a.val < b.val;
}

int main()
{
    int V, E;
    cin >> V >> E;

    int l, r, val;
    vector<Edge> edges;
    while (E--) {
        cin >> l >> r >> val;
        edges.push_back({ l, r, val });
    }

    sort(edges.begin(), edges.end(), cmp);

    // 记录最短路径的边
    // vector<Edge> result;

    // 并查集关系数组
    vector<int> fa(V + 1, 0);
    init(V, fa);

    int ans = 0;
    for (auto& e : edges) {
        if (!isSame(e.l, e.r, fa)) {
            join(e.l, e.r, fa);
            ans += e.val;
            // result.push_back(e);
        }
    }

    cout << ans << endl;

    // 打印最短路径
    // for (auto& e : result) {
    //     cout << e.l << " - " << e.r << " : " << e.val << endl;
    // }

    return 0;
}