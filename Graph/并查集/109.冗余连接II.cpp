/**有向图删除一个节点变成有向树 */
#include <iostream>
#include <vector>

using namespace std;

// 并查集方法
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
    int n, s, t;
    cin >> n;
    vector<int> tree(n + 1, 0);  // 入度都是1
    vector<int> father(n + 1, 0);
    init(n, father);
    int idx_2 = 0, node_2 = 0; // 入度为2的节点和另一个节点

    int idx = 0, node = 0;
    while (n--) {
        cin >> s >> t;
        if (!tree[t]) {
            tree[t] = s;
            if (!idx) {
                if (isSame(s, t, father)){
                    idx = t, node = s;  
                } else join(s, t, father);
            }
        }
        else {
            idx_2 = t;
            node_2 = s;
        }
    }
    if (!idx_2) cout << node << " " << idx;
    else cout << (idx ? tree[idx_2] : node_2) << " " << idx_2;

    return 0;
}