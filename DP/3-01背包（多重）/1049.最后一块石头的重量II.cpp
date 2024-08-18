#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < stones.size(); i++)
            for (int j = target; j >= stones[i]; j--)
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        return sum - dp[target] * 2;
    }

    int lastStoneWeightII_sort(vector<int>& stones) {
        multiset<int> s(stones.begin(), stones.end());
        while(s.size() > 1) {
            int s1 = *s.rbegin();
            s.erase(--s.end());
            int s2 = *s.rbegin();
            s.erase(--s.end());
            if(s1 != s2) {
                s.insert(s1 - s2);
            }
        }
        return s.empty() ? 0 : *s.rbegin();
    }
};

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    Solution s;
    cout << s.lastStoneWeightII(stones) << endl;
    cout << s.lastStoneWeightII_sort(stones) << endl;
    return 0;
}