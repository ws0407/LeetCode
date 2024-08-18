#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int max_left = INT_MIN, left = 0, index = 0;
        for (int i = 0; i < gas.size(); i++) {
            left += (gas[i] - cost[i]);
            if (left < 0) {
                left = 0;
                index = i + 1;
                continue;
            }
        }
        for (int i = 0; i < index; i++) {
            left += (gas[i] - cost[i]);
            if (left < 0) return -1;
        }
        return index;
    }
};