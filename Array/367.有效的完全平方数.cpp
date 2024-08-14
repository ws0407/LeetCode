#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0, right = num;
        while (left <= right) {
            int mid = (left + right) / 2;
            long long square = (long long) mid * mid;
            if (square > num) {
                right = mid - 1;
            } else if (square < num) {
                left = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isPerfectSquare(12) << endl;
    return 0;
}