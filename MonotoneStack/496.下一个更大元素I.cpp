#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        stack<int> st;
        for (int num: nums2) {
            while (!st.empty() && num > st.top()) {
                um[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        while (!st.empty()) {
            um[st.top()] = -1;
            st.pop();
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++) res[i] = um[nums1[i]];
        return res;
    }
};