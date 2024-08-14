/**
 * 题目中并不需要key有序，选择std::unordered_map 效率更高
 * 时间复杂度: O(n)
 * 空间复杂度: O(n)
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> u_map;
        for(int i = 0; i < nums.size(); i++) {
            if(u_map.find(target - nums[i]) != u_map.end()) {
                return {u_map[target - nums[i]], i};
            }
            u_map[nums[i]] = i;
        }
        return {};
    }
};