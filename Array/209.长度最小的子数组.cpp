#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, length = nums.size();
        int sum = 0, res = INT_MAX;
        while (right < length) {
            if (sum >= target) {
                res = min(res, right - left + 1);
            }
            sum += nums[right++];
            while (sum - nums[left] >= target)
            {
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;        
    }
};

int main() {
    Solution s;
    vector<int> v({2,3,1,2,4,3});
    cout << s.minSubArrayLen(7, v);
    return 0;
}