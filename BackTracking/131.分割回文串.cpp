#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    bool isPalindrome(string &s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) if (s[i] != s[j]) return false;
        return true;
    }

    void backtracking(string& s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isPalindrome(s, startIndex, i)) {
                path.push_back(s.substr(startIndex, i - startIndex + 1));
                backtracking(s, i + 1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtracking(s, 0);
        return res;
    }
};