#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 1;
        int end = intervals[0][1];
        for (vector<int> v: intervals) {
            if (end <= v[0]) {
                end = v[1];
                cnt++;
            }
        }
        return intervals.size() - cnt;
    }
};