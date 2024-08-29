#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, mid;
        stack<int> st;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                mid = height[st.top()];
                st.pop();
                if (!st.empty()) sum += (min(height[st.top()], height[i]) - mid) * (i - st.top() - 1);
            }
            st.push(i);
        }
        return sum;
    }
};