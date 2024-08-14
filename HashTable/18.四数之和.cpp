#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int first = 0; first+3 < nums.size(); first++) {
			if (nums[first] > target && nums[first] >= 0) break;
            for (int second = first + 1; second+2 < nums.size(); second++) {
				if (nums[first] + nums[second] > target && nums[first] + nums[second] > 0) break;
                if ((first > 0 && nums[first] == nums[first-1]) || (second > first+1 && nums[second] == nums[second-1])){
                    continue;
                }
                int left = second + 1, right = nums.size() - 1;
                while (left < right) {
                    int sums = nums[first] + nums[second] + nums[left] + nums[right];
                    if (sums == target) {
                        while (left < right && nums[left] == nums[left+1]) left++;
                        while (left < right && nums[right] == nums[right-1]) right--;
                        res.push_back({nums[first], nums[second], nums[left++], nums[right--]});
                    } else if (sums < 0) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};


int main() {

    vector<int> v = {0};
    Solution s;
    vector<vector<int>> vv = s.fourSum(v, 0);
    for (auto it = vv.begin(); it != vv.end(); it++) {
        for (auto itt = it->begin(); itt != it->end(); itt++) {
            cout << *itt << " ";
        }
        cout << endl;
    }
    return 0;
}