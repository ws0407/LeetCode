#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
            int mid = (left + right) / 2;
            long long sqrt = (long long) mid * mid;
            if (sqrt > x) {
                right = mid - 1;
            } else if (sqrt < x) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        return right;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(2147395599) << endl;
    return 0;
}