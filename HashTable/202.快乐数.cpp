#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> u_set;
        while (1)
        {
            int s = getSum(n);
            if (s == 1) return true;
            if (u_set.find(s) != u_set.end()) return false;
            u_set.insert(s);
            n = s;
        }
    }
};