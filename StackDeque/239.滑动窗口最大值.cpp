#include <iostream>
#include <deque>
#include <vector>

using namespace std;


class Solution {
private:
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> q;
        void push(int x) {
            while (!q.empty() && q.back() < x)
            {
                q.pop_back();
            }
            q.push_back(x);
        }

        void pop(int x) {
            if (!q.empty() && q.front() == x)
            {
                q.pop_front();
            }
        }

        int front() {
            return q.front();
        }

    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue q;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            if (i >= k - 1) {
                res.push_back(q.front());
                q.pop(nums[i - k + 1]);
            }
        }
        return res;
    }
};