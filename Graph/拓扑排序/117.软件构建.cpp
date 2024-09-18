/**
 * 拓扑排序
 * N 个文件，文件编号从 0 到 N - 1
 * 第一行输入两个正整数 M, N。表示 N 个文件之间拥有 M 条依赖关系。
 * 后续 M 行，每行两个正整数 S 和 T，表示 T 文件依赖于 S 文件。
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;


int main() {
    int N, M, s, t;
    cin >> N >> M;
    // 统计入度
    vector<int> inDegree(N, 0);
    // 依赖关系
    unordered_map<int, vector<int>> dependence(N);
    // 结果
    vector<int> res;
    // 队列
    queue<int> que;
    while (M--) {
        cin >> s >> t;
        inDegree[t]++;
        dependence[s].push_back(t);
    }
    for (int i = 0; i < N; i++) if (!inDegree[i]) que.push(i);
    while (!que.empty()) {
        int cur = que.front();
        que.pop();
        res.push_back(cur);
        for (int node: dependence[cur]) {
            inDegree[node]--;
            if (!inDegree[node]) que.push(node);
        }
    }

    // 输出结果
    if (res.size() == N) {
        for (int i = 0; i < N - 1; i++) cout << res[i] << " ";
        cout << res[N - 1];
    } else cout << -1 << endl;


    return 0;
}