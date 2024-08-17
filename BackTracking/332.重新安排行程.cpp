#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <map>
using namespace std;


class Solution {
public:
    vector<string> res;
    unordered_map<string, map<string, int>> targets;
    int ticketNum;

    bool dfs() {
        if (res.size() == ticketNum + 1) return true;
        for (auto& it: targets[res.back()]) {
            if (it.second > 0) {
                res.push_back(it.first);
                it.second--;
                if (dfs()) return true;
                res.pop_back();
                it.second++;
            }
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ticketNum = tickets.size();
        for (auto& it: tickets) {
            targets[it[0]][it[1]]++;
        }
        res.push_back("JFK");
        dfs();
        return res;
    }
};