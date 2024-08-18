#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        for (int i = 2; i <= n / 2 + 1; i++) {
            int multi = 1, shang = n / i, yushu = n % i;
            for (int j = 0; j < i; j++) multi *= j < i - yushu ? shang : (shang + 1);
            res = max(res, multi);
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.integerBreak(8) << endl;
    return 0;
}