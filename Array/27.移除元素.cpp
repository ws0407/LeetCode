#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (nums[right] == val) {
                right--;
            } else if (nums[left] == val) {
                nums[left] = nums[right];
                left++;
                right--;
            } else if (nums[left] != val) {
                left++;
            }
        }
        return left;
    }
};