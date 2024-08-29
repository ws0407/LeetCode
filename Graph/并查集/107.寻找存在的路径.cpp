/**判断是否有一条从节点 source 出发到节点 destination 的路径存在。
 * https://kamacoder.com/problempage.php?pid=1179
 * N 代表节点的个数，M 代表边的个数。 
 * 1 <= M, N <= 100。
 */

#include <bits/stdc++.h>
using namespace std;

void init(int n, vector<int>& father) {
    for (int i = 1; i <= n; i++) father[i] = i;
}

int find(int x, vector<int>& father) {
    return x == father[x] ? x : father[x] = find(father[x], father);
}

void join(int x, int y, vector<int>& father) {
    x = find(x, father);
    y = find(y, father);
    if (x != y) father[x] = y;
}

bool isSame(int x, int y, vector<int>& father) {
    x = find(x, father);
    y = find(y, father);
    return x == y;
}


int main() {
    int n, m, s, t;
    cin >> n >> m;

    vector<int> father(n + 1);
    init(n, father);
    
    while (m--) {
        cin >> s >> t;
        join(s, t, father);
    }

    cin >> s >> t;
    cout << (isSame(s, t, father) ? 1 : 0) << endl;


    return 0;
}