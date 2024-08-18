#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < step) step--;
            else step = nums[i];
            if (!step) return false;
        }
        return true;
    }
};