#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int find(vector<int>& father, int x) {
        return x == father[x] ? x : father[x] = find(father, father[x]);
    }


    void join(vector<int>& father, int x, int y) {
        x = find(father, x);
        y = find(father, y);
        if (x == y) return;
        father[y] = x;
    }

    void init(vector<int>& father, int n) {
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
    }

    bool isSame(vector<int>& father, int x, int y) {
        x = find(father, x);
        y = find(father, y);
        return x == y;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> father(n+1);
        init(father, n+1);

        for (auto& e: edges) {
            if (isSame(father, e[0], e[1])) {
                return e;
            } else {
                join(father, e[0], e[1]);
            }
        }
        return {};
    }
};