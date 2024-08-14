#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return res;
            if (i > 0 && nums[i] == nums[i - 1]) continue;  // i > 0，否则
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sums = nums[i] + nums[left] + nums[right];
                if (sums == 0) {
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    res.push_back({nums[i], nums[left++], nums[right--]});
                } else if (sums < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;    
    }
};


int main() {

    vector<int> v = {-2,-1,1,2};
    Solution s;
    vector<vector<int>> vv = s.threeSum(v);
    for (auto it = vv.begin(); it != vv.end(); it++) {
        for (auto itt = it->begin(); itt != it->end(); itt++) {
            cout << *itt << " ";
        }
        cout << endl;
    }
    return 0;
}