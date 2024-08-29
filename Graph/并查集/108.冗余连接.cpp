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
    int n, s, t;
    cin >> n;
    vector<int> father(n + 1, 0);
    init(n, father);

    while (n--) {
        cin >> s >> t;
        if (!isSame(s, t, father)) join(s, t, father);
        else {
            cout << s << " " << t << endl;
            return 0;
        }
    }

    return 0;
}