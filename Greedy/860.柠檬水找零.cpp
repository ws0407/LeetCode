#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> v(3, 0);
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                v[0]++;
            } else if (bills[i] == 10) {
                if (v[0] == 0) {
                    return false;
                }
                v[0]--;
                v[1]++;
            } else if (bills[i] == 20) {
                if (v[0] > 0 && v[1] > 0) {
                    v[0]--;
                    v[1]--;
                } else if (v[0] > 2) {
                    v[0] -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};