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

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> father(n+1);
        init(father, n+1);

        vector<int> inDegree(n+1);
        int specialNode = -1;
        vector<vector<int>> sepcialEdge;
        for (auto& e: edges) {
            inDegree[e[1]]++;
            if (inDegree[e[1]] > 1)
                specialNode = e[1];
        }
        for (auto& e: edges) {
            if (e[1] == specialNode) {
                sepcialEdge.push_back({e[0], e[1]});
            }
        }

        for (auto& e: edges) {
            if (e[0] == sepcialEdge[0][0] && e[1] == sepcialEdge[0][1]) {
                continue;
            }
            if (isSame(father, e[0], e[1])) {
                return sepcialEdge[1];
            } else {
                join(father, e[0], e[1]);
            }
        }
        return sepcialEdge[0];
    }
};