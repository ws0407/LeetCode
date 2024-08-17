#include <iostream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    // 定义优先队列
    class myCmp {
    public:
        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 统计词频
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }
        // 定义优先队列
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCmp> pq;

        for (auto it = m.begin(); it != m.end(); it++) {
            pq.push({it->first, it->second});
            if (pq.size() > k) pq.pop();
        }
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 1, 1, 2, 2, 3, 3, 4, 4, 4};

    vector<int> res = s.topKFrequent(nums, 2);

    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}