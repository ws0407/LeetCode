#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;
        int hash[1005] = {0};
        for (int num: nums1) hash[num] = 1;

        for (int num: nums2) {
            if (hash[num] == 1) {
                res.push_back(num);
                hash[num] = 0;
            }
        }

        return res;
    }
};