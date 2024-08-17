#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> res;
    string path;

    bool isIP(string s) {
        if (s.size() > 3) return false;
        if (s[0] == '0' && s.size() > 1) return false;
        int num = stoi(s);
        return num <= 255 && num >= 0;
    }

    void dfs(string s, int index, int pointNum) {
        if (index >= s.size() && pointNum == 4) {
            res.push_back(path);
            return;
        }

        for (int i = 1; i <= 3; i++) {
            if (index + i > s.size()) break;
            string str = s.substr(index, i);
            if (!isIP(str)) continue;
            path += str;
            if (pointNum != 3) path += ".";
            dfs(s, index + i, pointNum + 1);
            path = path.substr(0, path.size() - (i + (pointNum == 3 ? 0 : 1)));
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0, 0);
        return res;
    }
};