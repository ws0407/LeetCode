#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = 0;
        for (int num: nums) {
            sum += num;
            if (sum > res) res = sum;
            if (sum < 0) sum = 0;
        }
        return res;
    }
};

int main() {
    vector<int> nums{5,4,-1,7,8};
    cout << Solution().maxSubArray(nums) << endl;

    return 0;
}