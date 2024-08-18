#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a = cost[0], b = cost[1], c = 0;
        for (int i = 2; i < cost.size(); i++) {
            c = min(a, b) + cost[i];
            a = b;
            b = c;
        }
        return min(a, b);
    }
};